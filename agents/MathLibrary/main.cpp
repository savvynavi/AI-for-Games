#include<iostream>
#include"Vector3.h"
#include"Vector2.h"
using namespace std;

int main(){
	Vector2 v1(-8.0f, 4.0f);
	Vector2 v2(10.0f, 20.0f);
	float dotProductResult = v1.dotProduct(v2);
	float crossProductResult = v1.crossProduct(v2);
	float angleResult = v1.angle(v2);
	cout << "Dot product v1.v2: " << dotProductResult << endl;
	cout << "Cross product v1xv2: " << crossProductResult << endl;
	cout << "Angle v1 v2: " << angleResult << endl;

	system("pause");
	return 0;
}