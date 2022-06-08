/*
atcoderには必要になることがないけど
入力数を指定されない複数入力の場合

必要なら getline()の後に cin.ignore()もつけるべし
コンパイル時に　-std=c++11 オプション

*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    string input,v;
    getline(cin,input);
    stringstream ss(input);

    vector<string> test;
    while(getline(ss,v,' ')){//空白を検知する
        test.push_back(v);
    }

    for(const auto &str:test){
        cout<<str<<endl;
    }   




}
