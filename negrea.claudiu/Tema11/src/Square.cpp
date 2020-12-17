#include "Square.hpp"

#include <iostream>
#include <math.h>


//constructor
Square::Square(Point a, int length){

	points[0] = a;
	float x = a.getX();
	float y = a.getY();

	points[1] = Point(x+length, y); 
	points[2] = Point(x, y+length); 
	points[3] = Point(x+length, y+length); 
}

int Square::getNoEdges(){
	return noPoints;
}

float Square::perimeter(){
	float l =  sqrt( pow(points[0].getX() - points[1].getX(), 2) +
			 pow(points[0].getY() - points[1].getY(), 2) );
	return 4 * l ;		 
}

Point Square::getVertice(int i){
	return points[i];
	}
Point* Square::getVertices(){
	return points;
}	

