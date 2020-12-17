#include "Figure.hpp"
#include "Point.hpp"

#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square: public Figure{
	private:
		static const int  noPoints = 4;
		Point points[noPoints];
	public:
		Square(Point a, int length);
		int getNoEdges();
		float perimeter();
		Point getVertice(int i);
		Point* getVertices();
};

#endif
