#include "CameraController.h"
#include "CameraUtil.h"
#include "TransformUtil.h"

void CameraController::Update(float FT) {
	// add logic here

	CalcMatrix();
}

void CameraController::CalcMatrix() {
	Transform::Identity(camera.TranslateMatrix);
	Transform::Identity(camera.RotateMatrix);
	Transform::Move(camera.TranslateMatrix, Position.x, Position.y);
	Transform::Rotate(camera.RotateMatrix, Rotation);
}

void CameraController::Move(GLfloat X, GLfloat Y) {
	Position.x = -X;
	Position.y = -Y;
}

void CameraController::Move(glm::vec2& PositionValue) {
	Position = -PositionValue;
}

void CameraController::Rotate(GLfloat Value) {
	Rotation = Value;
}

void CameraController::Zoom(int Type, GLfloat Value) {
	switch (Type) {
	case ZOOM_IN:
		camera.ZoomValue = camera.ZoomValue / (1.0f - Value);
		break;

	case ZOOM_OUT:
		camera.ZoomValue = camera.ZoomValue * (1.0f - Value);
		break;
	}
}

GLfloat CameraController::CalculateNextZoom(int Type, GLfloat Value) {
	switch (Type) {
	case ZOOM_IN:
		return camera.ZoomValue / (1.0f - Value);
		break;

	case ZOOM_OUT:
		return camera.ZoomValue * (1.0f - Value);
		break;
	}
}

void CameraController::ChangeZoom(GLfloat Value) {
	camera.ZoomValue = Value;
}