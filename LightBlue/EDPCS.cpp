/*
dp[i][r][0 or 1] = 0~i-1までの位を見た際に,Dで割ったあまりがr

AC
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll dp[10000+10][100+5][2];

int main(){
    string K;
    cin>>K;
    int D;
    cin>>D;

    int len=K.size();
    
    dp[0][0][1]=1;//0

    for(int i=0;i<len;i++){
        //i桁目を考える

        for(int r=0;r<D;r++){
            //Dで割ったあまりがrの状態で, 数字dを加えるとする.

            for(int d=0;d<=9;d++){
                dp[i+1][(r+d)%D][0]+=dp[i][r][0];
                dp[i+1][(r+d)%D][0]%=MOD;
            }
            
            for(int d=0;d<(K[i]-'0');d++){
                dp[i+1][(r+d)%D][0]+=dp[i][r][1];
                dp[i+1][(r+d)%D][0]%=MOD;
            }

            int tmp_d = (K[i]-'0');//K[i]と一致するケースの場合
            dp[i+1][(r+tmp_d)%D][1]+=dp[i][r][1];
            dp[i+1][(r+tmp_d)%D][1]%=MOD;

        }

    }
    
    //-1しているのは 0を含むことになるから
    ll ans=((dp[len][0][0]+dp[len][0][1])%MOD-1+MOD)%MOD;
   

    cout<<ans<<endl;
}