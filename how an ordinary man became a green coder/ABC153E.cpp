//今のモンスターの体力がhになるまでに　トキが消費した魔力の最小値dp[h]
//AC
#include<iostream>
#include<vector>
using namespace std;
const int INF = 1<<30;

int main(){
    int H,N;
    cin>>H>>N;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }

    vector<int> dp(H+1,INF);
    dp[H]=0;
    
    for(int h=H;h>=0;h--){
        for(int i=0;i<N;i++){
            dp[ max(0,h-A[i])] = min( dp[ max(0,h-A[i])],dp[h]+B[i]);
        }
    }
    
    cout<<dp[0]<<endl;
}
