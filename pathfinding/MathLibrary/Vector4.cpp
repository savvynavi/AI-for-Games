#include"Vector4.h"
#include<math.h>
#include<iostream>

Vector4::Vector4() : x(0), y(0), z(0), w(1){

}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){

}

Vector4::~Vector4(){

}

//prints this vector
void Vector4::print(){
	std::cout << this->x << " " << this->y << " " << this->z << " " << this->w << std::endl;
}

//returns the magnitude of this vector
float Vector4::magnitude(){
	float tmp = pow(this -> x, 2) + pow(this -> y, 2) + pow(this -> z, 2) + pow(this -> w, 2);
	return sqrt(tmp);
}

//returns the normal of this vector
Vector4 Vector4::normalise(){
	float tmp = this->magnitude();
	this->x /= tmp;
	this->y /= tmp;
	this->z /= tmp;
	return *this;
}

//returns copy of normal
Vector4 Vector4::normalise(Vector4 &other){
	float tmp = this->magnitude();
	other.x = this -> x / tmp;
	other.y = this -> y / tmp;
	other.z = this -> z / tmp;
	return other;
}

//returns the dot product
float Vector4::dot(Vector4 &other){
	float dotProd = (this -> x * other.x) + (this -> y * other.y) + (this -> z * other.z);
	return dotProd;
}

//returns the cross product
Vector4 Vector4::cross(Vector4 &other){
	Vector4 tmp;
	tmp.x = (this->y * other.z) - (this->z * other.y);
	tmp.y = (this->z * other.x) - (this->x * other.z);
	tmp.z = (this->x * other.y) - (this->y * other.x);
	tmp.w = this->w;
	return tmp;
}

//returns the angle
float Vector4::angle(Vector4 &other){
	float angle = acos(this->dot(other) / (this->magnitude() * other.magnitude()));
	return angle;
}

Vector4 Vector4::operator+(Vector4 &other){
	Vector4 tmp(this -> x + other.x, this -> y + other.y, this -> z + other.z, this -> w + other.w);
	return tmp;
}

Vector4 Vector4::operator-(Vector4 &other){
	Vector4 tmp(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
	return tmp;
}

Vector4 Vector4::operator*(float scale){
	Vector4 tmp(this->x * scale, this->y * scale, this->z * scale, this->w * scale);
	return tmp;
}

Vector4 operator*(float scale, Vector4 other){
	Vector4 tmp(other.x * scale, other.y * scale, other.z * scale, other.w * scale);
	return tmp;
}

Vector4 Vector4::operator/(float scale){
	Vector4 tmp(this->x / scale, this->y / scale, this->z / scale, this->w / scale);
	return tmp;
}

Vector4 Vector4::operator*=(float scale){
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
	this->w *= scale;
	return *this;
}

Vector4 Vector4::operator/=(float scale){
	this->x /= scale;
	this->y /= scale;
	this->z /= scale;
	this->w /= scale;
	return *this;
}

Vector4 Vector4::operator+=(Vector4 &other){
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
	return *this;
}

Vector4 Vector4::operator-=(Vector4 &other){
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
	return *this;
}

//returns a pointer to the vector
Vector4::operator float*(){
	return((float*)this);
}