#include "Triangle.hpp"
#include <iostream>
#include <math.h>


//constructor
Triangle::Triangle(Point a, Point b, Point c){
	points[0] = a;
	points[1] = b; 
	points[2] = c;
}

int Triangle::getNoEdges(){
	return noPoints;
}

float Triangle::perimeter(){
	float ab = sqrt( pow(points[0].getX() - points[1].getX(), 2) +
			 pow(points[0].getY() - points[1].getY(), 2) );
	float bc = sqrt( pow(points[1].getX() - points[2].getX(), 2) +
			 pow(points[1].getY() - points[2].getY(), 2) );
	float ca = sqrt( pow(points[2].getX() - points[0].getX(), 2) +
			 pow(points[2].getY() - points[0].getY(), 2) );
			 
	return ab + bc + ca;		 
}

Point Triangle::getVertice(int i){
	return points[i];
	}
Point* Triangle::getVertices(){
	return points;
}	

