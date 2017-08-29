#pragma once
#include"Vector2.h"

class Matrix2{
public:
	union{
		struct{
			Vector2 xAxis;
			Vector2 yAxis;
		};
		float m[2][2];
	};

	Matrix2();
	Matrix2(float ax, float ay, float bx, float by);
	~Matrix2();
	void print();
	Matrix2 transpose(Matrix2 &other);
	Matrix2 transpose();
	Matrix2 setRotate(float angle);

	Matrix2 operator*(Matrix2 &other);
	Vector2 operator*(Vector2 &other);
	Vector2 & operator[](int axis);
	operator float*();
};