#include"Vector3.h"
#include<math.h>
#include<iostream>

Vector3::Vector3(): x(5.0f), y(5.0f), z(5.0f){

}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z){

}

Vector3::~Vector3(){

}

//prints this vector
void Vector3::print(){
	std::cout << this->x << " " << this->y << " " << this->z << std::endl;
}

//returns the magnitude of this vector
float Vector3::magnitude(){
	float tmp = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2);
	return sqrt(tmp);
}

//returns this vector, normalised
Vector3 Vector3::normalise(){
	float tmp = this->magnitude();
	this->x /= tmp;
	this->y /= tmp;
	this->z /= tmp;
	return *this;
}

//returns the normalisation of this vector, stores in a different vector
Vector3 Vector3::normalise(Vector3 &other){
	float tmp = this->magnitude();
	other.x = this->x / tmp;
	other.y = this->y / tmp;
	other.z = this->z / tmp;
	return other;
}

//returns the dot product of this and another vector
float Vector3::dot(Vector3 &other){
	float dotProd = (this -> x * other.x) + (this -> y * other.y) + (this -> z * other.z);
	return dotProd;
}

//returns the cross product of this and another vector
Vector3 Vector3::cross(Vector3 &other){
	Vector3 tmp;
	tmp.x = (this->y * other.z) - (this -> z * other.y);
	tmp.y = (this -> z * other.x) -(this -> x * other.z);
	tmp.z = (this -> x * other.y) - (this -> y * other.x);
	return tmp;

}

//returns the angle between this and another vector
float Vector3::angle(Vector3 &other){
	float angle = acos(this -> dot(other) / (this -> magnitude() * other.magnitude()));
	return angle;
}

Vector3 Vector3::operator+(Vector3 &other){
	Vector3 tmp(this -> x + other.x, this -> y + other.y, this -> z + other.z);
	return tmp;
}

Vector3 Vector3::operator-(Vector3 &other){
	Vector3 tmp(this -> x - other.x, this -> y - other.y, this -> z - other.z);
	return tmp;
}

Vector3 Vector3::operator*(float scale){
	Vector3 tmp(this -> x * scale, this -> y * scale, this -> z * scale);
	return tmp;
}

Vector3 operator*(float scale, Vector3 other){
	Vector3 tmp(other.x * scale, other.y * scale, other.z * scale);
	return tmp;
}

Vector3 Vector3::operator/(float scale){
	Vector3 tmp(this -> x / scale, this -> y / scale, this -> z / scale);
	return tmp;
}

Vector3 Vector3::operator*=(float scale){
	this -> x *= scale;
	this -> y *= scale;
	this -> z *= scale;
	return *this;
}

Vector3 Vector3::operator/=(float scale){
	this -> x /= scale;
	this -> y /= scale;
	this -> z /= scale;
	return *this;
}

Vector3 Vector3::operator+=(Vector3 &other){
	this -> x += other.x;
	this -> y += other.y;
	this -> z += other.z;
	return *this;
}

Vector3 Vector3::operator-=(Vector3 &other){
	this -> x -= other.x;
	this -> y -= other.y;
	this -> z -= other.z;
	return *this;
}

//returns a pointer to the vector
Vector3::operator float*(){
	return((float*)this);
}