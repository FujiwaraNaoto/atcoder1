/*
模範解答
N<=60などの特殊なケース
N=1などの特殊なケース　いろいろなケース

操作によって,かならず減る　など

*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    string S;
    cin>>S;
    ll ans=0;
    ll t=1;
    for(int i=0;i<N;i++){
        int d=S[i]-'a';
        ans += d*t;
        t*=2;
    }
    cout<<ans<<endl;

}