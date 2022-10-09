/*
dp[i][j][k]=i/N(dp[i-1][j][k]+1) + j/N(dp[i+1][j-1][k]+1)+k/N(dp[i][j+1][k-1]+1) + (N-(i+j+k))/N(dp[i][j][k]+1)

dp[i][j][k]について解く


*/
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

double dp[1000][630][330];

int main(){
    int N;
    cin>>N;
    vector<int> cnt(4,0);
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    

    
    for(int k=0;k<=cnt[3];k++){
         for(int j=0;j<=cnt[2]+cnt[3];j++){
             for(int i=0;i<=cnt[1]+cnt[2]+cnt[3];i++){
    
    // for(int i=0;i<=cnt[1]+cnt[2]+cnt[3];i++){
    //     for(int j=0;j<=cnt[2]+cnt[3];j++){
    //         for(int k=0;k<=cnt[3];k++){//これだとエラー

                if(i+j+k==0) continue;
                double tmp=0;
                if(i-1>=0){
                    tmp+=(double)i/(i+j+k)*dp[i-1][j][k];
                }
                if(j-1>=0){
                    tmp+=(double)j/(i+j+k)*dp[i+1][j-1][k];
                }
                if(k-1>=0){
                    tmp+=(double)k/(i+j+k)*dp[i][j+1][k-1];
                }
                tmp+=(double)N/(i+j+k);

                dp[i][j][k]+=tmp;
            }
        }
    }

    printf("%.10f\n",dp[cnt[1]][cnt[2]][cnt[3]]);
}