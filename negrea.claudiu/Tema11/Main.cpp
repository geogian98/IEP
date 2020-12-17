#include "src/Point.hpp"
#include "src/Triangle.hpp"
#include "src/Circle.hpp"
#include "src/Square.hpp"
#include <iostream>
#include <math.h>

template <class Figure> float slope( Figure f){
	float x1 = f.getVertice(0).getX();
	float y1 = f.getVertice(0).getY();
	float x2 = f.getVertice(1).getX();
	float y2 = f.getVertice(1).getY();
	return (y2-y1) / (x2-x1);
}

template<class Figure, class Circle> bool intersect( Figure f, Circle c){
	float c_radius = c.getRadius();
	float c_x = c.getOrigin().getX();
	float c_y = c.getOrigin().getY();
	
	Point * points = f.getVertices();
	for(size_t i = 0; i < f.getNoEdges(); i++){
		float x = f.getVertice(i).getX();
		float y = f.getVertice(i).getY();
		
		float d = sqrt( pow(c_x -x, 2) + pow(c_y - y, 2));
		if ( d <= c_radius)
			return true;
		}
	return false;		


}



int main(){

	Point p1 = Point(5, 5);
	p1.toString();
	p1.setX(10);
	p1.setY(10);
	p1.toString();

	Point a = Point(0, 5);
	Point b = Point(5, 0);
	Point c = Point(0, 0);
	
	Triangle t1 = Triangle( a, b ,c  );
	std::cout << "Triangle perimeter : " << t1.perimeter() << "\n";
	
	Circle* c1 = Circle::createCircle( Point(0, 0), 10);
	std::cout << "Circle circumference : " << c1->perimeter() << "\n";
	
	try{
		Circle* c2 = Circle::createCircle( Point(0, 0), 5);
		std::cout << "Circle circumference : " << c2->perimeter() << "\n";
	}
	catch(int i){
		std::cout << "Error!! Only one circle is allowed! \n";
	}
	
	std::cout << "Triangle slope: " << slope(t1) << "\n";
	
	// Square( Point bottom left, length of the edges)
	Square s1 = Square( Point(11, 11), 4 );
	std::cout << "Square perimeter : " << s1.perimeter() << "\n";
	
	std::cout << "Circle and triangle intersect ?  " << intersect(t1, *c1) << "\n";
	std::cout << "Circle and square intersect ?  " << intersect(s1, *c1) << "\n";
	return 0;
}
