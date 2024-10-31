#pragma once
#include "Scene.h"
#include "ImageUtil.h"
#include "SoundUtil.h"
#include "IntroMode.h"
#include "CameraUtil.h"
#include "FontUtil.h"
#include "GameResource.h"


class LoadingScreen : public GameObject {
private:
	TextUtil text;
	bool LoadingCommand{};

public:
	void InputKey(int State, unsigned char NormalKey, int SpecialKey) {
		if (State == NORMAL_KEY_DOWN) {
			switch (NormalKey) {
			case NK_ESCAPE:
				scene.Exit();
				break;
			}
		}
	}

	LoadingScreen() {
		text.Init(L"Arial", FW_BOLD);
		text.SetColor(1.0, 1.0, 1.0);
		SetColor(1.0, 1.0, 1.0);
		camera.Init();
	}

	void UpdateFunc(float FT) {
		text.Render(0.5, -0.9, 0.2, 1.0, L"LOADING...");

		if (LoadingCommand) {
			imageUtil.Init();
			soundUtil.Init();

			soundUtil.Import(IntroSound, "MGKResource//Sound//MGK_Logo_Sound.wav", FMOD_DEFAULT);
			imageUtil.Import(ImageEngineLogo, "MGKResource//Image//Common//MGK_Logo.png");
			imageUtil.Import(ImageFMODLogo, "MGKResource//Image//Common//FMOD_Logo.png");
			imageUtil.Import(ImageCollisionSphere, "MGKResource//Image//Collision//Circle.png", IMAGE_TYPE_NEAREST);
			imageUtil.Import(ImageCollidedSphere, "MGKResource//Image//Collision//Circle_Inside.png", IMAGE_TYPE_NEAREST);
			imageUtil.Import(LineTex, "MGKResource//Image//ShapeUtil//Texture_Line.png", IMAGE_TYPE_NEAREST);

#ifdef USE_CUSTOM_FONT
			int TotalSize = sizeof(FONT_PATH);
			int ElementSize = sizeof(FONT_PATH[0]);
			int Length = TotalSize / ElementSize;
			for (int i = 0; i < Length; ++i) {
				DWORD Num = i;
				FontUtil::Import(FONT_PATH[i], Num);
			}
#endif

			if (!ENABLE_INTRO_SCREEN) {
				soundUtil.Release(IntroSound);
				imageUtil.Release(ImageEngineLogo);
				imageUtil.Release(ImageFMODLogo);

				scene.SwitchMode(START_MODE);
			}

			else {
				scene.SwitchMode(IntroMode::Start);
			}
		}

		LoadingCommand = true;
	}
};

