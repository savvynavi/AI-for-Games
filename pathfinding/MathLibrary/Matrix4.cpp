#include"Matrix4.h"
#include"math.h"
#include<iostream>

Matrix4::Matrix4(){
	xAxis.x = 1;
	xAxis.y = 0;
	xAxis.z = 0;
	xAxis.w = 0;
	yAxis.x = 0;
	yAxis.y = 1;
	yAxis.z = 0;
	yAxis.w = 0;
	zAxis.x = 0;
	zAxis.y = 0;
	zAxis.z = 1;
	zAxis.w = 0;
	wAxis.x = 0;
	wAxis.y = 0;
	wAxis.z = 0;
	wAxis.w = 1;
}

Matrix4::Matrix4(float ax, float bx, float cx, float dx, float ay, float by, float cy, float dy, float az, float bz, float cz, float dz, float aw, float bw, float cw, float dw){
	xAxis.x = ax;
	xAxis.y = bx;
	xAxis.z = cx;
	xAxis.w = dx;
	yAxis.x = ay;
	yAxis.y = by;
	yAxis.z = cy;
	yAxis.w = dy;
	zAxis.x = az;
	zAxis.y = bz;
	zAxis.z = cz;
	zAxis.w = dz;
	wAxis.x = aw;
	wAxis.y = bw;
	wAxis.z = cw;
	wAxis.w = dw;
}

Matrix4::~Matrix4(){

}

//prints out the matrix
void Matrix4::print(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//transposts this matrix and stores it in a copy
Matrix4 Matrix4::transpose(Matrix4 &other){
	//Matrix3 tmp;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i != j){
				other.m[i][j] = this->m[j][i];
			} else{
				other.m[i][j] = this->m[i][j];
			}
		}
	}
	return other;
}

//transposes the matrix and changes the original
Matrix4 Matrix4::transpose(){
	float tmp;
	for(int i = 0; i < 4; i++){
		for(int j = i; j < 4; j++){
			if(i != j){
				tmp = this->m[i][j];
				this->m[i][j] = this->m[j][i];
				this->m[j][i] = tmp;
			}
		}
	}
	return *this;
}

//multiplies this matrix by another matrix4
Matrix4 Matrix4::operator*(Matrix4 &other){
	Matrix4 tmp(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				tmp.m[i][j] += (this->m[k][j] * other.m[i][k]);
			}
		}
	}

	return tmp;
}

//multiplies this matrix by a vector4, stores in another vector4
Vector4 Matrix4::operator*(Vector4 &other){
	Vector4 tmp = {
		(this->m[0][0] * other.x) + (this->m[1][0] * other.y) + (this->m[2][0] * other.z) + (this->m[3][0] * other.w),
		(this->m[0][1] * other.x) + (this->m[1][1] * other.y) + (this->m[2][1] * other.z) + (this->m[3][1] * other.w),
		(this->m[0][2] * other.x) + (this->m[1][2] * other.y) + (this->m[2][2] * other.z) + (this->m[3][2] * other.w),
		(this->m[0][3] * other.x) + (this->m[1][3] * other.y) + (this->m[2][3] * other.z) + (this->m[3][3] * other.w)
	};
	return tmp;
}

//rotates the x-axis
Matrix4 Matrix4::setRotateX(float angle){
	m[1][1] = cosf(angle);
	m[1][2] = sin(angle);
	m[2][1] = -sin(angle);
	m[2][2] = cosf(angle);

	return(*this);
}

//rotates the y-axis
Matrix4 Matrix4::setRotateY(float angle){
	m[0][0] = cosf(angle);
	m[0][2] = -sin(angle);
	m[2][0] = sin(angle);
	m[2][2] = cosf(angle);
	return (*this);
}

//rotates the z-axis
Matrix4 Matrix4::setRotateZ(float angle){
	m[0][0] = cosf(angle);
	m[0][1] = sin(angle);
	m[1][0] = -sin(angle);
	m[1][1] = cosf(angle);
	return (*this);
}

//returns an axis
Vector4 & Matrix4::operator[](int axis){
	if(axis == 0){
		return xAxis;
	}else if(axis == 1){
		return yAxis;
	}else if(axis == 2){
		return zAxis;
	}else if(axis == 3){
		return wAxis;
	}
}

//returns a pointer to the matrix
Matrix4::operator float*(){
	return((float*)this);
}