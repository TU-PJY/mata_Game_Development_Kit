#pragma once

// window name
constexpr const char* WINDOW_NAME = "mata_ENGINE-2";

// window size
constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 800;

// fullscreen option
constexpr bool FULL_SCREEN_OPTION = false;

// console window option
constexpr bool SHOW_CONSOLE = true;

// intro screen option
constexpr bool ENABLE_INTRO_SCREEN = true;

// framework layer option
// 'END' should be typed at last
enum class Layer
{ L1, L2, L3, END };

// framework container reserve option
constexpr int OBJECT_LIST_RESERVE = 500;

// show boundbox option
#define SHOW_BOUND_BOX

// data system option
//#define USE_DATA_SYSTEM