#pragma once

class Angle
{
private:
    int degree;
    int minute;
public:
    Angle(){}
    ~Angle(){}

    void setAn(int Deg, int Min)
    {
        degree = Deg;
        minute = Min;
    }

    int GetDeg()
    {
        return degree;
    }

    int getMin()
    {
        return minute;
    }
};

