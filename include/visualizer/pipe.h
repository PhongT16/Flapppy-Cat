//
// Created by Phong Tran on 11/18/20.
//

#pragma once

namespace naivebayes {

namespace visualizer {

class Pipe {
public:

  Pipe(double height);
  /**
   * Draws the Pipe
   */
  void Draw(bool game_);

  /**
   * Updates the location of the pipe
   */
  void UpdateLocation();

  /**
   * Gets the x-coordinate of the pipe's left side
   * @return the x-coordinate of the left side of the pipe
   */

  double GetPositionLeftSide() const ;

  /**
  * Gets the x-coordinate of the pipe's right side
  * @return the x-coordinate of the right side of the pipe
  */

  double GetPositionRightSide()const ;

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

  void SetSpeed(int value);

private:
  double left_side_ = 650.0;
  double right_side_ = 750.0; // 905
  int height_;
  const int pipe_distance_ = 150;
  int speed = 1;
};
}
}

