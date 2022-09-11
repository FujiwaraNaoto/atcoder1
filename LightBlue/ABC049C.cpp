/*
DP
AC
*/
#include<cmath>
#include<queue>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;


int main(){
    string S;
    cin>>S;
    
    int n=S.size();
    //dp[i]=true 0~i-1までで 構成が可能.
    vector<bool> dp(n+1,false);
    if(S[0]=='d' || S[0]=='e'){
        dp[0]=true;
    }
    for(int i=0;i<n;i++){
        if(dp[i]){

            if(i+5<=n && S.substr(i,5)=="dream"){//dream
                dp[i+5]=true;
            }
            if(i+7<=n && S.substr(i,7)=="dreamer"){//dreamer
                dp[i+7]=true;
            }
            if(i+5<=n && S.substr(i,5)=="erase"){//erase
                dp[i+5]=true;
            }
            if(i+6<=n && S.substr(i,6)=="eraser"){
                dp[i+6]=true;
            }
        }
    }

    cout<<(dp[n]?"YES":"NO")<<endl;



}