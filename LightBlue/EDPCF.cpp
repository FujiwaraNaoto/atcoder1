/*
AC
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;

int dp[3005][3005];

int main(){
    string s,t;
    cin>>s;
    cin>>t;
    /*
    s='*'+s;
    t='*'+t;
    */
    int len_s=s.size(),len_t=t.size();
    

    for(int i=0;i<len_s;i++){
        for(int j=0;j<len_t;j++){

            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            dp[i][j+1]=max(dp[i][j+1],dp[i][j]);

            if(s[i]==t[j]){
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
            }
        }
    }

    pair<int,int> start;
    int ans_len=0;
    for(int i=0;i<=len_s;i++){
        if(ans_len<dp[i][len_t]){
            ans_len=dp[i][len_t];
            start=make_pair(i,len_t);
        }
    }

    for(int j=0;j<=len_t;j++){
        if(ans_len<dp[len_s][j]){
            ans_len=dp[len_s][j];
            start=make_pair(len_s,j);
        }
    }

    auto [now_s,now_t]=start;

    vector<char> ans_str;
    /*
    //NG
    while(now_s>=0 || now_t>=0){
        if(now_s>0 && dp[now_s][now_t]==dp[now_s-1][now_t]){
            now_s--;
        }
        else if(now_t>0 && dp[now_s][now_t]==dp[now_s][now_t-1]){
            now_t--;
        }
        else{ 
        //if(s[now_s-1]==t[now_t-1]){
            ans_str.push_back(s[now_s-1]);
            now_s--;
            now_t--;
        }
    }
    */


    
    while(ans_len>0){
        //答えの復元
        if(now_s>0 && dp[now_s][now_t]==dp[now_s-1][now_t]){
            now_s--;
        }
        else if(now_t>0 && dp[now_s][now_t]==dp[now_s][now_t-1]){
            now_t--;
        }
        else{ 
        //if(s[now_s-1]==t[now_t-1]){
            ans_str.push_back(s[now_s-1]);
            ans_len--;
            now_s--;
            now_t--;
        }
    }


    reverse(ans_str.begin(),ans_str.end());

    string ans(ans_str.size(),'A');
    for(int i=0;i<ans_str.size();i++){
        ans[i]=ans_str[i];
    }
    cout<<ans<<endl;

}