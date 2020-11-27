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
  ci::gl::TextureRef  mTexture = ci::gl::Texture::create( ci::loadImage( "/Users/phongtran/Desktop/pic2.png" ) ); // /Users/phongtran/Desktop/background.jpeg3
  if (game) {

    ci::gl::draw( mTexture, ci::Rectf(left_side_, 0, right_side_, height_) );
    ci::gl::draw( mTexture, ci::Rectf(left_side_, height_ + pipe_distance_, right_side_, 650) );

  } else {
    UpdateLocation();
    ci::gl::draw( mTexture, ci::Rectf(left_side_, 0, right_side_, height_) );
    ci::gl::draw( mTexture, ci::Rectf(left_side_, height_ + pipe_distance_, right_side_, 650) );
  }
}

void Pipe::UpdateLocation() {
  left_side_ -= speed;
  right_side_ -= speed;

}

double Pipe::GetPositionRightSide() const { return right_side_; }
double Pipe::GetPositionLeftSide() const { return left_side_; }
double Pipe::GetTopPipeBorder() const { return height_; }
double Pipe::GetBottomPipeBorder() const { return height_ + pipe_distance_; }
void Pipe::SetSpeed(int value) {
  speed = value;
}

}
}

