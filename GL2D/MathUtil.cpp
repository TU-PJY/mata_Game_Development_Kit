#include "MathUtil.h"
#include <cmath>


void Math::LookAt(GLfloat FromX, GLfloat FromY, GLfloat ToX, GLfloat ToY, GLfloat& RotationVar, GLfloat RotationSpeed, float FT) {
	GLfloat targetAngle{}, shortestAngle{};
	targetAngle = atan2(ToY - FromY, ToX - FromX) * (180 / 3.14) - 90;
	targetAngle = NormalizeDegree(targetAngle);

	if (RotationSpeed > 0)
		shortestAngle = std::lerp(shortestAngle, CalculateShortestRotation(RotationVar, targetAngle), FT * RotationSpeed);
	else
		shortestAngle = CalculateShortestRotation(RotationVar, targetAngle);

	RotationVar = NormalizeDegree(RotationVar + shortestAngle);
}

void Math::LookAt(GLfloat Rotation, GLfloat& RotationVar, GLfloat RotationSpeed, float FT) {
	GLfloat targetAngle{}, shortestAngle{};
	targetAngle = NormalizeDegree(Rotation);

	if (RotationSpeed > 0)
		shortestAngle = std::lerp(shortestAngle, CalculateShortestRotation(RotationVar, targetAngle), FT * RotationSpeed);
	else
		shortestAngle = CalculateShortestRotation(RotationVar, targetAngle);

	RotationVar = NormalizeDegree(RotationVar + shortestAngle);
}

GLfloat Math::CalcDistance(GLfloat FromX, GLfloat FromY, GLfloat ToX, GLfloat ToY) {
	return  std::sqrt(std::pow(FromX - ToX, 2) + std::pow(FromY - ToY, 2));
}

GLfloat Math::NormalizeDegree(GLfloat Degree) {
	while (Degree < 0) Degree += 360;
	while (Degree >= 360) Degree -= 360;
	return Degree;
}

GLfloat Math::CalculateShortestRotation(GLfloat CurrentDegree, GLfloat DegreeDest) {
	float Diff = DegreeDest - CurrentDegree;

	if (Diff > 180)
		Diff -= 360;
	else if (Diff < -180)
		Diff += 360;

	return Diff;
}