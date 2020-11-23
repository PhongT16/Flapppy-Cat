#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pipe.h"
#include "sketchpad.h"
#include "sprite.h"
//#import <cinder/gl/Texture.h>
#include <vector>
namespace naivebayes {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class NaiveBayesApp : public ci::app::App {
 public:
  NaiveBayesApp();

  void draw() override;
  void setup() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  // TODO: Delete this comment. Feel free to play around with these variables
  // provided that you can see the entire UI on your screen.
  const double kWindowSize = 875;
  const double kMargin = 100;
  const size_t kImageDimension = 28;
  ~NaiveBayesApp();

 private:
  //Sketchpad sketchpad_;
//  int current_prediction_ = -1;
  Sprite sprite_;
  //Pipe pipe_;
  std::vector<Pipe *> pipe_list_;
  int counter;
  bool start_game_ = false;
  int score = 0;
  std::vector<bool> visited;
  //int pipe_idx_;
  //ci::gl::Texture texture;
};

}  // namespace visualizer

}  // namespace naivebayes
