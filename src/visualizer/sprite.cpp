//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/sprite.h"
#include <iostream>

namespace naivebayes {

namespace visualizer {

Sprite::Sprite(glm::vec2 position, glm::vec2 velocity, int radius) : position_(position), velocity_(velocity), kRadius(radius), current_pipe_(0) {}

void Sprite::Draw() {
  UpdatePosition();
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidCircle(glm::vec2(position_.x, position_.y),
                           kRadius);
}


void Sprite::UpdatePosition() {
  if (CheckPipeCollision() || CheckBorderCollision()) {
    std::cout << "Collision" << std::endl;
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
  //position_.y += 3;
  velocity_.y = 2;
  position_.y +=  velocity_.y;
}
void Sprite::MoveUp() {
  position_.y -= 50;
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
  //double top_border_y_ = 300;
  //double bottom_border_y_ = 637.5;
  bool is_collision = false;

  if (current_pipe_ != NULL) {

   // std::cout << "position_.x: " << position_.x << std::endl;
   // std::cout << " current_pipe_.GetPositionLeftSide(): " << current_pipe_->GetPositionLeftSide() << std::endl;


    if (position_.x >= current_pipe_->GetPositionLeftSide() && position_.y <= current_pipe_->GetTopPipeBorder()) {
      std::cout << "Collide Pipe" << std::endl;
      is_collision = true;
    } else if (position_.x >= current_pipe_->GetPositionLeftSide() && position_.y >= current_pipe_->GetBottomPipeBorder()) {
      std::cout << "Collide Pipe" << std::endl;
      is_collision = true;
    }
  }



  /*if (position_.y + velocity_.y - kRadius <= top_border_y_ && position_.x >= current_pipe_.GetPositionLeftSide()
  && position_.x <= current_pipe_.GetPositionRightSide()) {
    //std::cout << "here" << std::endl;
    position_.y = top_border_y_ + kRadius;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0,0);
    is_collision = true;
    std::cout << "top pipe" << std::endl;
  } else if (position_.y + velocity_.y + kRadius >= bottom_border_y_ && position_.x >= current_pipe_.GetPositionLeftSide()
             && position_.x <= current_pipe_.GetPositionRightSide()) {
    position_.y = bottom_border_y_ - kRadius;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0,0);
    is_collision = true;
    std::cout << "bottom pipe" << std::endl;
  }*/


  return is_collision;

}
void Sprite::SetPipe(Pipe & pipe) {
  std::cout << "Pipe memory location: " << &pipe << std::endl;

  //std::cout << pipe.GetPositionLeftSide() << std::endl;
  //std::cout << "SetPipe" << std::endl;
  current_pipe_ = &pipe;
}
bool Sprite::HasPassedPipe(const Pipe & pipe) {
  double mid = (pipe.GetPositionLeftSide() + pipe.GetPositionRightSide()) / 2;
  if (mid <= position_.x) {
    return true;
  }

  return false;
}
void Sprite::InPipe() {
  if (position_.x >= current_pipe_->GetPositionLeftSide() && position_.x <= current_pipe_->GetPositionRightSide()) {
    std::cout << "In between" << std::endl;
  }
}
int Sprite::GetScore() const { return score_; }

}
}
