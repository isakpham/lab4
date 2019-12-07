#pragma once
#ifndef lab4Task2
#define lab4Task2

class Point2D {
public:
	float x, y;
	Point2D(float xValue, float yValue);
	Point2D(Point2D& o);
	void newPoint(float xValue, float yValue);
	double distance(Point2D point2);

};


#endif // !lab4Task2
