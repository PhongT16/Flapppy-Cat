//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/sprite.h"
#include <iostream>

namespace naivebayes {

namespace visualizer {

Sprite::Sprite(glm::vec2 position, glm::vec2 velocity, int radius) : position_(position), velocity_(velocity), kRadius(radius), current_pipe_(0), next_position_(position) {}

void Sprite::Draw() {
  UpdatePosition();
  //ci::gl::color(ci::Color("red"));
 // ci::gl::drawSolidCircle(glm::vec2(position_.x, position_.y),
   //                       kRadius);


  if (position_.y > next_position_.y && move_) {
    ci::gl::color(ci::Color("red"));
    position_.y -= lerp_.y;
    ci::gl::drawSolidCircle(glm::vec2(position_.x, position_.y),kRadius);
    std::cout << "first condition" << std::endl;

  } else {
    move_ = false;
    std::cout << "second condition" << std::endl;
    Drop();
    ci::gl::color(ci::Color("red"));
    ci::gl::drawSolidCircle(glm::vec2(position_.x, position_.y),kRadius);
  }
  //std::cout << "Expected Position: " << next_position_ << std::endl;
  //std::cout << "Final Position: " << position_ << std::endl;

}


void Sprite::UpdatePosition() {
  if (CheckPipeCollision() || CheckBorderCollision()) {
    GameEnd = true;
  } /*else {
    Drop();
  }*/

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
  velocity_.y = 3;
  position_.y +=  velocity_.y;
}
void Sprite::MoveUp() {
  Update();
  move_ = true;
  //position_.y -= 60;
  //position_.y = temp.y;
}
bool Sprite::CheckBorderCollision() {

  double top_border_y_ = 0;
  double bottom_border_y_ = 650
      ;
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
  bool is_collision = false;

  if (current_pipe_ != NULL) {
    // Checks for side collision with pipe
    if (position_.x < current_pipe_->GetPositionLeftSide() && position_.x + kRadius >= current_pipe_->GetPositionLeftSide() && position_.y < current_pipe_->GetTopPipeBorder()) {
      position_.x = current_pipe_->GetPositionLeftSide() - kRadius;
      is_collision = true;

      std::cout << "COLLISION" << std::endl;
    } else if (position_.x < current_pipe_->GetPositionLeftSide() && position_.x + kRadius >= current_pipe_->GetPositionLeftSide() && position_.y >= current_pipe_->GetBottomPipeBorder()) {
      position_.x = current_pipe_->GetPositionLeftSide() - kRadius;
      is_collision = true;
    }

    // Checks for internal collision with pipe
    if (position_.x >= current_pipe_->GetPositionLeftSide() && position_.x <= current_pipe_->GetPositionRightSide()) {
      if (position_.y - kRadius <= current_pipe_->GetTopPipeBorder()) {
        position_.y = current_pipe_->GetTopPipeBorder() + kRadius;
        is_collision = true;
      } else if (position_.y + kRadius >= current_pipe_->GetBottomPipeBorder()) {
        position_.y = current_pipe_->GetBottomPipeBorder() - kRadius;
        is_collision = true;
      }
    }


  }
  return is_collision;

}
void Sprite::SetPipe(Pipe & pipe) {
  current_pipe_ = &pipe;
}
bool Sprite::HasPassedPipe(const Pipe & pipe) {
  //double mid = ((pipe.GetPositionLeftSide() + pipe.GetPositionRightSide()) / 2) + 100;
  if ( pipe.GetPositionRightSide() <= position_.x) {
    std::cout << "PASSED" << std::endl;
    return true;
  }
  return false;
}
void Sprite::ResetGame() {
  GameEnd = false;
  current_pipe_ = nullptr;
  position_.x = (650 / 2) + 0.5;
  position_.y = 400.5;
}

glm::vec2 Sprite::Update() {
  glm::vec2 start_position = position_;
  next_position_ = position_ + glm::vec2(0, -60);
  //float x = ci::lerp(position_.x, next_position_.x, 0.5);
  //float y = ci::lerp(position_.y, next_position_.y, 0.5);
  float x = 0.1 * (position_.x - next_position_.x);
  float y = 0.1 * (position_.y - next_position_.y);
  std::cout << "Current Position: " << position_ << std::endl;
  std::cout << "Next Position: " << next_position_ << std::endl;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  lerp_ = glm::vec2(x,y);
  std::cout << "------------------------" << std::endl;

  return glm::vec2(x, y);


}

}
}
