#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pipe.h"
#include "sketchpad.h"
#include "sprite.h"
//#import <cinder/gl/Texture.h>
#include <cinder/gl/gl.h>
#include <vector>
namespace game {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class JetpackCat : public ci::app::App {
 public:
  JetpackCat();

  void draw() override;
  void setup() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;
  ~JetpackCat();

  /**
   * Resets the member variables of this object except for high_score_
   */
  void replay();

  /**
   * Helper function that deletes the pipe_lists_ vector
   */
  void clear();

  /**
   * Deletes pipes that have gone out of frame
   * Helps free up heap memory and relieves with lag
   */

  void DeletePipe();

  // provided that you can see the entire UI on your screen.
  const double kWindowSize = 650;

  Sprite & GetSprite();

 private:
  // The sprite
  Sprite sprite_;

  // A vector of spawned pipes
  std::vector<Pipe *> pipe_list_;

  // A count of when a new pipe gets spawned
  int pipe_spawn_timer;

  // Keeps track of whether the game has start
  bool start_game_ = false;

  // The score per game
  int score_ = 0;

  // A vector keeping track of passed pipes
  std::vector<bool> visited_;

  // Whether the game has ended
  bool Game_End_ = false;

  // The high score since the game has been played
  int high_score_ = 0;


  cinder::gl::TextureRef mTextTexture;
  ci::Font mFont;

  // Texture containg the background picture
  ci::gl::TextureRef mTexture;



};

}  // namespace visualizer

}  // namespace naivebayes
