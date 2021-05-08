#pragma once
using namespace std;
#include <string>

class Shape {
public:
	virtual void Scale(double scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape();
};

class Shape2D :virtual public Shape {
public:
	virtual double Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};
class Shape3D :virtual public Shape {
public:
	virtual double Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};
class Square : virtual public Shape2D {
public:
	string GetName2D() const;
	void Scale(double scaleFactor);
	void Display() const;
	double Area() const;
	double _sideLength;
	Square();
	Square(double sideLength);
};
class Triangle : virtual public Shape2D {
public:

	void Scale(double scaleFactor);
	void Display() const;
	string GetName2D() const;
	double Area() const;
	double _base;
	double _height;
	Triangle();
	Triangle(double base, double height);
};
class Circle : virtual public Shape2D {
public:
	void Scale(double scaleFactor);
	void Display() const;
	string GetName2D() const;
	double Area() const;
	double _radius;
	Circle();
	Circle(double radius);
};
class TriangularPyramid : private Triangle, public Shape3D {
public:
	string GetName3D() const;
	void Scale(double scaleFactor);
	void Display() const;
	double _height;
	double _tBase;
	double _tHeight;
	double Volume() const;
	TriangularPyramid();
	TriangularPyramid(double tBase, double tHeight, double height);
};
class Cylinder : private Circle, public Shape3D {
public:
	string GetName3D() const;
	void Display() const;
	void Scale(double scaleFactor);
	double _height;
	double _cRadius;
	double Volume() const;
	Cylinder();
	Cylinder(double height, double radius);
};
class Sphere : private Circle, public Shape3D {
public:
	string GetName3D() const;
	void Display() const;
	void Scale(double scaleFactor);
	double _cRadius;
	double Volume() const;
	Sphere();
	Sphere(double radius);
};