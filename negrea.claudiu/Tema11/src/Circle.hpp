#include "Point.hpp"
#include "Figure.hpp"

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle{
	private:
		Point origin;
		float radius;
		static Circle * c;
		Circle(Point o, float r);
		void operator=(Circle &);

	public:
		static Circle* createCircle(Point o, float r);
		float getRadius();
		Point getOrigin();
		float perimeter();
};

#endif
