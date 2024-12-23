#include "MoveUtil.h"

void Move::MoveStraight(GLfloat& Position, int MoveDirection, GLfloat Speed, float FT) {
	Position += Speed * MoveDirection * FT;
}

void Move::MoveStraight(GLfloat& Position, GLfloat Speed, float FT) {
	Position += Speed * FT;
}

void Move::MoveForward(GLfloat& X, GLfloat& Y, GLfloat Speed, int MoveDirection, GLfloat RotationValue, float FT, bool Plus90Option) {
	if (Plus90Option) {
		X += Speed * cos(glm::radians(RotationValue + 90)) * MoveDirection * FT;
		Y += Speed * sin(glm::radians(RotationValue + 90)) * MoveDirection * FT;
	}
	else {
		X += Speed * cos(glm::radians(RotationValue)) * MoveDirection * FT;
		Y += Speed * sin(glm::radians(RotationValue)) * MoveDirection * FT;
	}
}

void Move::MoveForward(glm::vec2& Position, GLfloat Speed, int MoveDirection, GLfloat RotationValue, float FrameTime, bool Plus90Option) {
	if (Plus90Option) {
		Position.x += Speed * cos(glm::radians(RotationValue + 90)) * MoveDirection * FrameTime;
		Position.y += Speed * sin(glm::radians(RotationValue + 90)) * MoveDirection * FrameTime;
	}
	else {
		Position.x += Speed * cos(glm::radians(RotationValue)) * MoveDirection * FrameTime;
		Position.y += Speed * sin(glm::radians(RotationValue)) * MoveDirection * FrameTime;
	}
}

void Move::MoveForward(GLfloat& X, GLfloat& Y, GLfloat Speed, GLfloat RotationValue, float FT, bool Plus90Option) {
	if (Plus90Option) {
		X += Speed * cos(glm::radians(RotationValue + 90)) * FT;
		Y += Speed * sin(glm::radians(RotationValue + 90)) * FT;
	}
	else {
		X += Speed * cos(glm::radians(RotationValue)) * FT;
		Y += Speed * sin(glm::radians(RotationValue)) * FT;
	}
}

void Move::MoveForward(glm::vec2& Position, GLfloat Speed, GLfloat RotationValue, float FrameTime, bool Plus90Option) {
	if (Plus90Option) {
		Position.x += Speed * cos(glm::radians(RotationValue + 90)) * FrameTime;
		Position.y += Speed * sin(glm::radians(RotationValue + 90)) * FrameTime;
	}
	else {
		Position.x += Speed * cos(glm::radians(RotationValue)) * FrameTime;
		Position.y += Speed * sin(glm::radians(RotationValue)) * FrameTime;
	}
}