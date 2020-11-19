//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/sprite.h"
#include <iostream>

namespace naivebayes {

namespace visualizer {

Sprite::Sprite(glm::vec2 position, glm::vec2 velocity, int radius) : position_(position), velocity_(velocity), kRadius(radius) {}

void Sprite::Draw() {
  UpdatePosition();
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidCircle(glm::vec2(position_.x, position_.y),
                           kRadius);
}


void Sprite::UpdatePosition() {
  /*if (!CheckPipeCollision()|| !CheckBorderCollision()) {
    Drop();
    //position_ += velocity_;
  } else {
    GameEnd = true;
  }*/

  if (CheckPipeCollision() || CheckBorderCollision()) {
    GameEnd = true;
  } else {
    Drop();
  }
}

glm::vec2 Sprite::GetPosition() { return position_; }

void Sprite::UpdateVelocity(glm::vec2 velocity) {
  velocity_ = velocity;
}
glm::vec2 Sprite::GetVelocity() { return velocity_; }

void Sprite::MoveLeft() {
  //position_.x -= velocity_.x;
  position_.x -= 1;
}

void Sprite::MoveRight() {
  // Considering that x increases by 1
  position_.x += 1;

}
void Sprite::Drop() {
  position_.y += 0.5;
}
void Sprite::MoveUp() {
  position_.y -= 30;
}
bool Sprite::CheckBorderCollision() {

  double top_border_y_ = 0;
  double bottom_border_y_ = 875;
  bool is_collision = false;

  if (position_.y + velocity_.y - kRadius <= top_border_y_) {
    position_.y = top_border_y_ + kRadius;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0,0);
    is_collision = true;
  } else if (position_.y + velocity_.y + kRadius >= bottom_border_y_) {
    position_.y = bottom_border_y_ - kRadius;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0,0);
    is_collision = true;
  }
  return is_collision;
}

bool Sprite::GetGame() { return GameEnd; }

bool Sprite::CheckPipeCollision() {

  double top_border_y_ = 300;
  double bottom_border_y_ = 637.5;
  bool is_collision = false;

  if (position_.y + velocity_.y - kRadius <= top_border_y_) {
    position_.y = top_border_y_ + kRadius;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0,0);
    is_collision = true;
    velocity_ = glm::vec2(0,0);
  } else if (position_.y + velocity_.y + kRadius >= bottom_border_y_) {
    position_.y = bottom_border_y_ - kRadius;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0,0);
    is_collision = true;
  }


  return is_collision;

}

}
}
