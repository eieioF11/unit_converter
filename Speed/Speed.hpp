/*
速度変換用ライブラリ
対応してる変換
[m/s]->[rps]
[rad/s]->[rps]
[rps]->[m/s]
[rps]->[rad/s]

Ex [m/s]->[rps]
    #define WHEEL_R 0.03 //[m]
    unit_converter::Speed V(unit_converter::V_rps, WHEEL_R);
    V = [m/s]の値を代入;
    double vel=V;//velに[rps]に変換された値が代入される
*/
#ifndef SPEED_H_
#define SPEED_H_
#include <math.h>

#if defined __cplusplus
extern "C" {
#endif

namespace unit_converter
{

enum VUCmode
{
    V_rps,//m/s -> rps
    W_rps,//rad/s -> rps
    rps_V,//rps -> m/s
    rps_W,//rps -> rad/s
};

class Speed
{
    private:
        VUCmode mode;
        double vel;
        double R;
        double lim;
    public:
        Speed(VUCmode mode, double R, double lim = 0.0); // R[m]
        void change(VUCmode mode);//変換モードの変更
        Speed& operator = (double val);//val [m/s] or [rad/s] or [rps]
        operator double ();
};

}

#if defined __cplusplus
}
#endif

#endif