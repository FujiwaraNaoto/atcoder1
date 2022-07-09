/*
模範解答　
高速化
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
    vector<vector<ll>> ds(N+1,vector<ll>(N+1,0));

    //1種類の文字で構成されるSがi文字のとき　Tは(1+digit(i))文字 Sの個数は26
    for(int i=1;i<=N;i++){
        dp[i][1+digit(i)]=26;//Sはa~zまでの26文字
    }
    /*
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){

            //k文字分を後から追加
            for(int k=1;j+1+digit(k)<=N && i+k<=N;k++){
                dp[i+k][j+1+digit(k)]+=dp[i][j]*25;
                dp[i+k][j+1+digit(k)]%=P;
            }
        }
    }
    */
   const int ten[]={0,1,10,100,1000,10000};
    for(int i=1;i<=N;i++){
        for(int j=1;j<N;j++){
            /*
            //k文字分を後から追加
            for(int k=1;i-k>0;k++){
                int nj=j-1-digit(k);
                if(nj<0) continue;
                dp[i][j]+=dp[i-k][nj]*25;
                dp[i][j]%=P;

                //dp[i+k][j+1+digit(k)]+=dp[i][j]*25;
                //dp[i+k][j+1+digit(k)]%=P;
            }
            */


            for(int k=1;k<=4;k++){
                int nj=j-k-1;
                if(nj<0) continue;

                int lb=ten[k],ub=ten[k+1];
                ub = min(ub,i);
                if(lb>=ub) continue;// lb<ubでなければならない
                //i-ub+1 ~ i-lb
                ll sum = (ds[i-lb][nj] - ds[i-ub][nj]+P)%P;
                dp[i][j]+=sum*25; 
                dp[i][j]%=P;

            }
     
           ds[i][j]=ds[i-1][j]+dp[i][j];
        }

     
       
        
    }



    ll ans=0;
    for(int i=2;i<N;i++){//|S|>|T|となるようにする
        ans+=dp[N][i];
        ans%=P;
    }

    cout<<ans<<endl;


    
}