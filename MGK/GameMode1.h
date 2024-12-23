#pragma once
#include "Scene.h"
#include "MouseUtil.h"

class GameMode1 {
public:
	static GameMode1* M_Inst;
	GameMode1() {
		M_Inst = this;
	}

	static void Start() {
		Framework::SetBackColor(0.3, 0.3, 0.3);

		scene.RegisterController(Controller, MODE_TYPE_DEFAULT);
		scene.RegisterDestructor(Destructor);
		scene.RegisterModeName("GameMode1");
	}

	static void Destructor() {

	}

	/////////////////////////////////////////////////////////////

	void ProcessKeyboard(int State, unsigned char NormalKey, int SpecialKey) {
		KeyEvent Event{ State, NormalKey, SpecialKey };

		if (Event.Type == NORMAL_KEY_DOWN) {
			switch (Event.NormalKey) {
			case NK_ESCAPE:
				Framework::Exit();
				break;
			}
		}
	}

	void ProcessMouseButton(int Type) {

	}

	void ProcessMouseWheel(int Type) {

	}

/////////////////////////////////////////////////////////////

	static void KeyDown(unsigned char KEY, int X, int Y) {
		M_Inst->ProcessKeyboard(NORMAL_KEY_DOWN, KEY, NULL);
	}

	static void KeyUp(unsigned char KEY, int X, int Y) {
		M_Inst->ProcessKeyboard(NORMAL_KEY_UP, KEY, NULL);
	}

	static void SpecialKeyDown(int KEY, int X, int Y) {
		M_Inst->ProcessKeyboard(SPECIAL_KEY_DOWN, NULL, KEY);
	}

	static void SpecialKeyUp(int KEY, int X, int Y) {
		M_Inst->ProcessKeyboard(SPECIAL_KEY_UP, NULL, KEY);
	}

	static void MouseMotion(int X, int Y) {
		mouse.ConvertPosition(X, Y);
	}

	static void MousePassiveMotion(int X, int Y) {
		mouse.ConvertPosition(X, Y);
	}

	static void MouseWheel(int Button, int Wheel, int X, int Y) {
		if (Wheel > 0)
			M_Inst->ProcessMouseWheel(WHEEL_UP);
		else if (Wheel < 0)
			M_Inst->ProcessMouseWheel(WHEEL_DOWN);
	}

	static void MouseButton(int Button, int State, int X, int Y) {
		switch (State) {
		case GLUT_DOWN:
			switch (Button) {
			case GLUT_LEFT_BUTTON:
				M_Inst->ProcessMouseButton(LEFT_BUTTON_DOWN);   break;
			case GLUT_RIGHT_BUTTON:
				M_Inst->ProcessMouseButton(RIGHT_BUTTON_DOWN);  break;
			case GLUT_MIDDLE_BUTTON:
				M_Inst->ProcessMouseButton(MIDDLE_BUTTON_DOWN); break;
			}
			break;

		case GLUT_UP:
			switch (Button) {
			case GLUT_LEFT_BUTTON:
				M_Inst->ProcessMouseButton(LEFT_BUTTON_UP);   break;
			case GLUT_RIGHT_BUTTON:
				M_Inst->ProcessMouseButton(RIGHT_BUTTON_UP);  break;
			case GLUT_MIDDLE_BUTTON:
				M_Inst->ProcessMouseButton(MIDDLE_BUTTON_UP); break;
			}
			break;
		}
	}

	static void Controller() {
		glutMotionFunc(MouseMotion);
		glutPassiveMotionFunc(MousePassiveMotion);
		glutKeyboardFunc(KeyDown);
		glutKeyboardUpFunc(KeyUp);
		glutMouseWheelFunc(MouseWheel);
		glutMouseFunc(MouseButton);
		glutSpecialFunc(SpecialKeyDown);
		glutSpecialUpFunc(SpecialKeyUp);
	}
};
extern GameMode1 Mode1;