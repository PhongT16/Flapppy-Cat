//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/pipe.h"
#include <cinder/gl/gl.h>

#include "iostream"

namespace naivebayes {

namespace visualizer {

Pipe::Pipe(double height) : height_(height) {}

void Pipe::Draw() {
  //std::cout << "drawing" << std::endl;
  UpdateLocation();

  ci::gl::color(1, 1, 1); // set color to white
  //std::cout << "875 - x: " << 875 - x << std::endl;
  //std::cout << "left_side_: " << left_side_ << std::endl;
  ci::gl::drawSolidRect(ci::Rectf(left_side_, 0, right_side_, height_));

  ci::gl::color(1, 1, 1); // set color to white
  ci::gl::drawSolidRect(ci::Rectf(left_side_, height_ + 150, right_side_, 875));


}
void Pipe::UpdateLocation() {
  x = 1;
  left_side_ -= x;
  right_side_ -= x;

}
double Pipe::GetPositionRightSide() const { return right_side_; }
double Pipe::GetPositionLeftSide() const { return left_side_; }

}
}

