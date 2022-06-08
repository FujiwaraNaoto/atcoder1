/*
小数点の桁数を指定する
指数表記

Qiita
https://qiita.com/ryupim/items/1cbeb860d4a2f056358a
*/
#include<iomanip>//setprecision を使用
#include<cstdio>//printf
#include<iostream>
using namespace std;

int main(){

    double y=1.0/3.0;

    cout<<y<<endl;//0.333333
    cout<<fixed<<setprecision(10)<<y<<endl;//0.3333333333
    printf("%.10f\n",y);//0.3333333333


    y=31415.926535;

    //単純に指数表記　
    cout<<scientific<<y<<endl;//3.1415926535e+04
    
    //指数表記　+ 小数点以下長さ指定
    cout<<scientific<<setprecision(2)<<y<<endl;//3.14e+04

    //uppercaseでeの部分を大文字表記に
    cout<<scientific<<setprecision(2)<<uppercase<<y<<endl;//3.14E+04
    printf("%.2e\n",y);//3.14e+04
    printf("%.2E\n",y);//3.14E+04

    return 0;
}

