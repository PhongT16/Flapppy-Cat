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
    : sprite_(glm::vec2(kWindowSize / 2 + 0.5, 400.5), glm::vec2(0,1), 8){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  counter = 0;

  //gl::Texture texture = loadImage("data/background.jpeg");
  //gl::draw(texture);
}

void NaiveBayesApp::setup() {
  //texture = ci::loadImage("data/background.jpeg");
  //ci::gl::Texture2dRef myImage;
  //myImage = gl::Texture2d::create(loadImage(loadResource("resources/pic.png")));
  //console() << "Path: " << getResourcePath("") << std::endl;
  //gl::draw( myImage, getWindowBounds());
  //std::cout << "here" << std::endl;
  //fs::path path = fs::path("./pic.jpg");
  //auto img = loadImage(path);
  //fs::path path = fs::path("resources/pic.jpg");
  //gl::TextureRef texture = gl::Texture::create(loadImage(path));
  //gl::Texture2dRef texture = gl::Texture2d::create( loadImage(  loadResource("pic.png"  )) );


  //gl::Texture texture = loadImage("resources/pic.png");
  //gl::draw(texture);
}

void NaiveBayesApp::draw() {


  //gl::Texture2d texture = loadImage("data/background.jpeg");
  ci::Color8u background_color(255, 246, 148);  // light yellow
  ci::gl::clear(background_color);

  //sprite_.Draw();

  if (start_game_ && !sprite_.GetGame()) {

    //std::cout << "counter: " << counter << std::endl;
    // Spawn a new pipe every 300 hundred pixels
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
      (*it)->Draw(false);
    }



    for (size_t i = 0; i < pipe_list_.size(); i++) {
      if (pipe_list_.size() == 1) {
        sprite_.SetPipe(*pipe_list_.at(i));
      } else if (!visited.at(i) && sprite_.HasPassedPipe(*pipe_list_.at(i))) {
        std::cout << "PASSED PIPE" << std::endl;
        sprite_.SetPipe(*pipe_list_.at(i + 1));
        visited.at(i) = true;
        score++;
        break;
      }
    //std::cout << "--------------------------" << std::endl;
    }

  counter++;
  ci::gl::drawStringCentered(std::to_string(score),
      glm::vec2(kWindowSize / 2, 200), ci::Color("black"));

    sprite_.Draw();

  } else if (sprite_.GetGame()) {
    Game_End_ = true;
    sprite_.Draw();
    for (auto it = pipe_list_.begin(); it != pipe_list_.end(); ++it) {
      (*it)->Draw(true);
    }

    counter++;
    ci::gl::drawStringCentered(std::to_string(score),
                               glm::vec2(kWindowSize / 2, kWindowSize / 2 + 50), ci::Color("black"));

    ci::gl::drawStringCentered(
        "GAME OVER",
        glm::vec2(kWindowSize / 2, kWindowSize / 2), ci::Color("black"));

    highcore_ = score;
  } else {
    ci::gl::drawStringCentered(
        "PRESS ENTER TO START GAME",
        glm::vec2(kWindowSize / 2, kWindowSize / 2), ci::Color("black"));

    ci::gl::drawStringCentered(std::to_string(highcore_),
                               glm::vec2(kWindowSize / 2, 200), ci::Color("black"));

  }
  std::cout << "------------------------" << std::endl;

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
    Pipe * temp = pipe_list_.at(i);
    delete temp;
    pipe_list_.at(i) = NULL;
    temp = NULL;
  }
  pipe_list_.clear();
  visited.clear();
  score = 0;
}

}  // namespace visualizer

}  // namespace naivebayes
