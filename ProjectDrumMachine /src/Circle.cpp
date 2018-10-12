#include "Circle.h"
#define PI 3.14159265359

Circle::Circle()
{

}
Circle::Circle(float x_in, float y_in, float r_in)
{
   x=x_in;
   y=y_in;
   r=r_in;
}

void Circle::setCircle(float x_in, float y_in, float r_in)
{
    x=x_in;
    y=y_in;
    r=r_in;
}

void Circle::setRand(int xmin, int xmax, int ymin, int ymax, int rmin, int rmax)
{
    x=(float)xmin+rand()%xmax-xmin+1;
    y=(float)ymin+rand()%ymax-ymin+1;
    r=(float)rmin+rand()%rmax-rmin+1;
}

float Circle::getArea()
{
    float result;
    result = PI * r*r;
    return(result);
}

float Circle::getCircumference()
{
    float result;
    result = 2 * PI * r;
    return(result);
}

float Circle::getDistBetweenCenters(Circle circle_in)
{
    float result;
    result = sqrt((x-circle_in.x)*(x-circle_in.x)+(y-circle_in.y)*(y-circle_in.y));
    return(result);
}

bool Circle::intersect(Circle circle_in)
{
    bool result;
    float distance;
    float sumRadius;
    distance = getDistBetweenCenters(circle_in);
    sumRadius = r + circle_in.r;
    if (sumRadius > distance) result=1;
    else result=0;
    return(result);
}



void Circle::print()
{
 printf("\nCircle--------------");
 printf("\nx = %f",x);
 printf("\ny = %f",y);
 printf("\nr = %f",r);
}

Circle::~Circle()
{
    //dtor
}
