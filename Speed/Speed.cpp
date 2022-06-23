#include "Speed.hpp"

using namespace unit_converter;

Speed::Speed(VUCmode mode, double R, double lim)
{
    this->mode=mode;
    this->vel=0.f;
    this->R=R;
    this->lim=lim;
}

void Speed::change(VUCmode mode)
{
    this->mode = mode;
}

/*
w[rad/s]=2*Pi*n[rps]
n[rps]=w[rad/s]/2*Pi
V[m/s]=R[m]*w[rad/s]
w[rad/s]=V[m/s]/R[m]
*/
Speed& Speed::operator = (double val)
{
    switch(mode)
    {
        case V_rps:this->vel=val / (2 * M_PI * this->R );break;
        case W_rps:this->vel=val / 2 * M_PI;break;
        case rps_V:this->vel=2 * M_PI * R * val;break; //v[m/s] = r[m] * w[rad/s]
        case rps_W:this->vel=2 * M_PI * val;break;     //w[rad/s] = 2 * Pi * n[rps]
    }
    return *this;
}

Speed::operator double ()
{
    if(fabs(this->vel) < this->lim || this->lim == 0.0)
        return this->vel;
    else
        return this->lim * (this->vel/fabs(this->vel));
}