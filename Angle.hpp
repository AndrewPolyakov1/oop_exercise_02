#pragma once
#include <string>
class Angle
{
private:
    int degree;
    int minute;
public:
    Angle(){}
    ~Angle(){}
    Angle(int Deg, int Min)
    {
        this->degree = Deg;
        this->minute = Min;
    }
    void setAn(int Deg, int Min)
    {
        this->degree = Deg;
        this->minute = Min;
    }

    int getDeg()
    {
        return degree;
    }

    int getMin()
    {
        return minute;
    }

    void Reduce()
    {
        int state = 0;
        do{
        state = 0;
        if(this->degree >= 360)
        {
            this->degree -= 360;
            state ++;
        }
        if(this->degree <= 0)
        {
            this->degree += 360;
            state ++;
        }
        if(this->minute >= 60)
        {
            this->minute -= 60;
            this->degree += 1;
            state ++;
        }
        }while(state > 0);
    }
};

Angle operator ""_angle(const char* angle)
{
    Angle phi;
    int state = 0;
    std::string tmp_deg, tmp_min;
    for(int i = 0; i < strlen(angle); i++)
    {
        if ((angle[i] == '.') || (angle[i] == ',')) state = 1;
        if((state == 0) && !((angle[i] == '.') || (angle[i] == ',')))
        {
            tmp_deg += angle[i];
        }
        if((state == 1) && !((angle[i] == '.') || (angle[i] == ',')))
        {
            tmp_min += angle[i];
        }
    }
    phi.setAn(std::stoi(tmp_deg,nullptr,10),std::stoi(tmp_min,nullptr,10));
    return phi;
}
