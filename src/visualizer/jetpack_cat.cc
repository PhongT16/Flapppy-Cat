#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <string>
#include <visualizer/jetpack_cat.h>
#include <iostream>

namespace game {

namespace visualizer {
using namespace ci;
using namespace ci::app;

JetpackCat::JetpackCat()
    : sprite_(glm::vec2(kWindowSize / 2 + 0.5, 400.5), glm::vec2(0,3), 25, kWindowSize){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  pipe_spawn_timer = 0;

}

void JetpackCat::setup() {
  mFont = Font( "Times New Roman", 30 );
  mTexture = gl::Texture::create( loadImage( "data/backgroundfinal.png"));

}

void JetpackCat::draw() {

  // Clears the canvas and draws the background
  ci::gl::clear();

  if( mTexture ) {
    gl::color(Color::white());
    Rectf destRect = Rectf( mTexture->getBounds() ).getCenteredFit( getWindowBounds(), true ).scaledCentered( 1.0f );
    gl::draw( mTexture, destRect );
  }

  // Only start the game if start_game is true and sprite collision isn't detected

  if (start_game_ && !sprite_.CollisionDetection()) {
    // Draws the sprite
    sprite_.Draw();

    // Checks for out of frame pipes and delete them
    DeletePipe();

    // Spawn a new pipe every 100 hundred pixels
    if (pipe_spawn_timer == 100) {
      srand (time(NULL));
      int height = rand() % 300 + 100;
      Pipe * pipe = new Pipe(height, 3);
      pipe_list_.push_back(pipe);
      visited_.push_back(false);
      pipe_spawn_timer = 0;
    }

    // Draws the pipes
    for (auto it : pipe_list_) {
      if (it != nullptr)
        (it)->Draw(false);
    }

    // Sets the current pipe for sprite_ to operate on
    for (size_t i = 0; i < pipe_list_.size(); i++) {
      if (pipe_list_.at(i) != nullptr) {
        if (pipe_list_.size() == 1) {
          sprite_.SetPipe(*pipe_list_.at(i));
        } else if (!visited_.at(i) && sprite_.HasPassedPipe(*pipe_list_.at(i))) {
          sprite_.SetPipe(*pipe_list_.at(i + 1));
          visited_.at(i) = true;
          score_++;
          break;
        }
      }
    }

    // Increment the tick for pipe spawn
    pipe_spawn_timer++;

    // Draws the score box
    TextBox score_box = TextBox().alignment( TextBox::CENTER ).font( mFont ).size( ivec2( 50 , 50) ).text(std::to_string(score_));
    score_box.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( score_box.render() ), glm::vec2(kWindowSize / 2 - 25, 100));

  } else if (sprite_.CollisionDetection()) { // If collision is detected, then end game
    Game_End_ = true;
    start_game_ = false;
    sprite_.Draw();

    // Stops drawing the pipes
    for (auto it : pipe_list_) {
      if (it != nullptr)
        (it)->Draw(true);
    }

    // Record the high score
    if (high_score_ == 0 || high_score_ < score_)
      high_score_ = score_;

    // Reset the game elements
    replay();

  }

  // If game hasn't started or player just lost, then this screen will render
  if (!start_game_){

    ci::gl::TextureRef  mTexture2 = ci::gl::Texture::create( ci::loadImage( "data/pokemon.png" ) );
    ci::gl::draw( mTexture2, ci::Rectf(mTexture2->getBounds()).getCenteredFit( getWindowBounds(), true ).scaledCentered( 0.7f ));

    TextBox instruction_box = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 500 , 50) ).text("PRESS ENTER TO START GAME");
    instruction_box.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( instruction_box.render() ), glm::vec2(kWindowSize / 2 - 250, kWindowSize / 2 - 35) );

    TextBox score_box = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 200 , 50) ).text("Score: " + std::to_string(score_));
    score_box.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( score_box
    .render() ), glm::vec2(kWindowSize / 2 - 100, kWindowSize / 2 - 5 ) );

    TextBox high_score_box = TextBox().alignment( TextBox::CENTER ).font( Font( "Times New Roman", 17 ) ).size( ivec2( 200 , 50) ).text("High Score: " + std::to_string(high_score_));
    high_score_box.setColor( Color( 0.0f, 0.0f, 0.0f ) );
    gl::draw( gl::Texture2d::create( high_score_box.render() ), glm::vec2(kWindowSize / 2 - 100, kWindowSize / 2  + 25) );
  }

}

JetpackCat::~JetpackCat() {
  clear();
}

void JetpackCat::replay() {
  clear();
  sprite_.ResetGame();
  start_game_ = false;
  pipe_spawn_timer = 0;

}

void JetpackCat::clear() {
  for (size_t i = 0; i < pipe_list_.size(); i++) {
    if (pipe_list_.at(i) == nullptr) {
      continue;
    }
    Pipe * temp = pipe_list_.at(i);
    delete temp;
    pipe_list_.at(i) = nullptr;
  }
  pipe_list_.clear();
  visited_.clear();
}
void JetpackCat::DeletePipe() {

  for (unsigned i = 0; i < pipe_list_.size(); i++) {
    if (pipe_list_.at(i) !=
        nullptr && pipe_list_.at(i)->GetPositionRightSide() < 0) {
      delete pipe_list_.at(i);
      pipe_list_.at(i) = nullptr;
      break;
    }
  }
}

void JetpackCat::keyDown(ci::app::KeyEvent event) {
  if (!start_game_) {
    switch (event.getCode()) {

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


}  // namespace visualizer

}  // namespace game
