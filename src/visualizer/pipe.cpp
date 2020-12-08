//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/pipe.h"
#include <cinder/gl/gl.h>

#include "iostream"

namespace naivebayes {

namespace visualizer {

Pipe::Pipe(double height, int speed) : height_(height), speed(speed) {
  top_pipe_ = height_;
  bottom_pipe_ = height_ + pipe_distance_;
  pipe_mid_point_ = (height_ + height_ + pipe_distance_) / 2;
  target_height_ = pipe_mid_point_;
}

void Pipe::Draw(bool game) {
  ci::gl::color(ci::Color::white());
  ci::gl::TextureRef  mTexture = ci::gl::Texture::create( ci::loadImage( "/Users/phongtran/Desktop/pic2.png" ) ); // /Users/phongtran/Desktop/background.jpeg3
  if (game) {
    ci::gl::draw( mTexture, ci::Rectf(left_side_, 0, right_side_, top_pipe_) );
    ci::gl::draw( mTexture, ci::Rectf(left_side_, bottom_pipe_, right_side_, 650) );

  } else {
    UpdateLocation();
    ci::gl::draw( mTexture, ci::Rectf(left_side_, 0, right_side_, top_pipe_) );
    ci::gl::draw( mTexture, ci::Rectf(left_side_, bottom_pipe_, right_side_, 650) );
  }
}

void Pipe::UpdateLocation() {
  left_side_ -= speed;
  right_side_ -= speed;
  MovePipe();

}

double Pipe::GetPositionRightSide() const { return right_side_; }

double Pipe::GetPositionLeftSide() const { return left_side_; }

double Pipe::GetTopPipeBorder() const { return top_pipe_; }

double Pipe::GetBottomPipeBorder() const { return bottom_pipe_; }

void Pipe::MovePipe() {
  int value = 2;

  if (target_height_ == pipe_mid_point_) {
    top_pipe_ += value;
    bottom_pipe_ -= value;
  } else if (target_height_ == height_) {
    top_pipe_ -= value;
    bottom_pipe_ += value;
  }

  if (top_pipe_ >= pipe_mid_point_ && target_height_ == pipe_mid_point_) {
    target_height_ = height_;
  } else if (top_pipe_ <= height_ && target_height_ == height_) {
    target_height_ = pipe_mid_point_;
  }
}

}
}

