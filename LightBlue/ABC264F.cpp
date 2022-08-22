/*
AC

dp[i][j][flag1][flag2]
=(i,j)のマスで 
i行目がひっくり返されているならflag1=1,そうでないならばflag1=0
j列目がひっくり返されているならflag2=1,そうでないならばflag2=0

*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;

int main(){
    int H,W;
    cin>>H>>W;
    vector<ll> R(H),C(W);
    for(int i=0;i<H;i++)cin>>R[i];
    for(int i=0;i<W;i++)cin>>C[i];
    vector<vector<int>> A(H,vector<int>(W));
    string str;
    for(int i=0;i<H;i++){
        cin>>str;
        for(int j=0;j<W;j++){
            A[i][j]=str[j]-'0';//数字にしておく
        }
    }
    


    vector dp(H,vector<vector<vector<ll>>>(W,vector<vector<ll>>(2,vector<ll>(2,INF))));
    
    dp[0][0][0][0]=0;
    dp[0][0][0][1]=C[0];//0列目をひっくり返す場合
    dp[0][0][1][0]=R[0];//0行目をひっくり返す場合
    dp[0][0][1][1]=R[0]+C[0];//0列目と0行目をひっくり返す場合
    

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
           
            for(int bit1=0;bit1<2;bit1++){
                for(int bit2=0;bit2<2;bit2++){
                    int x=A[i][j];
                    if(bit1==1){//まずは(i,j)でのタイルの色を見る
                        x^=1;
                    }
                    if(bit2==1){
                        x^=1;
                    }

                    if(j+1<W){
                        int nx=A[i][j+1];
        
                        if(bit1==1){
                            nx^=1;//i行目がひっくり返されている操作の場合 A[i][j+1]の色が反転している故
                        }
                        if(nx==x){//j+1列目をひっくり返す必要がない場合
                            dp[i][j+1][bit1][0]=min(dp[i][j+1][bit1][0],dp[i][j][bit1][bit2]);
                        }else{
                            //j+1列目がひっくり返される必要がある
                            dp[i][j+1][bit1][1]=min(dp[i][j+1][bit1][1],dp[i][j][bit1][bit2]+C[j+1]);

                        }

                        

                    }

                    if(i+1<H){
                        int nx=A[i+1][j];

                        if(bit2==1){
                            nx^=1;//j列目がひっくり返されている操作の場合
                        }

                        if(nx==x){//i+1行目をひっくり返す必要がない場合
                            dp[i+1][j][0][bit2]=min(dp[i+1][j][0][bit2],dp[i][j][bit1][bit2]);

                        }else{
                            //i+1行目をひっくり返す必要がある場合
                            dp[i+1][j][1][bit2]=min(dp[i+1][j][1][bit2],dp[i][j][bit1][bit2]+R[i+1]);   
                        }

                    }
                                    
                }
            }
        }
    }

    ll ans=INF;
    for(int bit1=0;bit1<2;bit1++){
        for(int bit2=0;bit2<2;bit2++){
            ans=min(ans,dp[H-1][W-1][bit1][bit2]);
        }
    }

    cout<<ans<<endl;



}