#ifndef CIRCLE_H
#define CIRCLE_H
#define N_MAX  10000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

class Circle
{
    public:
        float x;
        float y;
        float r;


        Circle();
        Circle(float x_in, float y_in, float r_in);
        void setCircle(float x_in, float y_in, float r_in);
        void setRand(int xmin, int xmax, int ymin, int ymax, int rmin, int rmax);
        float getArea();
        float getCircumference();
        float getDistBetweenCenters(Circle circle_in);
        bool intersect(Circle circle_in);
        int getNumIntersects(Circle in_circle);
        void print();

        virtual ~Circle();

    protected:

    private:
};

#endif // CIRCLE_H
