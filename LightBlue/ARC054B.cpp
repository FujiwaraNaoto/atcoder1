/*
微分　
ただし,場合分けが必要
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int main(){
    double P;
    cin>>P;

    double x = max(0.0, -1.5/log(2) *(log(1.5/(P*log(2)))) );
    double f = x+P*exp(-log(2)*x/1.5);
    printf("%.10f\n",f);
}
