//
// Created by Phong Tran on 11/18/20.
//
#include "visualizer/sprite.h"

namespace naivebayes {

namespace visualizer {

void Sprite::Draw() {
  Drop();
  ci::gl::color(ci::Color("red"));

  ci::gl::drawSolidCircle(glm::vec2(position_.x, position_.y),
                          kRadius);
}

Sprite::Sprite(glm::vec2 position, glm::vec2 velocity, int radius) : position_(position), velocity_(velocity), kRadius(radius) {}

void Sprite::UpdatePosition(glm::vec2 position) {
  position_ = position;
}

glm::vec2 Sprite::GetPosition() { return position_; }

void Sprite::UpdateVelocity(glm::vec2 velocity) {
  velocity_ = velocity;
}
glm::vec2 Sprite::GetVelocity() { return velocity_; }

void Sprite::MoveLeft() {
  //position_.x -= velocity_.x;
  position_.y -= 10;
}

void Sprite::MoveRight() {
  position_.x += velocity_.x;
}
void Sprite::Drop() {
  position_.y += 0.5;
}

}
}

