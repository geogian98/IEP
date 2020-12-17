#ifndef POINT_HPP
#define POINT_HPP

class Point{
	
	private: 
		float x, y;
		
	public: Point();
		Point(float x, float y);
		float getX();
		float getY();
		void setX(float nx);
		void setY(float ny);
		void toString();
};

#endif
