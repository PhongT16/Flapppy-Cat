//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/sprite.h"
#include <cinder/app/AppBase.h>
#include <iostream>

namespace game {

namespace visualizer {

Sprite::Sprite(const glm::vec2 &position, const glm::vec2 &velocity,
               size_t apothem)
    : starting_position_(position), starting_velocity_(velocity),
      position_(position), velocity_(velocity), kApothem(apothem),
      current_pipe_(0), is_lerp_active_(false), kWindowSize(650) {}

Sprite::Sprite(const glm::vec2 &position, const glm::vec2 &velocity,
               size_t apothem, double window_size)
    : starting_position_(position), starting_velocity_(velocity),
      position_(position), velocity_(velocity), kApothem(apothem),
      current_pipe_(0), is_lerp_active_(false), kWindowSize(window_size) {
  up_motion_texture_ =
      ci::gl::Texture::create(ci::loadImage("data/sprite.png"));
  down_motion_texture_ =
      ci::gl::Texture::create(ci::loadImage("data/sprite2.png"));
  has_collided_ = false;
}

void Sprite::Draw() {
  // has_collided_ = CollisionDetection();
  ci::gl::color(ci::Color::white());

  if (position_.y > next_position_.y && is_lerp_active_) {
    position_.y -= lerp_.y;
    ci::gl::draw(up_motion_texture_,
                 ci::Rectf(position_.x - kApothem, position_.y - kApothem,
                           position_.x + kApothem, position_.y + kApothem));
  } else {
    is_lerp_active_ = false;
    Drop();
    ci::gl::draw(down_motion_texture_,
                 ci::Rectf(position_.x - kApothem, position_.y - kApothem,
                           position_.x + kApothem, position_.y + kApothem));
  }
}

bool Sprite::CollisionDetection() {
  return CheckPipeCollision() || CheckBorderCollision();
}

void Sprite::Drop() { position_.y += velocity_.y; }

void Sprite::MoveUp() {
  RelativeLerpUp();
  is_lerp_active_ = true;
}

bool Sprite::CheckBorderCollision() {

  double top_border_y_ = 0;
  double bottom_border_y_ = kWindowSize;
  bool is_collision = false;

  if (is_lerp_active_ && position_.y - kApothem - lerp_.y <= top_border_y_) {
    position_.y = top_border_y_ + kApothem;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0, 0);
    is_collision = true;
  } else if (position_.y + velocity_.y + kApothem >= bottom_border_y_) {
    position_.y = bottom_border_y_ - kApothem;
    position_.x += velocity_.x;
    velocity_ = glm::vec2(0, 0);
    is_collision = true;
  }
  return is_collision;
}

bool Sprite::CheckPipeCollision() {
  bool has_collided = false;

  if (current_pipe_ != NULL) {
    // Checks for side collision with pipe
    if (position_.x < current_pipe_->GetPositionLeftSide() &&
        position_.x + kApothem + current_pipe_->GetSpeed() >=
            current_pipe_->GetPositionLeftSide() &&
        position_.y < current_pipe_->GetTopPipeBorder()) {
      position_.x = current_pipe_->GetPositionLeftSide() - kApothem;
      velocity_ = glm::vec2(0, 0);
      has_collided = true;
    } else if (position_.x < current_pipe_->GetPositionLeftSide() &&
               position_.x + kApothem + current_pipe_->GetSpeed() >=
                   current_pipe_->GetPositionLeftSide() &&
               position_.y >= current_pipe_->GetBottomPipeBorder()) {
      position_.x = current_pipe_->GetPositionLeftSide() - kApothem;
      velocity_ = glm::vec2(0, 0);
      has_collided = true;
    }

    // Checks for internal collision with pipe
    if (position_.x >= current_pipe_->GetPositionLeftSide() &&
        position_.x - kApothem <= current_pipe_->GetPositionRightSide()) {
      if (is_lerp_active_ && position_.y - kApothem - lerp_.y <=
                                 current_pipe_->GetTopPipeBorder()) {
        position_.y = current_pipe_->GetTopPipeBorder() + kApothem;
        velocity_ = glm::vec2(0, 0);
        has_collided = true;
      } else if (position_.y + kApothem + velocity_.y >=
                 current_pipe_->GetBottomPipeBorder()) {
        position_.y = current_pipe_->GetBottomPipeBorder() - kApothem;
        velocity_ = glm::vec2(0, 0);
        has_collided = true;
      }
    }
  }
  return has_collided;
}
void Sprite::SetPipe(const Pipe &pipe) { current_pipe_ = &pipe; }

bool Sprite::HasPassedPipe(const Pipe &pipe) {
  return pipe.GetPositionRightSide() < position_.x - kApothem;
}

void Sprite::ResetGame() {
  has_collided_ = false;
  current_pipe_ = nullptr;
  position_ = starting_position_;
  velocity_ = starting_velocity_;
}

glm::vec2 Sprite::RelativeLerpUp() {
  // Relative Lerp
  next_position_ = position_ + glm::vec2(0, -60);
  float x = 0.1 * (position_.x - next_position_.x);
  float y = 0.1 * (position_.y - next_position_.y);

  lerp_ = glm::vec2(x, y);
  return glm::vec2(x, y);
}

glm::vec2 &Sprite::GetVelocity() { return velocity_; }
glm::vec2 &Sprite::GetPosition() { return position_; }
glm::vec2 Sprite::GetLerp() {
  return is_lerp_active_ ? lerp_ : glm::vec2(0, 0);
}

} // namespace visualizer
} // namespace game
