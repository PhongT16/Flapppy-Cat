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
    : sprite_(glm::vec2(kWindowSize / 2 + 0.5, 400.5), glm::vec2(0,1), 10){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  counter = 0;

  //gl::Texture texture = loadImage("data/background.jpeg");
  //gl::draw(texture);
}

void NaiveBayesApp::setup() {
  mText = "Here is some text that is larger than can fit naturally inside of 100 pixels.\nHere are some unicode code points: \303\251\303\241\303\250\303\240\303\247";
  mFont = Font( "Times New Roman", 30 );
  mTexture = gl::Texture::create( loadImage( "/Users/phongtran/Desktop/siebel.png" ) ); // /Users/phongtran/Desktop/background.jpeg3
  //mTexture = gl::Texture::create( loadImage( "/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/background.jpeg" ) ); // /Users/phongtran/Desktop/background.jpeg3
  std::cout << "value: " << getWindowBounds() << std::endl;
/*#if defined( CINDER_COCOA )
  mFont = Font( "Times New Roman", 30 );
#else
  mFont = Font( "Times New Roman", 24 );
#endif
  mSize = vec2( 200, 200 );*/

}

void NaiveBayesApp::draw() {


  //gl::Texture2d texture = loadImage("data/background.jpeg");
  //ci::Color8u background_color(255, 246, 148);  // light yellow


  ci::gl::clear();

  //gl::enableAlphaBlending();

  if( mTexture ) {
    gl::color(Color::white());
    Rectf destRect = Rectf( mTexture->getBounds() ).getCenteredFit( getWindowBounds(), true ).scaledCentered( 1.5f );
    gl::draw( mTexture, destRect );
  }



  if (start_game_ && !sprite_.GetGame()) {
    // Spawn a new pipe every 300 hundred pixels
    DeletePipe();

    if (counter == 300) {
      srand (time(NULL));
      int height = rand() % 400 + 100;
      Pipe * pipe = new Pipe(height);
      pipe_list_.push_back(pipe);
      visited.push_back(false);
      counter = 0;
      std::cout << "CREATED" << std::endl;

    }

    for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
      if (*it != nullptr) {
        (*it)->Draw(false);
      }
      //(*it)->Draw(false);
    }

    for (size_t i = 0; i < pipe_list_.size(); i++) {
      if (pipe_list_.at(i) != nullptr) {
        if (pipe_list_.size() == 1) {
          sprite_.SetPipe(*pipe_list_.at(i));
        } else if (!visited.at(i) && sprite_.HasPassedPipe(*pipe_list_.at(i))) {
          std::cout << "PASSED PIPE" << std::endl;
          sprite_.SetPipe(*pipe_list_.at(i + 1));
          visited.at(i) = true;
          score++;
          break;
        }
      }
      /*if (pipe_list_.size() == 1) {
        sprite_.SetPipe(*pipe_list_.at(i));
      } else if (!visited.at(i) && sprite_.HasPassedPipe(*pipe_list_.at(i))) {
        std::cout << "PASSED PIPE" << std::endl;
        sprite_.SetPipe(*pipe_list_.at(i + 1));
        visited.at(i) = true;
        score++;
        break;
      }*/
    }
  counter++;

    TextBox tbox = TextBox().alignment( TextBox::CENTER ).font( mFont ).size( ivec2( 50 , 50) ).text(std::to_string(score));
    tbox.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    mTextTexture = gl::Texture2d::create( tbox.render() );
    if( mTextTexture )
      gl::draw( mTextTexture, glm::vec2(kWindowSize / 2 - 25, 100) );


    sprite_.Draw();

  } else if (sprite_.GetGame()) {
    Game_End_ = true;
    sprite_.Draw();
    for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
      if (*it != nullptr) {
        (*it)->Draw(true);
      }
      //(*it)->Draw(true);
    }

    counter++;

    TextBox tbox = TextBox().alignment( TextBox::CENTER ).font( mFont ).size( ivec2( 200 , 50) ).text("GAME OVER");
    tbox.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( tbox.render() ), glm::vec2(kWindowSize / 2 - 100, kWindowSize / 2) );

    TextBox tbox2 = TextBox().alignment( TextBox::CENTER ).font( mFont ).size( ivec2( 200 , 50) ).text("Score: " + std::to_string(score));
    tbox2.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( tbox2.render() ), glm::vec2(kWindowSize / 2 - 100, kWindowSize / 2 + 50) );

    highcore_ = score;
  } else {
    TextBox tbox = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 500 , 50) ).text("PRESS ENTER TO START GAME");
    tbox.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( tbox.render() ), glm::vec2(kWindowSize / 2 - 250, kWindowSize / 2 - 150) );

    TextBox tbox2 = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 200 , 50) ).text("High Score: " + std::to_string(highcore_));
    tbox2.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( tbox2.render() ), glm::vec2(kWindowSize / 2 - 100, kWindowSize / 2 -100) );


  }
}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  //sketchpad_.HandleBrush(event.getPos());
  if (event.isLeftDown()) {
    sprite_.MoveLeft();
  } else if (event.isRightDown()) {
    sprite_.MoveRight();
  }

}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  //sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
  if (!Game_End_) {
    switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_SPACE:
      sprite_.MoveUp();
      break;

    case ci::app::KeyEvent::KEY_RETURN:
      start_game_ = true;
      break;

    }
  } else {
    switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_r:
      Game_End_ = false;
      replay();
      break;
    }
  }


}
NaiveBayesApp::~NaiveBayesApp() {
  std::cout << "In Destructor" << std::endl;
  clear();
}
void NaiveBayesApp::replay() {
  clear();
  std::cout << "size: " << pipe_list_.size() << std::endl;
  sprite_.ResetGame();
  start_game_ = false;
  counter = 0;

}
void NaiveBayesApp::clear() {
  std::cout << "In clear" << std::endl;
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
  visited.clear();
  score = 0;
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
