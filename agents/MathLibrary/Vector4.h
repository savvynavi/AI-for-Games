#pragma once

class Vector4{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();
	void print();
	float magnitude();
	Vector4 normalise();
	Vector4 normalise(Vector4 &other);
	float dot(Vector4 &other);
	Vector4 cross(Vector4 &other);
	float angle(Vector4 &other);

	Vector4 operator+(Vector4 &other);
	Vector4 operator-(Vector4 &other);
	Vector4 operator*(float scale);
	friend Vector4 operator*(float scale, Vector4 other);
	Vector4 operator/(float scale);
	Vector4 operator*=(float scale);
	Vector4 operator/=(float scale);
	Vector4 operator+=(Vector4 &other);
	Vector4 operator-=(Vector4 &other);
	operator float*();

	float x;
	float y;
	float z;
	float w;
};