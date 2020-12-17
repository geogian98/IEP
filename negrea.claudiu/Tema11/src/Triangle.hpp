#include "Figure.hpp"
#include "Point.hpp"

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle: public Figure{
	private:
		static const int  noPoints = 3;
		Point points[noPoints];
	public:
		Triangle(Point a, Point b, Point c);
		int getNoEdges();
		float perimeter();
		Point getVertice(int i);
		Point* getVertices();
};

#endif
