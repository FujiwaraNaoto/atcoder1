/*
二つの整数をえらんで,それぞれから1を引く
= すべての整数から1を引き、整数を一つ選び1を足す
この操作は最大でも
K=max({A,B,C});とすると
(K-A)+(K-B)+(K-C)回までしか行われない.
しかもKはA,B,Cのどれかと等しい.


A,B,Cから Kを引いた後で
最大K回の回数分, A,B,Cに1を足す操作が可能

AC

*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll A,B,C;
    cin>>A>>B>>C;
    ll K=max({A,B,C});

    ll tmp=(K-A)+(K-B)+(K-C);
    if(tmp>K){
        cout<<-1<<endl;
        
    }else{
        cout<<K<<endl;
    }

    return 0;

}