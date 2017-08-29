#include"Matrix3.h"
#include"math.h"
#include<iostream>

Matrix3::Matrix3(){
	xAxis.x = 1;
	xAxis.y = {};
	xAxis.z = {};
	yAxis.x = {};
	yAxis.y = 1;
	yAxis.z = {};
	zAxis.x = {};
	zAxis.y = {};
	zAxis.z = 1;
}

Matrix3::Matrix3(float ax, float bx, float cx, float ay, float by, float cy, float az, float bz, float cz){
	xAxis.x = ax;
	xAxis.y = bx;
	xAxis.z = cx;
	yAxis.x = ay;
	yAxis.y = by;
	yAxis.z = cy;
	zAxis.x = az;
	zAxis.y = bz;
	zAxis.z = cz;
}

Matrix3::~Matrix3(){

}

//prints out the matrix
void Matrix3::print(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//transposts this matrix and stores it in a copy
Matrix3 Matrix3::transpose(Matrix3 &other){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i != j){
				other.m[i][j] = this -> m[j][i];
			}else{
				other.m[i][j] = this->m[i][j];
			}
		}
	}
	return other;
}

//same as above but doesn't store in a copy
Matrix3 Matrix3::transpose(){
	float tmp;
	for(int i = 0; i < 3; i++){
		for(int j = i; j < 3; j++){
			if(i != j){
				tmp = this->m[i][j];
				this->m[i][j] = this->m[j][i];
				this->m[j][i] = tmp;
			}
		}
	}
	return *this;
}

//multiplies 2 matrices together
Matrix3 Matrix3::operator*(Matrix3 &other){
	Matrix3 tmp(0, 0, 0, 0, 0, 0, 0, 0, 0);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				tmp.m[i][j] += (this->m[k][j] * other.m[i][k]);
			}
		}
	}
	return tmp;
}

//multiplies a matrix by a vector, sotres result in a vector3
Vector3 Matrix3::operator*(Vector3 &other){
	Vector3 tmp = {
		(this->m[0][0] * other.x) + (this->m[1][0] * other.y) + (this->m[2][0] * other.z),
		(this -> m[0][1] * other.x) + (this -> m[1][1] * other.y) + (this -> m[2][1] * other.z),
		(this -> m[0][2] * other.x) + (this -> m[1][2] * other.y) + (this -> m[2][2] * other.z)
	};
	return tmp;
}

//rotates the x-axis
Matrix3 Matrix3::setRotateX(float angle){
	m[1][1] = cosf(angle);
	m[1][2] = sin(angle);
	m[2][1] = -sin(angle);
	m[2][2] = cosf(angle);

	return(*this);
}

//rotates the y-axis
Matrix3 Matrix3::setRotateY(float angle){
	m[0][0] = cosf(angle);
	m[0][2] = -sin(angle);
	m[2][0] = sin(angle);
	m[2][2] = cosf(angle);
	return (*this);
}

//rotates the z-axis
Matrix3 Matrix3::setRotateZ(float angle){
	m[0][0] = cosf(angle);
	m[0][1] = sin(angle);
	m[1][0] = -sin(angle);
	m[1][1] = cosf(angle);
	return (*this);
}

//returns an axis
Vector3 & Matrix3::operator[](int axis){
	if(axis == 0){
		return xAxis;
	}else if(axis == 1){
		return yAxis;
	}else if(axis == 2){
		return zAxis;
	}
}

//returns a pointer to the matrix
Matrix3::operator float*(){
	return((float*)this);
}