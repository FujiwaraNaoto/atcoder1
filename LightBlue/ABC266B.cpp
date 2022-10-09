#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD=998244353;

int main(){
    ll N;
    cin>>N;

    //cout<<(N%MOD+MOD)%MOD<<endl;//これでとおる
    
     if(N>=0){
         cout<<N%MOD<<endl;
     }else{
       
         cout<<N%MOD<<endl;
         cout<<N%MOD+MOD<<endl;//NがちょうどMODの倍数の時に困る
         cout<<(N%MOD+MOD)%MOD<<endl;

         /*
         //これでもとおるのか...
         for(int x=0;x<MOD;x++){
             if((N-x)%MOD==0){
                 cout<<x<<endl;
                 return 0;
             }
         }
         */

     }
 }