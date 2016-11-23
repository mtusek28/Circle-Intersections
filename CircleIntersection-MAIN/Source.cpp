#include <iostream>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535897

/*

TODO:
Need to calculate the intersections of a circle by using the
geometrical algorithm here --> (http://stackoverflow.com/questions/3349125/circle-circle-intersection-points)

Possibly implement better debug information to allow for better calls
and cleaner code to methods

*/

//Creating a class of a point that allows distances and certain properties easier to access and understand

class Point {
protected:
	double x;
	double y;

public:
	//Function that is essentialy a constructor... :-)
	void setObjectData(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	double getDistance(Point point)
	{
		return sqrt(pow((point.getX() - this->x), 2) + pow((point.getY() - this->y), 2));
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}
};

//Creating the class of a triangle with the general properties of a circle with one exception
//This class is different because it uses the prior class Point and uses the points from the algorithm...
//I'm smart :^)
class Triangle
{
	//General properties
protected:
	Point p0, p1, p2;
	double area;
	double height;

public:
	Point getP0()
	{
		return p0;
	}

	Point getP1()
	{
		return p1;
	}

	Point getP2()
	{
		return p2;
	}

	double getArea()
	{
		return area;
	}

	double getHeight()
	{
		return height;
	}

	//Woot constructor!
	void setObjectData(Point p0, Point p1, Point p2)
	{

	}

};


//Creating the class of a circle with the general properties of a circle
class Circle {
	//Creating the implementable elements of the circle
protected:
	double area;
	double radius;
	double diameter;
	double h, k;

	Point center;

	//Defining the methods such as getters and setters
public:
	double getArea()
	{
		return ((2) * (PI) * (radius));
	}

	double getRadius()
	{
		return radius;
	}

	double getDiameter()
	{
		return (2 * radius);
	}

	double getH()
	{
		return h;
	}

	double getK()
	{
		return k;
	}

	double getDistance(Circle circle1)
	{
		return this->center.getDistance(circle1.center);
	}

	void setObjectData(double radius, double h, double k)
	{
		this->radius = radius;
		this->h = h;
		this->k = k;
		center.setObjectData(h, k);
	}

};

bool checkIntersection(double distance, double radius0, double radius1)
{
	double sumRadius = radius0 + radius1;

	if (distance > sumRadius)
	{
		std::cout << "No Solutions! Circles are seperate." << std::endl;
		return false;
	}

	else if (distance < abs(radius0 - radius1))
	{
		std::cout << "No Solutions! Circles contained within eachother." << std::endl;
		return false;
	}

	else if (distance == 0 && radius0 == radius1)
	{
		std::cout << "Infinite solutions! Cicles are the coincident." << std::endl;
		return false;
	}

	else
	{
		std::cout << "There is intersections!" << std::endl;
		return true;
	}

}

void getIntersections(Circle circle0, Circle circle1)
{
	Point intersection0;
	Point intersection1;

	Point elements0;
	Point elements1;
	Point elements2;

	double radius0;
	double radius1;

	double a;
	
	double h;
	
	double distance;
	
	double x0;
	double y0;
	
	double x1;
	double y1;

	double x2;
	double y2;

	double x3;
	double y3;

	/* From http://stackoverflow.com/questions/3349125/circle-circle-intersection-points,
	Equation(s) -->
	a = (r0^2 - r1^2 + d^2 ) / (2d)

	h^2 = r0^2 - a^2

	x3 = x2 +- h ( y1 - y0 ) / d

	y3 = y2 -+ h ( x1 - x0 ) / d
	*/

	distance = (circle0.getDistance(circle1));

	radius0 = circle0.getRadius();
	radius1 = circle1.getRadius();

	a = ((pow(radius0, 2)) - (pow(radius1, 2)) + (pow(distance, 2))) / (2 * distance);

	h = sqrt((pow(radius0, 2) - pow(a, 2)));

	x0 = circle0.getH();
	y0 = circle0.getK();

	elements0.setObjectData(x0, y0);

	x1 = circle1.getH();
	y1 = circle1.getK();

	elements1.setObjectData(x1, y1);

	x2 = (x0 + (a * (x1 - x0) / distance));
	y2 = (y0 + (a * (y1 - y0) / distance));

	elements2.setObjectData(x2, y2);

	x3 = (x2 + h*(y1 - y0) / distance);
	y3 = (y2 - h*(x1 - x0) / distance);

	intersection0.setObjectData(x3, y3);

	std::cout << std::endl << "Intersection0 X: " << intersection0.getX() << std::endl;
	std::cout << "Intersection0 Y: " << intersection0.getY() << std::endl;
	
	x3 = (x2 - h*(y1 - y0) / distance);
	y3 = (y2 + h*(x1 - x0) / distance);

	intersection1.setObjectData(x3, y3);

	std::cout << std::endl << "Intersection1 X: " << intersection1.getX() << std::endl;
	std::cout << "Intersection1 Y: " << intersection1.getY() << std::endl;

}

/*

Plan --

Goal:
Find the intersections of two circles.

Method(s):
So far what I think I'm going to do is generate the circles and their
properties. With that information I will use the algorithm(s) that I found
on Stack overflow in this case (http://stackoverflow.com/questions/3349125/circle-circle-intersection-points)

Execution:

Generate the circles and use methods to access those properties and manipulate them
in the manner of the algorithm. There is going to be debug information aftwards using
cout.

*/

int main()
{
	Circle circle0;
	Circle circle1;

	double radius0;
	double h0;
	double k0;

	double radius1;
	double h1;
	double k1;

	std::cout << "Input Circle #0 -> Radius: " << std::endl;
	std::cin >> radius0;
	std::cout << "Input Circle #0 -> H: " << std::endl;
	std::cin >> h0;
	std::cout << "Input Circle #0 -> K: " << std::endl;
	std::cin >> k0;

	std::cout << "Input Circle #1 -> Radius: " << std::endl;
	std::cin >> radius1;
	std::cout << "Input Circle #1 -> H: " << std::endl;
	std::cin >> h1;
	std::cout << "Input Circle #1 -> K: " << std::endl;
	std::cin >> k1;

	getchar();

	circle0.setObjectData(radius0, h0, k0);
	circle1.setObjectData(radius1, h1, k1);
	
	Point point0;
	Point point1;

	point0.setObjectData(circle0.getH(), circle0.getK());
	point1.setObjectData(circle1.getH(), circle1.getK());

	if (checkIntersection(point0.getDistance(point1), circle0.getRadius(), circle1.getRadius()))
	{
		getIntersections(circle0, circle1);

	}
	getchar();

	return 0;

	/*

	Debug information, using the std output library.

	*/

	// std::cout << "Circle 0 -> Radius: " << circle0.getRadius() << std::endl;
	// std::cout << "Circle 0 -> Diameter: " << circle0.getDiameter() << std::endl;
	// std::cout << "Circle 0 -> Area " << circle0.getArea() << std::endl;
	// std::cout << "Circle 0 -> H: " << circle0.getH() << std::endl;
	// std::cout << "Circle 0 -> K: " << circle0.getK() << std::endl;
	//
	// std::cout << "Circle 1 -> Radius: " << circle1.getRadius() << std::endl;
	// std::cout << "Circle 1 -> Diameter: " << circle1.getDiameter() << std::endl;
	// std::cout << "Circle 1 -> Area " << circle1.getArea() << std::endl;
	// std::cout << "Circle 1 -> H: " << circle1.getH() << std::endl;
	// std::cout << "Circle 1 -> K: " << circle1.getK() << std::endl;
	//
	// std::cout << "Point 0 -> X: " << point0.getX() << std::endl;
	// std::cout << "Point 0 -> Y: " << point0.getY() << std::endl;
	//
	// std::cout << "Point 1 -> X: " << point1.getX() << std::endl;
	// std::cout << "Point 1 -> Y: " << point1.getY() << std::endl;
	//
	// std::cout << "Distance from -> Point 0 - Point 1: " << point0.getDistance(point1) << std::endl

}
