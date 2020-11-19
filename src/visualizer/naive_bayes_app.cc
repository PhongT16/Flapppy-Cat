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
    : sprite_(glm::vec2(kWindowSize / 2, 400.5), glm::vec2(0,1), 8){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  counter = 0;
  /*ci::gl::Texture myImage;
  myImage = gl::Texture( loadImage( loadResource( "data/background.jpeg" ) ) );
  gl::draw( myImage, getWindowBounds());*/
}

void NaiveBayesApp::draw() {
  ci::Color8u background_color(255, 246, 148);  // light yellow
  ci::gl::clear(background_color);
  if (start_game_) {
    if (counter == 400) {
      srand (time(NULL));
      int height = rand() % 475 + 200;

      Pipe * pipe = new Pipe(height);
      pipe_list_.push_back(pipe);
      visited.push_back(false);

      counter = 0;
    }
    for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
      (*it)->Draw();
    }

   /* if (!pipe_list_.empty()) {
      for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
        if (sprite_.HasPassedPipe(*(*it))) {
          std::cout << "passed" << std::endl;
          score++;
        }
      }
    }*/
    for (size_t i = 0; i < pipe_list_.size(); i++) {
      if (!visited.at(i)) {
        sprite_.SetPipe(*pipe_list_.at(i));
      }
    }

    for (size_t i = 0; i < pipe_list_.size(); i++) {


      if (!visited.at(i) && sprite_.HasPassedPipe(*pipe_list_.at(i))) {
        visited.at(i) = true;
        score++;
      }
    }
    counter++;
    ci::gl::drawStringCentered(std::to_string(score),
        glm::vec2(kWindowSize / 2, 200), ci::Color("black"));

    // Check Collision
    /*for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
      sprite_.CheckPipeCollision(*(*it));
    }*/

    //pipe_.Draw();
    //sprite_.SetPipe(pipe_);
    if (!sprite_.GetGame()) {
      sprite_.Draw();
    } else {
      sprite_.Draw();
      ci::gl::drawStringCentered(
          "GAME OVER",
          glm::vec2(kWindowSize / 2, kWindowSize / 2), ci::Color("black"));
    }

  } else {
    ci::gl::drawStringCentered(
        "PRESS ENTER TO START GAME",
        glm::vec2(kWindowSize / 2, kWindowSize / 2), ci::Color("black"));
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
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_SPACE:
      // ask your classifier to classify the image that's currently drawn on the
      // sketchpad and update current_prediction_
      sprite_.MoveUp();
      break;

    case ci::app::KeyEvent::KEY_RETURN:
      //sketchpad_.Clear();
      start_game_ = true;
      break;
  }
}
NaiveBayesApp::~NaiveBayesApp() {
  for (size_t i = 0; i < pipe_list_.size(); i++) {
    Pipe * temp = pipe_list_.at(i);
    delete temp;
    pipe_list_.at(i) = NULL;
    temp = NULL;
  }
}

}  // namespace visualizer

}  // namespace naivebayes
