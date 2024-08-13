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

// framework message option
constexpr bool SHOW_FRAMEWORK_MESSAGE = true;

// framework layer option
// 'END' should be typed at last
enum class Layer
{ L1, L2, L3, END };

// show boundbox option
#define SHOW_BOUND_BOX