#pragma once
#include "Framework.h"
#include "ImageUtil.h"
#include "SoundUtil.h"
#include "IntroMode.h"
#include "CameraUtil.h"

class LoadingScreen : public GameObject {
private:
	TextUtil text;
	
public:
	LoadingScreen() {
		camera.Init();

		SetBackColor(0.0, 0.0, 0.0);
		text.Init(L"Arial", FW_BOLD);
		text.SetColor(1.0, 1.0, 1.0);
		text.SetRenderType(RenderType::Static);
	}

	void Update(float FT) {
		text.Render(0.5, -0.9, 0.2, 1.0, L"LOADING...");

		imageUtil.Init();
		soundUtil.Init();

		LoadSystemResources();
		LoadImageResources();
		LoadSoundResources();

		if (!ENABLE_INTRO_SCREEN) {
			SetBackColor(R, G, B);
			framework.SwitchMode(StartMode);
		}

		else
			framework.SwitchMode(Intro_Mode::IntroMode);
	}
};

