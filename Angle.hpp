#pragma once
#include <string>
#define RAD (M_PI / 180)
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
    double toRad()
    {
        Angle tmp;
        tmp.setAn(this->degree,this->minute);
        tmp.Reduce();
        printf("%d  %d  %lf  \n" ,tmp.degree ,tmp.minute, (double(tmp.degree) + (double(tmp.minute) / 60)) );
        return ((double(tmp.degree) + (double(tmp.minute) / 60)) * double(RAD));
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


    double sin()
    {
        Angle tmp;
        tmp.setAn(this->degree,this->minute);
        return std::sin(tmp.toRad());
    }

    double cos()
    {
        Angle tmp;
        tmp.setAn(this->degree,this->minute);
        return std::cos(tmp.toRad());
    }

    double tan()
    {
        Angle tmp;
        tmp.setAn(this->degree,this->minute);
        return (std::sin(tmp.toRad()) / std::cos(tmp.toRad()));
    }
//operators overloading
        Angle operator+(const Angle& right)
        {
            Angle ans;
            ans.setAn((this->degree + right.degree),(this->minute + right.minute));
            return ans;
        }
        Angle operator-(const Angle& right)
        {
            Angle ans;
            int tmp_deg,tmp_min;
            tmp_deg = this->degree - right.degree;
            tmp_min = this->minute - right.minute;
            while(tmp_min < 0)
            {
                tmp_min += 60;
                tmp_deg -= 1;
            }
            ans.setAn(tmp_deg, tmp_min);
            return ans;
        }
        //angle times integer
        Angle operator*(const int mult)
        {
            Angle ans;
            ans.degree = this->degree * mult;
            ans.minute = this->minute * mult;
            return ans;
        }
        double operator/(const Angle& right)
        {
            double ans;
            ans = ((this->degree * 60) + double(this->minute))/((right.degree * 60) + double(right.minute));
            return ans;
        }
        Angle operator/(const int divider)
        {
            Angle ans;
            ans.degree = 0;
            ans.minute = floor((this->degree * 60) + double(this->minute) / divider);
            return ans;
        }
};
//Getting value in <degrees>.<minutes> format
Angle operator ""_angle(const char* angle)
{
    Angle phi;
    //states to control changes
    int state = 0;
    //temporary strings to store values
    std::string tmp_deg, tmp_min;
    //reading input and convert to value
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
