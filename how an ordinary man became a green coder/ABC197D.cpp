/*
AC
行列の一次変換

*/
#include<iostream>
#include<cmath>
using namespace std;
const double pi = 3.1415926535;

int main(){
    int N;
    cin>>N;
    double x0,y0,x2,y2;
    cin>>x0>>y0;
    cin>>x2>>y2;

    double centerx =(x0+x2)/2;
    double centery =(y0+y2)/2;

    double theta = 2*pi/N;

    double dx = x0-centerx;
    double dy = y0-centery;

    double ansx = dx*cos(theta)-dy*sin(theta)+centerx;
    double ansy = dx*sin(theta)+dy*cos(theta)+centery;
    
    printf("%.10f %.10f\n",ansx,ansy);

    return 0;

}
