#include "Point.hpp"
#include <iostream>

//constructors
Point::Point():x(0), y(0){};
Point::Point(float x, float y) : x(x), y(y){};

//getters
float Point::getX(){ return x; }
float Point::getY(){ return y; }

//setters
void Point::setX(float nx){ x = nx; }
void Point::setY(float ny){ y = ny; }

//toString

void Point::toString(){
	std::cout << "Point("<< x << ", " << y << ") \n" ;
	}

