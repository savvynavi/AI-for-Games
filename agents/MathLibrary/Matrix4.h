#pragma once
#include"Vector4.h"

class Matrix4{
public:
	union{
		struct{
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 wAxis;
		};
		float m[4][4];
	};

	Matrix4();
	Matrix4(float ax, float bx, float cx, float dx, float ay, float by, float cy, float dy, float az, float bz, float cz, float dz, float aw, float bw, float cw, float dw);
	~Matrix4();
	void print();
	Matrix4 transpose(Matrix4 &other);
	Matrix4 transpose();
	Matrix4 setRotateX(float angle);
	Matrix4 setRotateY(float angle);
	Matrix4 setRotateZ(float angle);

	Matrix4 operator*(Matrix4 &other);
	Vector4 operator*(Vector4 &other);
	Vector4 & operator[](int axis);
	operator float*();
};