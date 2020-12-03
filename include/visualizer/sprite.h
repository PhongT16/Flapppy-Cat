//
// Created by Phong Tran on 11/18/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "visualizer/pipe.h"

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
   * Checks whether there is pipe or border collision
   * @param position The new position of the sprite
   */
  void CollisionDetection();

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

  /**
   * Whether the game has ended
   * @return GameEnd
   */
   bool GetGame();

   /**
    * Set the current pipe
    */
    void SetPipe(Pipe & pipe);


    /**
     * Checks if the pipe has passed a pipe
     * @param pipe
     * @return Whether the sprite has just passed a pipe
     */

    bool HasPassedPipe(const Pipe & pipe);

    /**
     * Resets the game state of the sprite object
     */

    void ResetGame();

    /**
     * Calculates the relative lerp value for any up movement
     * @return The Relative Lerp Vector
     */

    glm::vec2 RelativeLerpUp();




private:
  // The current position of the Sprite
  glm::vec2 position_;

  // The current velocity of the Sprite
  glm::vec2 velocity_;

  // The Radius of the object
  const int kRadius;

  bool GameEnd = false;


  Pipe * current_pipe_;

  glm::vec2 next_position_;

  glm::vec2 lerp_;

  bool move_ = false;

//
// int score_ = 0;

};


}
}


