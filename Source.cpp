#include "Color.h"
#include "Vector.h"

#include <cmath>

Vector::Vector(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};

void Vector::operator+=(Vector o)
{
	x += o.x; y += o.y; z += o.z;
}
void Vector::operator-=(Vector o)
{
	x -= o.x; y -= o.y; z -= o.z;
}
void Vector::operator*=(float s)
{
	x *= s; y *= s; z *= s;
}
void Vector::operator/=(float s)
{
	x /= s; y /= s; z /= s;
}
float Vector::sqrLength()
{
	return x*x + y*y + z*z;
}
float Vector::Length()
{
	return std::sqrtf(this->sqrLength());
}

float Vector::dot(Vector v1, Vector v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}
Vector Vector::cross(Vector v1, Vector v2)
{
	return Vector(v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]);
}

float & Vector::operator[](int i)
{
	if (i == 0)return x;
	if (i == 1)return y;
	if (i == 2)return z;
	throw "Invalid index";
}

Vector operator+(Vector v1, Vector v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector operator-(Vector v1, Vector v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
Vector operator*(Vector v, float s)
{
	return Vector(v.x*s, v.y*s, v.z*s);
}
Vector operator*(float s, Vector v)
{
	return Vector(v.x*s, v.y*s, v.z*s);
}
Vector operator/(Vector v, float s)
{
	return Vector(v.x/s, v.y/s, v.z/s);
}

ColorRGB::ColorRGB(float _r, float _g, float _b) :r(_r), g(_g), b(_b) {}
ColorRGB::ColorRGB() {}

void ColorRGB::operator+=(ColorRGB o)
{
	r = (r + o.r / 2.f);
	g = (g + o.g / 2.f);
	b = (b + o.b / 2.f);
}

ColorRGB operator+(ColorRGB c1, ColorRGB c2)
{
	return ColorRGB((c1.r + c2.r) / 2.f, (c1.g + c2.g) / 2.f, (c1.b + c2.b) / 2.f);
}

ColorRGBA::ColorRGBA(float _r, float _g, float _b, float _a) :r(_r), g(_g), b(_b), a(_a) {}
ColorRGBA::ColorRGBA(ColorRGB c)
{
	r = c.r; g = c.g; b = c.b; a = 1;
}
ColorRGBA::ColorRGBA() {}

void ColorRGBA::operator+=(ColorRGBA bg)
{/*
	a = 1 - (1 - a) * (1 - bg.a);
	if (a < 1E-6) r = g = b = 0;
	else
	{
		r = r * a / a + bg.r * bg.a * (1 - a) / a;
		g = g * a / a + bg.g * bg.a * (1 - a) / a;
		b = b * a / a + bg.b * bg.a * (1 - a) / a;
	}*/
}

ColorRGBA operator+(ColorRGBA fg, ColorRGBA bg)
{
	ColorRGBA r;
	r.a = 1 - (1 - fg.a) * (1 - bg.a);
	if (r.a< 1E-6) return r; // Fully transparent -- R,G,B not important
	r.r = fg.r * fg.a / r.a + bg.r * bg.a * (1 - fg.a) / r.a;
	r.g = fg.g * fg.a / r.a + bg.g * bg.a * (1 - fg.a) / r.a;
	r.b = fg.b * fg.a / r.a + bg.b * bg.a * (1 - fg.a) / r.a;
	return r;
}
