//
// Created by Phong Tran on 11/18/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "visualizer/pipe.h"

namespace game {

namespace visualizer {

class Sprite {
public:

  Sprite(const glm::vec2 & position, const glm::vec2 & velocity, int apothem);
  /**
   * Custom Constructor for Sprite
   * @param position The initial position of the Sprite
   * @param velocity The initial velocity of the Sprite
   */
  Sprite(const glm::vec2 & position, const glm::vec2 & velocity, int apothem, double window_size);

  /**
   * Checks whether there is pipe or border collision
   * @param position The new position of the sprite
   */
  bool CollisionDetection();

  /**
   * Draws the Sprite object
   */
  void Draw();

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
    void SetPipe(const Pipe & pipe);


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

    /**
     * Sets the position of the sprite.
     * Used for testing
     * @param position The desired position
     */

    void SetPosition(glm::vec2 position);

    /**
     * Gets the velocity_
     * Used for testing
     */

    glm::vec2  & GetVelocity();

    /**
     * Gets the position_
     * Used for testing
     */

    glm::vec2 & GetPosition();

    /**
     * Gets the lerp_
     * Used for testing
     */
     glm::vec2 GetLerp();






private:
  // The starting position of the sprite
  const glm::vec2 starting_position_;

  // The starting velocity of the sprite
  const glm::vec2 starting_velocity_;

  // The current position of the Sprite
  glm::vec2 position_;

  // The current velocity of the Sprite
  glm::vec2 velocity_;

  // The Radius of the object
  const int kApothem;

  // Whether the sprite has collided with the wall
  bool has_collided_;

  // The current pipe that the sprite is approaching
  const Pipe * current_pipe_;

  // The next position of the sprite
  glm::vec2 next_position_;

  // The lerp value
  glm::vec2 lerp_;


  bool isLerpActive = false;

  ci::gl::TextureRef up_motion_texture_;
  ci::gl::TextureRef down_motion_texture_;

  const double kWindowSize;


//
// int score_ = 0;

};


}
}


