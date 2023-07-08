/*
atcoderには必要になることがないけど
入力数を指定されない複数入力の場合
空白を含む入力一行をそのまま読み込む際にはgetlineを用いる

必要なら getline()の後に cin.ignore()もつけるべし
コンパイル時に　-std=c++11 オプション

*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>


int main(){
    std::string input,v;
    std::getline(std::cin,input);
    std::stringstream ss(input);

    std::vector<std::string> test;
    while(std::getline(ss,v,' ')){//空白を検知する
        test.push_back(v);
    }

    for(const auto &str:test){
        std::cout<<str<<std::endl;
    }   




}
