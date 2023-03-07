#ifndef COMMON_FUNC_H_
#define COMMON_FUNC_H_

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gScreen = NULL;
static SDL_Event gEvent;

//window dimension
const int FRAME_PER_SECOND = 40;
const int SCREEN_HEIGHT = 1000;
const int SCREEN_WIDTH = 1600;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0xff;

#endif