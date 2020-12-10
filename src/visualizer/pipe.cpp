//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/pipe.h"
#include <cinder/gl/gl.h>

namespace game {

namespace visualizer {

Pipe::Pipe(size_t height, size_t speed)
    : left_side_(650.0), right_side_(725.0), height_(height),
      pipe_distance_(225), speed_(speed) {
  top_pipe_ = height_;
  bottom_pipe_ = height_ + pipe_distance_;
  pipe_mid_point_ = (height_ + height_ + pipe_distance_) / 2;
  target_height_ = pipe_mid_point_;
}

void Pipe::Draw(bool game) {
  ci::gl::color(ci::Color::white());
  ci::gl::TextureRef mTexture =
      ci::gl::Texture::create(ci::loadImage("data/pipe.png"));
  if (game) {
    // Draws the top pipe
    ci::gl::draw(mTexture, ci::Rectf(left_side_, 0, right_side_, top_pipe_));
    // Draws the bottom pipe
    ci::gl::draw(mTexture,
                 ci::Rectf(left_side_, bottom_pipe_, right_side_, 650));
  } else {
    UpdateLocation();
    // Draws the top pipe
    ci::gl::draw(mTexture, ci::Rectf(left_side_, 0, right_side_, top_pipe_));
    // Draws the bottom pipe
    ci::gl::draw(mTexture,
                 ci::Rectf(left_side_, bottom_pipe_, right_side_, 650));
  }
}

void Pipe::UpdateLocation() {
  // Moves the top and bottom pipe to the left by speed_
  left_side_ -= speed_;
  right_side_ -= speed_;
  MovePipe();
}

double Pipe::GetPositionRightSide() const { return right_side_; }

double Pipe::GetPositionLeftSide() const { return left_side_; }

double Pipe::GetTopPipeBorder() const { return top_pipe_; }

double Pipe::GetBottomPipeBorder() const { return bottom_pipe_; }

void Pipe::MovePipe() {
  // The speed at which the moves up and down
  size_t vertical_speed = 2;

  if (target_height_ == pipe_mid_point_) {
    top_pipe_ += vertical_speed;
    bottom_pipe_ -= vertical_speed;
  } else if (target_height_ == height_) {
    top_pipe_ -= vertical_speed;
    bottom_pipe_ += vertical_speed;
  }

  if (top_pipe_ >= pipe_mid_point_ && target_height_ == pipe_mid_point_) {
    target_height_ = height_;
  } else if (top_pipe_ <= height_ && target_height_ == height_) {
    target_height_ = pipe_mid_point_;
  }
}
int Pipe::GetSpeed() const { return speed_; }

void Pipe::SetPipePosition(double left_side, double right_side) {
  left_side_ = left_side;
  right_side_ = right_side;
}

} // namespace visualizer
} // namespace game
