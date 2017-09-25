#pragma once
struct Vector
{
	float x, y, z;
	Vector(float x = 0, float y = 0, float z = 0);
	void operator+=(Vector other);
	void operator-=(Vector other);
	void operator*=(float scalar);
	void operator/=(float scalar);
	float sqrLength();
	float Length();
	static float dot(Vector v1, Vector v2);
	static Vector cross(Vector v1, Vector v2);

	float &operator[](int index);
};

Vector operator+(Vector vector1, Vector vector2);
Vector operator-(Vector vector1, Vector vector2);
Vector operator*(Vector vector, float scalar);
Vector operator*(float scalar, Vector vector);
Vector operator/(Vector vector, float scalar);