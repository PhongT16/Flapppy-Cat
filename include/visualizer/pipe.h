//
// Created by Phong Tran on 11/18/20.
//

#pragma once

namespace naivebayes {

namespace visualizer {

class Pipe {
public:
  /**
   * Draws the Pipe
   */
  void Draw();

  /**
   * Updates the location of the pipe
   */
  void UpdateLocation();

private:
  //int height_;
  //int width_;
  /*double left_border_;
  double right_border_;
  double bottom_border_;
  double top_border_;*/
  double x = 0;
};
}
}

