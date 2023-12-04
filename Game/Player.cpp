#include "Player.h"
#include "Novice.h"
Player::Player() {

}

void Player::Init() {
	this->pos = {640.0f,360.0f};
	this->speed_ = 2.0f;
}

void Player::Update() {
	
}

void Player::Draw() {
	Novice::DrawEllipse((int)pos.x,(int)pos.y,20,20,0.0f,RED,kFillModeSolid);
}


void Player::MoveRight() {
	this->pos.x += this->speed_;
}

void Player::MoveLeft() {
	this->pos.x -= this->speed_;
}
