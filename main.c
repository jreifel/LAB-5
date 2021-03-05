#include <stdio.h>
#include <math.h>

double getCoordinate(char plane, int num);
double sidelength(double x1, double x2, double y1, double y2);
double getPerimeter(double side1, double side2, double side3);
double getCenter(double p1, double p2, double p3, double side1, double side2, double side3, double perimeter);
double getAngle(double side1, double side2, double sideAngle);
double getAngleRemainder(double angle);
double getCenterToSide(double toCenter, double angle);
double getQuadSide(double toCenter, double angle);
double getAreaQuad(double s, double side1, double side2, double side3, double side4);
void display(double AngleA, double AngleB, double AngleC, double AngleAMinutes, double AngleBMinutes, double AngleCMinutes, double AngleASeconds, double AngleBSeconds, double AngleCSeconds, double areaA, double areaB, double areaC);

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
  double angleAMin;
  double angleBMin;
  double angleCMin;
  double angleASec;
  double angleBSec;
  double angleCSec;
  double side1Center; //The distance from 1 to the Center
  double side2Center; //The distance from 2 to the Center
  double side2Center; //The distance from 2 to the Center
  double quad1Area; //The area of the quadrilateral connecting to point 1
  double quad2Area; //The area of the quadrilateral connecting to point 2
  double quad3Area; //The area of the quadrilateral connecting to point 3
  double quad1Side; //The side of quad 1 on the triangle
  double quad2Side; //The side of quad 2 on the triangle
  double quad3Side; //The side of quad 3 on the triangle

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
  angleA = getAngle(sideLengthB, sideLengthC, sideLengthA);
  angleB = getAngle(sideLengthA, sideLengthB, sideLengthB);
  angleC = getAngle(sideLengthA, sideLengthB, sideLengthC);
  angleAMin = getAngleRemainder(angleA);
  angleBMin = getAngleRemainder(angleB);
  angleCMin = getAngleRemainder(angleC);
  angleASec = getAngleRemainder(angleAMin);
  angleBSec = getAngleRemainder(angleBMin);
  angleCSec = getAngleRemainder(angleCMin);

  //calculating the lines perpendicular to sides from center
  side1Center = sideLength(xcoord1, centerPointx, ycoord1, centerPointy);
  side2Center = sideLength(xcoord2, centerPointx, ycoord2, centerPointy);
  side3Center = sideLength(xcoord3, centerPointx, ycoord3, centerPointy);
  side1CenterAngle = angleA / 2;
  side2CenterAngle = angleB / 2;
  side3CenterAngle = angleC / 2;
  radius = getCenterToSide(side1Center, side1CenterAngle);
  
  //calculating the areas of the quadrilaterals
  quad1Area = getAreaQuad(radius, radius, quad1Side, quad1Side);
  quad2Area = getAreaQuad(radius, radius, quad2Side, quad2Side);
  quad3Area = getAreaQuad(radius, radius, quad3Side, quad3Side);
  
  //outputting
  
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

double getAngleRemainder(double angle)
{
  double remainder;
  remainder = a - floor(a);
  remainder *= 60;
  return remainder;
}

double getCenterToSide(double toCenter, double angle)
{
  double centerToSide;
  angle *= M_PI / 180;
  centerToSide = toCenter * sin(angle);
  return centerToSide;
}

double getQuadSide(double toCenter, double angle)
{
  double quadSide;
  angle *= M_PI / 180;
  quadSide = toCenter * cos(angle);
  return quadSide;
}

double getAreaQuad(double s, double side1, double side2, double side3, double side4)
{
  double area;
  area = (s - side1) * (s - side2) * (s - side3) * (s - side4);
  area = sqrt(area);
  return area;
}

void display(double AngleA, double AngleB, double AngleC, double AngleAMinutes, double AngleBMinutes, double AngleCMinutes, double AngleASeconds, double AngleBSeconds, double AngleCSeconds, double areaA, double areaB, double areaC)
{
  double PrintAngleA;
  double PrintAngleB;
  double PrintAngleC;
  double PrintMinutesA;
  double PrintMinutesB;
  double PrintMinutesC;
  
  PrintAngleA = floor(AngleA);
  PrintAngleB = floor(AngleB);
  PrintAngleC = floor(AngleC);
  PrintMinutesA = floor(AngleAMinutes);
  PrintMinutesB = floor(AngleBMinutes);
  PrintMinutesC = floor(AngleCMinutes);
  
  printf("Internal triangle angle %.0lf° %.0lf' %.2lf\", %.0lf° %.0lf' %.2lf\", %.0lf° %.0lf' %.2lf\"", AngleA, PrintMinutesA, AngleASeconds, AngleB, PrintMinutesB, AngleBSeconds, AngleC, PrintMinutesC, AngleCSeconds);
  printf("Area of quadrilaterals: %.2lf, %.2lf, %.2lf", areaA, areaB, areaC);
  
  return (0);
}

