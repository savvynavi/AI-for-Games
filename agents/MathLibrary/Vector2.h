#pragma once

class Vector2{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();
	void print();
	float magnitude();
	float magnitude(Vector2 &other);
	Vector2 normalise();
	Vector2 normalise(Vector2 &other);
	float dot(Vector2 &other);
	float cross(Vector2 &other);
	float angle(Vector2 &other);
	Vector2 interpolation(const Vector2 &a, const Vector2 &b, float t);

	Vector2 operator+(Vector2 &other);
	Vector2 operator-(Vector2 &other);
	Vector2 operator*(float scale);
	friend Vector2 operator*(float scale, Vector2 other);
	Vector2 operator/(float scale);
	Vector2 operator*=(float scale);
	Vector2 operator/=(float scale);
	Vector2 operator+=(Vector2 &other);
	Vector2 operator-=(Vector2 &other);
	operator float*();

	float x;
	float y;
};