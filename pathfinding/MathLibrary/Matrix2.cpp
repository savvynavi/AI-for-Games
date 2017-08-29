#include"Matrix2.h"
#include"math.h"
#include<iostream>

Matrix2::Matrix2(){
	xAxis.x = 1;
	xAxis.y = {};
	yAxis.x = {};
	yAxis.y = 1;
}

Matrix2::Matrix2(float ax, float bx, float ay, float by){
	xAxis.x = ax;
	xAxis.y = bx;
	yAxis.x = ay;
	yAxis.y = by;
}

Matrix2::~Matrix2(){

}

//prints matrix out
void Matrix2::print(){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//transposes this matrix
Matrix2 Matrix2::transpose(){
	float tmp;
	tmp = this->xAxis.y;
	this->xAxis.y = this->yAxis.x;
	this->yAxis.x = tmp;
	return *this;
}


//returns a copy of the matrix, transposed
Matrix2 Matrix2::transpose(Matrix2 &other){
	other.xAxis.x = this->xAxis.x;
	other.xAxis.y = this->yAxis.x;
	other.yAxis.x = this->xAxis.y;
	other.yAxis.y = this->yAxis.y;
	return other;
}

//rotates this matrix by given angle
Matrix2 Matrix2::setRotate(float angle){
	Matrix2 rotate(cosf(angle), sinf(angle), -sinf(angle), cosf(angle));
	*this = (*this) * rotate;
	return *this;
}

//multiply a matrix2 by another matrix2
Matrix2 Matrix2::operator*(Matrix2 &other){
	Matrix2 tmp;
	tmp.xAxis.x = (this -> m[0][0] * other.m[0][0]) + (this -> m[0][1] * other.m[1][0]);
	tmp.xAxis.y = (this -> m[0][0] * other.m[0][1]) + (this -> m[0][1] * other.m[1][1]);
	tmp.yAxis.x = (this -> m[1][0] * other.m[0][0]) + (this -> m[1][1] * other.m[1][0]);
	tmp.yAxis.y = (this -> m[1][0] * other.m[0][1]) + (this -> m[1][1] * other.m[1][1]);
	return tmp;
}

//multiply a matrix2 by a vector2
Vector2 Matrix2::operator*(Vector2 &other){
	Vector2 tmp;
	tmp.x = (this -> m[0][0] * other.x) + (this -> m[1][0] * other.y);
	tmp.y = (this -> m[0][1] * other.x) + (this -> m[1][1] * other.y);
	return tmp;
}

//returns an axis
Vector2 & Matrix2::operator[](int axis){
	if(axis == 0){
		return xAxis;
	}else if(axis == 1){
		return yAxis;
	}
}

//returns a pointer to the matrix
Matrix2::operator float*(){
	return((float*)this);
}