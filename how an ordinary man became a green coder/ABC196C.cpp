/*
AC
long long にするためにstollを使用
stoiは int 
*/
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;


int main(){
    ll N;
    cin>>N;

    ll cnt=0;
    for(ll i=1;i*i<=N;i++){
        
        
        ll temp = stoll(to_string(i)+to_string(i));
        if(temp<=N){
            cnt++;
        }
    }

    cout<<cnt<<endl;
   


}