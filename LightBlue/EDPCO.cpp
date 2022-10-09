/*
AC
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bit>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;


int main(){
    int N;
    cin>>N;
    vector<vector<int>> a(N,vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }

    /*
    dp[S]= bit Sの女性がペアに結ばれた
    いま, __builtin_popcount(S)目の男性が (S\{j})の女性jと結ばれようとしている
    */

   
    vector<ll> dp(1<<N,0);
    dp[0]=1;

    for(int S=0;S<=(1<<N)-2;S++){
      
        int cnt=__builtin_popcount(S);//cnt人目の男性
        //cout<<"cnt="<<cnt<<endl;
        //cout<<"S="<<S<<",cnt="<<cnt<<endl;
        for(int j=0;j<N;j++){//j人目の女性
            if(((S>>j)&1)==0 && a[cnt][j]==1){
                //cout<<"S="<<S<<",j="<<j<<endl;
                dp[S|(1<<j)]+=dp[S];
                
                dp[S|(1<<j)]%=MOD;
            }
        }

    }
    cout<<dp[(1<<N)-1]<<endl;

}