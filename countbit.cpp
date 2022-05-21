/*
立っているbitの数をカウント
*/
#include<iostream>
#include<bit>
using namespace std;

int main(){
    int n=5;
    for(int S=0;S<(1<<n);S++){
        cout<<__builtin_popcount(S)<<endl;
    }
}