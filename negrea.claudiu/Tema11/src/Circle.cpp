#include "Circle.hpp"
#include "math.h"

Circle* Circle::c = nullptr;

Circle::Circle(Point o, float r):origin(o), radius(r){};

Circle* Circle::createCircle(Point o, float r){
	if (c)
		throw 99;
	else
		c = new Circle(o, r);
	return c;
}

float Circle::getRadius(){
	return radius;
	}
Point Circle::getOrigin(){
	return origin;
	}
float Circle::perimeter(){
	return 2* asin(1.0) * 2 * radius;
	}
