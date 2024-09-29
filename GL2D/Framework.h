#pragma once
#include "GameObject.h"
#include <algorithm>
#include <unordered_map>

typedef void(*Function)(void);
typedef void(*ControllerFunction)(void);
constexpr int Layers = static_cast<int>(Layer::END);

using LayerIter = std::unordered_multimap<std::string, GameObject*>::iterator;

typedef struct {
	LayerIter First, End;
}ObjectRange;

enum class DeleteRange
{ One, All };

enum class SearchRange
{ One, All };

enum class ModeType
{ Default, Floating };

class Framework {
private:
	std::unordered_multimap<std::string, GameObject*> ObjectList;

	const char*						  CurrentRunningMode{};
	const char*						  PrevRunningMode{};

	bool							  FloatingRunningActivated{};
	bool                              FloatingFocusActivated{};

	float							  FrameTime{};

	ControllerFunction				  ControllerBuffer{};
	Function						  DestructorBuffer{};

public:
	const char* Mode();
	void RegisterModeName(const char* ModeName);
	void Init(Function ModeFunction);
	void RegisterController(ControllerFunction Controller, ModeType Type);
	void InputFrameTime(float ElapsedTime);
	void Routine();
	void SwitchMode(Function ModeFunction);
	void RegisterDestructor(Function DestructorFunction);
	void ReleaseDestructor();
	void StartFloatingMode(Function ModeFunction, bool FloatingFocus=false);
	void EndFloatingMode();
	void ResetControlState(GameObject* Object);
	void ResetControlState(const char* Tag);
	void InputKey(const char* Tag, KeyType Key, KeyState State, unsigned char NormalKey, int SpecialKey);
	void InputMouse(const char* Tag, int button, int state, int x, int y);
	void InputScroll(const char* Tag, int button, int Wheel, int x, int y);
	void AddObject(GameObject* Object, const char* Tag, Layer AddLayer, bool SetFloatingObject=false, bool SetStaticObject =false);
	void SwapLayer(GameObject* Object, Layer TargetLayer);
	void DeleteObject(GameObject* Object);
	void DeleteObject(const char* Tag, DeleteRange deleteRange);
	GameObject* Find(const char* Tag);
	ObjectRange EqualRange(const char* Tag);
	void Exit();

private:
	void UpdateContainer();
	void ClearFloatingObject();
	void ClearAll();
};
extern Framework framework;