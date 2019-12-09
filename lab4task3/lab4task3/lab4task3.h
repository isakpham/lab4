#pragma once
#ifndef lab4task3
#define lab4task3

using namespace std;

class Point2D {
public:
	float x, y;
	Point2D(float xValue, float yValue);
	Point2D(Point2D& o);
	Point2D();
	string toString();
	void newPoint(float xValue, float yValue);
	float distance(Point2D point2);
};

class Polyline {
public:
	Point2D* arr;
	int numberOfElements;
	Polyline(int length);
	void removeLastPoint();
	void addPoint(float xValue, float yValue);
	float PolylineIndexX(int index);
	float PolylineIndexY(int index);
	int numberOfPoints();
	void combinePoints(int index1, int index2);
	float totalLenght();
	void printPolyLine();
	~Polyline();
};

#endif // !lab4task3
