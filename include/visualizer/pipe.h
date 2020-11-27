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

  double GetPositionLeftSide() const ;

  double GetPositionRightSide()const ;

  double GetTopPipeBorder() const;

  double GetBottomPipeBorder() const;

  void SetSpeed(int value);

private:
  double left_side_ = 650.0;
  double right_side_ = 750.0; // 905
  int height_;
  const int pipe_distance_ = 90;
  int speed = 1;
};
}
}

