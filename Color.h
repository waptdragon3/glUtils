#pragma once
#include "typedefs.h"
struct ColorRGB
{
	float r, g, b;
	ColorRGB(float r, float g, float b);
	ColorRGB();
	void operator+=(ColorRGB other);
};

ColorRGB operator+(ColorRGB color1, ColorRGB color2);

struct ColorRGBA
{
	float r, g, b, a;
	ColorRGBA(float r, float g, float b, float a);
	ColorRGBA(ColorRGB color);
	ColorRGBA();
	void operator+=(ColorRGBA other);	
};

//ColorRGBA operator+(ColorRGBA color1, ColorRGBA color2);