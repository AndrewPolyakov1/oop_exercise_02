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
    alpha = 721.121_angle;
    alpha.setAn(-365, 500);
    std::cout << alpha.getDeg() << "\'" <<alpha.getMin() << "\'\'" << std::endl;
    alpha.Reduce();
    std::cout << "#" << alpha.getDeg() << "\'" <<alpha.getMin() << "\'\'" << std::endl;
    return 0;
}