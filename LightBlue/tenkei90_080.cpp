/*

全事象 -(少なくともひとつを満たす)

ここでの満たす　はA[0]~A[N-1]のなかに該当するものがある

AC
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;


int main(){
    int N,D;
    cin>>N>>D;
    vector<ll> A(N);
    for(int i=0;i<N;i++)cin>>A[i];

    //少なくとも一つを満たす
    //S=0のときは全体となる
    //
    ll ans=0;
    for(int S=0;S<(1<<N);S++){
        ll bitS=0;
        int cnt=0;
        for(int i=0;i<N;i++){
            if( (S>>i)&1){
                cnt++;
                bitS |= A[i];
            }
        }
        ll num=1;
        //bitがbitSのどれとも被らない場合の数
        //bitSの条件を　満たさない場合の数

        for(int bit=0;bit<D;bit++){//位
            if( bitS&(1LL<<bit)) continue;
            else{
                //bitが0のときがポイント
                // このときは位bitは0と1のどちらでもよい
                num*=2;
            }
        }

        if(cnt%2==0){
            ans+=num;
        }else{
            ans-=num;
        }

    }
    cout<<ans<<endl;

}