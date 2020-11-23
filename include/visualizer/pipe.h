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
  void Draw();

  /**
   * Updates the location of the pipe
   */
  void UpdateLocation();

  double GetPositionLeftSide() const ;

  double GetPositionRightSide()const ;

  double GetTopPipeBorder() const;

  double GetBottomPipeBorder() const;

private:
  //int height_;
  //int width_;
  /*double left_border_;
  double right_border_;
  double bottom_border_;
  double top_border_;*/
  double x = 0;
  double left_side_ = 875.0;
  double right_side_ = 1075; // 905
  double height_;
};
}
}

