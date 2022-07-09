/*
方針はあっている
O(N^3)
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int digit(int x){
    int cnt=0;
    while(x>0){
        cnt++;
        x/=10;
    }
    return cnt;
}

int main(){
    int N; ll P;
    cin>>N>>P;

    vector<vector<ll>> dp(N+1,vector<ll>(N+1,0));

    //1種類の文字で構成されるSがi文字のとき　Tは(1+digit(i))文字 Sの個数は26
    for(int i=1;i<=N;i++){
        dp[i][1+digit(i)]=26;//Sはa~zまでの26文字
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){

            //k文字分を後から追加
            for(int k=1;j+1+digit(k)<=N && i+k<=N;k++){
                dp[i+k][j+1+digit(k)]+=dp[i][j]*25;
                dp[i+k][j+1+digit(k)]%=P;
            }
        }
    }
    ll ans=0;
    for(int i=2;i<N;i++){//|S|>|T|となるようにする
        ans+=dp[N][i];
        ans%=P;
    }

    cout<<ans<<endl;


    
}