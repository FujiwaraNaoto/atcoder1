/*
printfなどはある程度バッファがいっぱいにならないとむり
ストリームから吐き出されるまでは画面に文字が表示されない
fflushを用いて即座にデータを吐き出す処理を行わせる
コンパイルがとおらないために実行できない
g++ cout.cpp -o p -fenable-enable-libstdcxx-time -std=c++17
cc1plus.exe: error: unknown pass enable-libstdcxx-time specified in '-fenable'

*/
#include<iostream>
#include<chrono>
#include<future>
#include<thread>
#define _GLIBCXX_USE_NANOSLEEP 

int main(){

    std::cout<<"Hello World"<<std::endl;
    std::flush(std::cout);
    
    for(int i = 0; i < 10; i++){
        std::cout<<"Hello World "<<i<<std::endl;
        std::flush(std::cout);
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }

    for(int i = 0; i < 10; i++){
        std::cout<<"Hello World "<<i<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }


}