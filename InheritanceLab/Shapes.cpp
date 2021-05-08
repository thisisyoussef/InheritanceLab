#include <iostream>
#include <string>
#include "Shapes.h"
#define PI 3.14159f
using namespace std;
Shape::~Shape() {}
void Shape2D::ShowArea() const {
	cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
}
bool Shape2D::operator<(const Shape2D& rhs) const {
	if (this->Area() < rhs.Area()) {
		return true;
	}
	else { return false; }
}
bool Shape2D::operator>(const Shape2D& rhs) const {
	if (this->Area() > rhs.Area()) {
		return true;
	}
	else { return false; }
}
bool Shape2D::operator==(const Shape2D& rhs) const {
	if (this->Area() == rhs.Area()) {
		return true;
	}
	else { return false; }
}
void Shape3D::ShowVolume() const {
	cout << "The volume of the " << GetName3D() << " is: " << Volume() << endl;

}
bool Shape3D::operator<(const Shape3D& rhs) const {
	if (this->Volume() < rhs.Volume()) {
		return true;
	}
	else { return false; }
}
bool Shape3D::operator>(const Shape3D& rhs) const {
	if (this->Volume() > rhs.Volume()) {
		return true;
	}
	else { return false; }
}
bool Shape3D::operator==(const Shape3D& rhs) const {
	if (this->Volume() == rhs.Volume()) {
		return true;
	}
	else { return false; }
}
double Square::Area() const {
	return _sideLength * _sideLength;
}
Square::Square() {
	_sideLength = 0;
}
Square::Square(double sideLength) {
	_sideLength = sideLength;
}
string Square::GetName2D() const {
	return "Square";
}
void Square::Scale(double scaleFactor) {
	_sideLength *= scaleFactor;
}


void Square::Display() const {
	cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
	cout << "Length of a side: " << _sideLength << endl;
}
void Circle::Display() const {
	cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
	cout << "Radius: " << _radius << endl;
}
void Triangle::Display() const {
	cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
	cout << "Base: " << _base << endl;
	cout << "Height: " << _height << endl;

}
double Triangle::Area() const {
	return 0.5 * _base * _height;
}
Triangle::Triangle() {
	_base = 0;
	_height = 0;
}
Triangle::Triangle(double base, double height) {
	_base = base;
	_height = height;
}
string Triangle::GetName2D() const {
	return "Triangle";
}
void Triangle::Scale(double scaleFactor) {
	_base *= scaleFactor;
	_height *= scaleFactor;
}
double Circle::Area() const {
	return PI * _radius * _radius;
}
Circle::Circle() {
	_radius = 0;
}
Circle::Circle(double radius) {
	_radius = radius;
}
string Circle::GetName2D() const {
	return "Circle";
}
void Circle::Scale(double scaleFactor) {
	_radius *= scaleFactor;
}
TriangularPyramid::TriangularPyramid() {
	_tBase = 0;
	_tHeight = 0;
	_height = 0;
	Triangle(_tBase, _tHeight);

}
TriangularPyramid::TriangularPyramid(double tBase, double tHeight, double height) {
	_tBase = tBase;
	_tHeight = tHeight;
	_height = height;
	Triangle(_tBase, _tHeight);
}
void TriangularPyramid::Scale(double scaleFactor) {
	_tBase *= scaleFactor;
	_tHeight *= scaleFactor;
	_height *= scaleFactor;
	Triangle(_tBase, _tHeight);
}
double TriangularPyramid::Volume() const {
	return Area() * _height * (1 / 3);
}
void TriangularPyramid::Display() const {
	cout << "The volume of the " << GetName3D() << " is: " << Volume() << endl;
	cout << "The height is: " << _height << endl;
	cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
	cout << "Base: " << _tBase << endl;
	cout << "Height: " << _tHeight << endl;
}
string TriangularPyramid::GetName3D() const {
	return "TriangularPyramid";
}

Cylinder::Cylinder() {
	_cRadius = 0;
	_height = 0;
	Circle();

}
Cylinder::Cylinder(double height, double radius) {
	_cRadius = radius;
	_height = height;
	_radius = _cRadius;
}
void Cylinder::Scale(double scaleFactor) {
	_cRadius *= scaleFactor;
	_height *= scaleFactor;
	_radius = _cRadius;
}
double Cylinder::Volume() const {
	return Area() * _height;
}
void Cylinder::Display() const {
	cout << "The volume of the " << GetName3D() << " is: " << Volume() << endl;
	cout << "The height is: " << _height << endl;
	cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
	cout << "Radius: " << _cRadius << endl;
}
string Cylinder::GetName3D() const {
	return "Cylinder";
}	 Sphere::Sphere() {
	_cRadius = 0;
	Circle();

}
Sphere::Sphere(double radius) {
	_cRadius = radius;
	_radius = _cRadius;
}
void Sphere::Scale(double scaleFactor) {
	_cRadius *= scaleFactor;
	_radius = _cRadius;
}
double Sphere::Volume() const {
	return PI * _radius * _radius *_radius * (4 / 3);
}
void Sphere::Display() const {
	cout << "The volume of the " << GetName3D() << " is: " << Volume() << endl;
	cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
	cout << "Radius: " << _cRadius << endl;
}
string Sphere::GetName3D() const {
	return "Sphere";
}