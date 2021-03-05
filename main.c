#include <stdio.h>
#include <math.h>

double getCoordinate(char plane, int num);
double sidelength(double x1, double x2, double y1, double y2);
double getPerimeter(double side1, double side2, double side3);
double getCenter(double p1, double p2, double p3, double side1, double side2, double side3, double perimeter);

int main()
{
	//variable declarations
	double xcoord1;
	double xcoord2;
	double xcoord3;
	double ycoord1;
	double ycoord2;
	double ycoord3;
	double sideLengthA; //The length from points 1 to 2
	double sideLengthB; //The length from points 2 to 3
	double sideLengthC; //The length from points 3 to 1
	double perimeter;
	double centerPointx;
	double centerPointy;
	double angleA; //The angle across from side A
	double angleB; //The angle across from side B 
	double angleC; //The angle across from side C

  //inputs
  xcoord1 = getCoordinate("X", 1);
	ycoord1 = getCoordinate("Y", 1);
	xcoord2 = getCoordinate("X", 2);
	ycoord2 = getCoordinate("Y", 2);
	xcoord3 = getCoordinate("X", 3);
	ycoord3 = getCoordinate("Y", 3);

	//calculations:
	//calculating sideLengths
  sideLengthA = sideLength(xcoord1, xcoord2, ycoord1, ycoord2);
	sideLengthB = sideLength(xcoord2, xcoord3, ycoord2, ycoord3);
	sideLengthC = sideLength(xcoord3, xcoord1, ycoord3, ycoord1);

	//calculating center of the triangle
  perimeter = getPerimeter(sideLengthA, sideLengthB, sideLengthC);
  centerPointx = getCenter(xcoord1, xcoord2, xcoord3, sideLengthA, sideLengthB, sideLengthC, perimeter);
	centerPointy = getCenter(ycoord1, ycoord2, ycoord3, sideLengthA, sideLengthB, sideLengthC, perimeter);

	//calculating angles
  

	//calculating the lines perpendicular to sides from center

	//calculating the areas of the quadrilaterals

	return 0;
}

double getCoordinate(char plane, int num)
{
  double point;
	printf("Enter %c coordinate #%i ->", plane, num); 
	scanf("%lf", &point);
	return point;
}

double sidelength(double x1, double x2, double y1, double y2)
{
  double distance;
  double xdiff;
  double ydiff;
  xdiff = fabs(x1 - x2);
  ydiff = fabs(y1 - y2);
  distance = sqrt(pow(xdiff, 2) + pow(ydiff, 2));
  return (distance);
}

double getPerimeter(double side1, double side2, double side3)
{
  double perimeter;
	perimeter = side1 + side2 + side3;
	return perimeter;
}

double getCenter(double p1, double p2, double p3, double side1, double side2, double side3, double perimeter)
{
	double pCenter;
	pCenter = p1 * side1 + p2 * side2 + p3 * side3;
	pCenter /= perimeter;
	return pCenter;
}

double getAngle(double side1, double side2, double sideAngle)
{
	double angle;
	angle = pow(side1, 2) + pow(side2, 2) - pow(sideAngle, 2);
	angle /= (2 * side1 * side2);
	angle = acos(angle);
  angle *= (180 / M_PI);
	return angle;
}
