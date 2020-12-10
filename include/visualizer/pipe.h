//
// Created by Phong Tran on 11/18/20.
//

#pragma once
#include <string>

namespace game {

namespace visualizer {

class Pipe {
public:
  /**
   * Custom Constructor for Pipe
   * @param height The initial height of the pipe
   * @param speed The initial speed of the speed
   */
  Pipe(size_t height, size_t speed);

  /**
   * Draws the Pipe
   */
  void Draw(bool game);

  /**
   * Updates the location of the pipe
   */
  void UpdateLocation();

  /**
   * Gets the x-coordinate of the pipe's left side
   * @return the x-coordinate of the left side of the pipe
   */

  double GetPositionLeftSide() const;

  /**
   * Gets the x-coordinate of the pipe's right side
   * @return the x-coordinate of the right side of the pipe
   */

  double GetPositionRightSide() const;

  /**
   * Gets the y-coordinate of the upper half of the pipe
   * @return The y-coordinate of the upper half of the pipe
   */

  double GetTopPipeBorder() const;

  /**
   * Gets the y-coordinate of the lower half of the pipe
   * @return The y-coordinate of the lower half of the pipe
   */

  double GetBottomPipeBorder() const;

  /**
   * Retrieves the current speed of the pipe
   * @return the speed_
   */
  int GetSpeed() const;

  /**
   * Move the top pipe down and bottom pipe up until they meet at the midpoint
   * height
   */
  void MovePipe();

  /**
   * Sets the pipe's position
   * Used for testing
   * @param left_side The desired x-coordinate for the left side of the pipe
   * @param right_side The desired x-coordinate for the right side of the pipe
   */
  void SetPipePosition(double left_side, double right_side);

private:
  // The starting x-coordinate of left side of the top and bottom pipe
  double left_side_;

  // The starting x-coordinate of the right side of the top and bottom pipe
  double right_side_;

  // The starting height of the top_height_
  const size_t height_;

  // The distance between the top and bottom pipe
  const size_t pipe_distance_;

  // The speed that the pipe is moving at
  size_t speed_;

  // The y-coordinate of the bottom side of the top pipe
  double top_pipe_;

  // The y-coordinate of the top side of the bottom pipe
  double bottom_pipe_;

  // The average y-coordinate between top_pipe_ and bottom_pipe_
  double pipe_mid_point_;

  // This height switches between pipe_mid_point_ and height_.
  // It lets the pipe knows when to move up and down
  double target_height_;
};

} // namespace visualizer
} // namespace game
