#include<iostream>
#include<typeinfo>

#include<chrono>
#include<cstdio>
using namespace std;

int main(){

    auto tic = chrono::steady_clock::now();
    /*
    ここに時間を測りたい処理を書く
    */
    auto toc = chrono::steady_clock::now();
    cout<<typeid(tic).name()<<endl;
    double  elapsed_time = chrono::duration<double>(toc - tic).count();
    //std::cout << msec << " msec" << std::endl;
    printf("msec = %20.10f\n",elapsed_time);

}