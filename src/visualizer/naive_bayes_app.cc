#include <visualizer/naive_bayes_app.h>
#include <iostream>

namespace naivebayes {

namespace visualizer {

NaiveBayesApp::NaiveBayesApp()
    : sprite_(glm::vec2(kWindowSize / 2, 400.5), glm::vec2(0,1), 8){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void NaiveBayesApp::draw() {
  ci::Color8u background_color(255, 246, 148);  // light yellow
  ci::gl::clear(background_color);

  pipe_.Draw();
  if (!sprite_.GetGame()) {
    sprite_.Draw();
  } else {
    sprite_.Draw();
    ci::gl::drawStringCentered(
        "GAME OVER",
        glm::vec2(kWindowSize / 2, kWindowSize / 2), ci::Color("black"));
  }


  //sketchpad_.Draw();

  /*ci::gl::drawStringCentered(
      "Press Delete to clear the sketchpad. Press Enter to make a prediction.",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));

  ci::gl::drawStringCentered(
      "Prediction: " + std::to_string(current_prediction_),
      glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("blue"));*/
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

    case ci::app::KeyEvent::KEY_DELETE:
      //sketchpad_.Clear();
      break;
  }
}

}  // namespace visualizer

}  // namespace naivebayes
