#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <String>
#include "Renderer.h"

SDL_Texture* loadTexture(std::string path, Renderer r);
std::string parseLine(std::string line, std::string getData);
std::string parseBracketData(std::string line, int num);