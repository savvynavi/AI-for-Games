#include"Vector2.h"
#include<math.h>
#include<iostream>

Vector2::Vector2() :x(5.0f), y(5.0f){

}

Vector2::Vector2(float x, float y) : x(x), y(y){

}

Vector2::~Vector2(){

}

//prints this vector
void Vector2::print(){
	std::cout << this->x << " " << this->y << std::endl;
}

//returns the magnitude of this vector from origin
float Vector2::magnitude(){
	float tmp = pow(this->x, 2) + pow(this->y, 2);
	return sqrt(tmp);
}

//returns the magnitude of this vector to another vector
float Vector2::magnitude(Vector2 &other){
	float tmp = pow(other.x - this->x, 2) + pow(other.y - this->y, 2);
	return sqrt(tmp);
}

//returns this vector, normalised
Vector2 Vector2::normalise(){
	float tmp = this->magnitude();
	this->x /= tmp;
	this->y /= tmp;
	return *this;
}

//returns a copy of the normalised vector
Vector2 Vector2::normalise(Vector2 &other){
	float tmp = this->magnitude();
	other.x = this->x / tmp;
	other.y = this->y / tmp;
	return other;
}

//returns a vector of the dot product of 2 vectors
float Vector2::dot(Vector2 &other){
	float dotProd = (this->x * other.x) + (this->y * other.y);
	return dotProd;
}

//returns the cross product between 2 vector2's
float Vector2::cross(Vector2 &other){
	float dotProd = (this->x * other.y) - (this->y * other.x);
	return dotProd;
}

//returns the angle between 2 vectors
float Vector2::angle(Vector2 &other){
	float angle = acos(this->dot(other) / (this->magnitude() * other.magnitude()));
	return angle;
}

//takes in the end point and time, interpolates linearly
Vector2 Vector2::interpolation(const Vector2 &a, const Vector2 &b, float t){
	this->x = (1 - t) * a.x + (t * b.x);
	this->y = (1 - t) * a.y + (t * b.y);
	return *this;
}

Vector2 Vector2::operator+(Vector2 &other){
	Vector2 tmp(this->x + other.x, this->y + other.y);
	return tmp;
}

Vector2 Vector2::operator-(Vector2 &other){
	Vector2 tmp(this->x - other.x, this->y - other.y);
	return tmp;
}

Vector2 Vector2::operator*(float scale){
	Vector2 tmp(this->x * scale, this->y * scale);
	return tmp;
}

Vector2 operator*(float scale, Vector2 other){
	Vector2 tmp(other.x * scale, other.y * scale);
	return tmp;
}

Vector2 Vector2::operator/(float scale){
	Vector2 tmp(this->x / scale, this->y / scale);
	return tmp;
}

Vector2 Vector2::operator*=(float scale){
	this->x *= scale;
	this->y *= scale;
	return *this;
}

Vector2 Vector2::operator/=(float scale){
	this->x /= scale;
	this->y /= scale;
	return *this;
}

Vector2 Vector2::operator+=(Vector2 &other){
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2 Vector2::operator-=(Vector2 &other){
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

//returns a pointer to the vector
Vector2::operator float*(){
	return((float*)this);
}