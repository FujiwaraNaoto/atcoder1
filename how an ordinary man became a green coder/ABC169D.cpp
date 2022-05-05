/*
素因数分解がポイント
AC
*/
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

map<ll,int> div(ll x){

    map<ll,int> mp;
    for(ll i=2;i*i<=x;i++){
        
        while(x%i==0){//xがiで割り切れるなら割れるだけ割ってしまう
            mp[i]++;
            x=x/i;
        }
    }

    if(x>1) mp[x]++;//x自身が素数の時
    return mp;
} 

int main(){
    ll N;
    cin>>N;

    map<ll,int>  mp = div(N);//Nを素因数分解した際 firstがsecond乗されている

    /*
    for(auto [x,times]:mp){
        cout<<"x="<<x<<",times="<<times<<endl;
    }
    */

    ll ans=0;
    for(auto [x, times]:mp){
        
        int tempsum=0;
        int cnt=0;
        // tempsumは 1+2+3+..+cntのこと
        while(true){
            tempsum += (cnt+1);
            if(tempsum>times) break;
            cnt++;//tempsum<=timesの時
        }
        //cout<<"x="<<x<<",cnt="<<cnt<<endl;
        ans+=cnt;
    }

    cout<<ans<<endl;

}