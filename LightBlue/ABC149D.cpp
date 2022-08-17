/*
グー　r=0
チョキ　s=1
パー　p=2
とする

*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N,K;
    int R,S,P;
    cin>>N>>K;
    cin>>R>>S>>P;
    string T;
    cin>>T;
    vector<int> t(N);
    for(int i=0;i<N;i++){
        if(T[i]=='r'){
            t[i]=0;
        }else if(T[i]=='s'){
            t[i]=1;
        }else{
            // T[i]=='p'
            t[i]=2;
        }
    }

    vector<vector<int>> dp(N+1,vector<int>(3,0));
    int points[3]={R,S,P};

    dp[0][0]=dp[0][1]=dp[0][2]=0;
    vector<int> record;

    for(int i=0;i<N;i++){
        
        int win=(t[i]+2)%3;//i回目のじゃんけんでの手の出し方
            
        if(i>=K && win==record[i-K]){
            //K回目の影響をうける.かつ,勝つ手がK回前の手と一致するときが困る
            int tmp=max({dp[i][0],dp[i][1],dp[i][2]});

            dp[i+1][win]=tmp;
            dp[i+1][(win+1)%3]=tmp;
            dp[i+1][(win+2)%3]=tmp;
            record.push_back(4);//過去の手を(win+1)%3,(win+2)%3と自由に変更が可能な any=4とする 
        }else{
            int tmp=max({dp[i][0],dp[i][1],dp[i][2]});
            dp[i+1][win]=tmp+points[win];//勝つ手のときがお得
            dp[i+1][(win+1)%3]=tmp;
            dp[i+1][(win+2)%3]=tmp;
            record.push_back(win);//手を記録する
        }

        
    }

    int ans=max({dp[N][0],dp[N][1],dp[N][2]});
    cout<<ans<<endl;
    

}