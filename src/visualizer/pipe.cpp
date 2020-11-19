//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/pipe.h"
#include <cinder/gl/gl.h>

#include "iostream"

namespace naivebayes {

namespace visualizer {

void Pipe::Draw() {
  UpdateLocation();
  ci::gl::color(1, 1, 1); // set color to white
  ci::gl::drawSolidRect(ci::Rectf(875 - x, 0, 905 - x, 300));

  ci::gl::color(1, 1, 1); // set color to white
  ci::gl::drawSolidRect(ci::Rectf(875 - x, 637.5, 905 - x, 875));

}
void Pipe::UpdateLocation() {
  x += 1;

}
}
}

