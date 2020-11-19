//
// Created by Phong Tran on 11/18/20.
//
#pragma once
#include "cinder/gl/gl.h"

namespace naivebayes {

namespace visualizer {

class Sprite {
public:
  /**
   * Custom Constructor for Sprite
   * @param position The initial position of the Sprite
   * @param velocity The initial velocity of the Sprite
   */
  Sprite(glm::vec2 position, glm::vec2 velocity, int radius);

  /**
   * Updates the location of the Sprite
   * @param position The new position of the sprite
   */
  void UpdatePosition();

  /**
   * Retrieves the current position of the sprite
   * @return The current position (position_) of the sprite
   */
  glm::vec2 GetPosition();

  /**
   * Updates the velocity of the Sprite
   * @param velocity The new velocity of the sprite
   */
  void UpdateVelocity(glm::vec2 velocity);

  /**
   * Retrieves the current velocity of the sprite
   * @return The current velocity (velocity_) of the sprite
   */
  glm::vec2 GetVelocity();

  /**
   * Draws the Sprite object
   */
  void Draw();

  /**
   * Moves the Sprite to the left
   */
  void MoveLeft();

  /**
   * Moves the Sprite to the right
   */
  void MoveRight();

  /**
   * Moves the Sprite up
   */
  void MoveUp();

  /**
   * Drops the Sprite
   */

  void Drop();

  /**
   * Checks for collisions with the walls
   * @return whether the sprite has hit the border
   */
   bool CheckBorderCollision();

   /**
    * Checks for collisions with the pipes
    * @return whether the sprite has hit the pipe
    */
   bool CheckPipeCollision();

   bool GetGame();



private:
  // The current position of the Sprite
  glm::vec2 position_;

  // The current velocity of the Sprite
  glm::vec2 velocity_;

  // The Radius of the object
  const int kRadius;

  bool GameEnd = false;

};


}
}


