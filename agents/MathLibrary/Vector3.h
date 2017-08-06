#pragma once

class Vector3{
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();
	void print();
	float magnitude();
	Vector3 normalise();
	Vector3 normalise(Vector3 &other);
	float dot(Vector3 &other);
	Vector3 cross(Vector3 &other);
	float angle(Vector3 &other);

	Vector3 operator+(Vector3 &other);
	Vector3 operator-(Vector3 &other);
	Vector3 operator*(float scale);
	friend Vector3 operator*(float scale, Vector3 other);
	Vector3 operator/(float scale);
	Vector3 operator*=(float scale);
	Vector3 operator/=(float scale);
	Vector3 operator+=(Vector3 &other);
	Vector3 operator-=(Vector3 &other);
	operator float*();

	float x;
	float y;
	float z;
};