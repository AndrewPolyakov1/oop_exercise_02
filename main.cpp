#define _USE_MATH_DEFINES
//M_PI
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include "Angle.hpp"

int main()
{
    Angle alpha;
    Angle beta;
    alpha = 15.13_angle;
    beta = 1.360_angle;
    Angle tmp = alpha / 10;
    printf("%d \' %d  %lf\n", tmp.getDeg(),tmp.getMin(), alpha.sin());
    return 0;
}