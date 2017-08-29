#pragma once
#include"Vector3.h"

class Matrix3{
public:
	union{
		struct{
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		float m[3][3];
	};

	Matrix3();
	Matrix3(float ax, float bx, float cx, float ay, float by, float cy, float az, float bz, float cz);
	~Matrix3();
	void print();
	Matrix3 transpose(Matrix3 &other);
	Matrix3 transpose();
	Matrix3 setRotateX(float angle);
	Matrix3 setRotateY(float angle);
	Matrix3 setRotateZ(float angle);

	Matrix3 operator*(Matrix3 &other);
	Vector3 operator*(Vector3 &other);
	Vector3 & operator[](int axis);
	operator float*();
};