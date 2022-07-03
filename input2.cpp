/*
空白を含めてすべて一行すべて読み込む方法.
cin>> では空白で途切れる
*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
const string error = "FORMAT ERROR";

int main(){
    string input;
    getline(cin,input);
    stringstream ss(input);


}