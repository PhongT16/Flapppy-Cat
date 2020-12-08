#include <visualizer/naive_bayes_app.h>
#include <iostream>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <string>

namespace naivebayes {

namespace visualizer {
using namespace ci;
using namespace ci::app;

NaiveBayesApp::NaiveBayesApp()
    : sprite_(glm::vec2(kWindowSize / 2 + 0.5, 400.5), glm::vec2(0,3), 25, kWindowSize){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  pipe_spawn_timer = 0;

}

void NaiveBayesApp::setup() {
  mFont = Font( "Times New Roman", 30 );
  mTexture = gl::Texture::create( loadImage( "/Users/phongtran/Desktop/siebel.png"));

}

void NaiveBayesApp::draw() {

  ci::gl::clear();

  if( mTexture ) {
    gl::color(Color::white());
    Rectf destRect = Rectf( mTexture->getBounds() ).getCenteredFit( getWindowBounds(), true ).scaledCentered( 1.5f );
    gl::draw( mTexture, destRect );
  }

  if (start_game_ && !sprite_.CollisionDetection()) {
    sprite_.Draw();

    // Spawn a new pipe every 300 hundred pixels
    DeletePipe();
    int a = 3;
    if (pipe_spawn_timer == 100) {
      srand (time(NULL));
      int height = rand() % 400 + 100;
      Pipe * pipe = new Pipe(height, a);
      pipe_list_.push_back(pipe);
      visited_.push_back(false);
      pipe_spawn_timer = 0;
    }

    //
    for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
      if (*it != nullptr) {
        (*it)->Draw(false);
      }
    }

    for (size_t i = 0; i < pipe_list_.size(); i++) {
      if (pipe_list_.at(i) != nullptr) {
        if (pipe_list_.size() == 1) {
          sprite_.SetPipe(*pipe_list_.at(i));
        } else if (!visited_.at(i) && sprite_.HasPassedPipe(*pipe_list_.at(i))) {
          //std::cout << "PASSED PIPE" << std::endl;
          sprite_.SetPipe(*pipe_list_.at(i + 1));
          sprite_.SetPipe(*pipe_list_.at(i + 1));
          visited_.at(i) = true;
          score_++;
          break;
        }
      }
    }

    pipe_spawn_timer++;

    TextBox tbox = TextBox().alignment( TextBox::CENTER ).font( mFont ).size( ivec2( 50 , 50) ).text(std::to_string(score_));
    tbox.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    mTextTexture = gl::Texture2d::create( tbox.render() );
    if( mTextTexture )
      gl::draw( mTextTexture, glm::vec2(kWindowSize / 2 - 25, 100) );


    //sprite_.Draw();

  } else if (sprite_.CollisionDetection()) {
    Game_End_ = true;
    start_game_ = false;
    sprite_.Draw();
    for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
      if (*it != nullptr) {
        (*it)->Draw(true);
      }
    }

    if (high_score_ == 0 || high_score_ < score_) {
      high_score_ = score_;
    }
    replay();

  }
  if (!start_game_){

    ci::gl::TextureRef  mTexture2 = ci::gl::Texture::create( ci::loadImage( "/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/data/pokemon.png" ) );
    ci::gl::draw( mTexture2, ci::Rectf(mTexture2->getBounds()).getCenteredFit( getWindowBounds(), true ).scaledCentered( 0.7f ));

    TextBox tbox = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 500 , 50) ).text("PRESS ENTER TO START GAME");
    tbox.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( tbox.render() ), glm::vec2(kWindowSize / 2 - 250, kWindowSize / 2 - 35) );

    TextBox tbox3 = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 200 , 50) ).text("Score: " + std::to_string(score_));
    tbox3.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( tbox3
    .render() ), glm::vec2(kWindowSize / 2 - 100, kWindowSize / 2 - 20 ) );

    TextBox tbox2 = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 200 , 50) ).text("High Score: " + std::to_string(high_score_));
    tbox2.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( tbox2.render() ), glm::vec2(kWindowSize / 2 - 100, kWindowSize / 2 ) );
  }

}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  //sketchpad_.HandleBrush(event.getPos());

}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  //sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
  if (!start_game_) {
    switch (event.getCode()) {
    /*case ci::app::KeyEvent::KEY_SPACE:
      sprite_.MoveUp();
      break;
    */
    case ci::app::KeyEvent::KEY_RETURN:
      start_game_ = true;
      score_ = 0;
      break;

    }
  } else {
    switch (event.getCode()) {

    case ci::app::KeyEvent::KEY_SPACE:
      sprite_.MoveUp();
      break;
    }


  }
}

NaiveBayesApp::~NaiveBayesApp() {
  clear();
}

void NaiveBayesApp::replay() {
  clear();
  sprite_.ResetGame();
  start_game_ = false;
  pipe_spawn_timer = 0;

}
void NaiveBayesApp::clear() {
  for (size_t i = 0; i < pipe_list_.size(); i++) {
    if (pipe_list_.at(i) == nullptr) {
      continue;
    }
    Pipe * temp = pipe_list_.at(i);
    delete temp;
    pipe_list_.at(i) = NULL;
    temp = NULL;
  }
  pipe_list_.clear();
  visited_.clear();
  //score_ = 0;
}
void NaiveBayesApp::DeletePipe() {

  for (unsigned i = 0; i < pipe_list_.size(); i++) {
    if (pipe_list_.at(i) !=
        nullptr && pipe_list_.at(i)->GetPositionRightSide() < 0) {
      delete pipe_list_.at(i);
      pipe_list_.at(i) = nullptr;
      break;
    }
  }
}


}  // namespace visualizer

}  // namespace naivebayes
