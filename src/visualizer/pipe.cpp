//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/pipe.h"
#include <cinder/gl/gl.h>

#include "iostream"

namespace naivebayes {

namespace visualizer {

Pipe::Pipe(double height) : height_(height) {}

void Pipe::Draw(bool game) {
  //std::cout << "drawing" << std::endl;
  if (game) {
    ci::gl::color(1, 1, 1); // set color to white
    ci::gl::drawSolidRect(ci::Rectf(left_side_, 0, right_side_, height_));

    ci::gl::color(1, 1, 1); // set color to white
    ci::gl::drawSolidRect(ci::Rectf(left_side_, height_ + pipe_distance_, right_side_, 650));
  } else {
    UpdateLocation();
    ci::gl::color(1, 1, 1); // set color to white
    ci::gl::drawSolidRect(ci::Rectf(left_side_, 0, right_side_, height_));

    ci::gl::color(1, 1, 1); // set color to white
    ci::gl::drawSolidRect(ci::Rectf(left_side_, height_ + pipe_distance_, right_side_, 650));
  }
}

void Pipe::UpdateLocation() {
  left_side_ -= 1;
  right_side_ -= 1;

}

double Pipe::GetPositionRightSide() const { return right_side_; }
double Pipe::GetPositionLeftSide() const { return left_side_; }
double Pipe::GetTopPipeBorder() const { return height_; }
double Pipe::GetBottomPipeBorder() const { return height_ + pipe_distance_; }

}
}

