/*
模範解答
dpを思いつくことがむずい
最長単調増加のイメージ
*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int N;
    string S;
    cin>>N;
    cin>>S;
    //長さを決めうつ
    vector<vector<int>> dp(N+1,vector<int>(N+1,0));


    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            if(S[i]==S[j]){
                //範囲外ならば0になっている
                dp[i][j]=dp[i+1][j+1]+1;
            }else{
                dp[i][j]=0;
            }
        }
    }

    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            //長さは頑張っても　j-iまで
            ans=max(ans,min(dp[i][j],j-i));
        }
    }
    cout<<ans<<endl;


}