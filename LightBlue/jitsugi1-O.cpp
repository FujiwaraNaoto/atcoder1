/*
アルゴリズム実技検定1

問題O

j番目のさいころを降るときに i<A[j][k]となるすべてのkで
dp[A[j][k]]/6の総和が期待値となる

dp[]



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





int main(){
    int N;
    cin>>N;
    set<int> S;
    vector<vector<int>> A(N,vector<int>(6));
    for(size_t i=0;i<N;i++){
        for(size_t j=0;j<6;j++){
            cin>>A[i][j];
            S.insert(A[i][j]);
        }
    }

    map<int,int> mp;
    int cnt=1;
    for(int x:S){
        mp[x]=cnt++;
    }
    //現在のcntとすると 実際は 0~cnt-1の種類
    

    vector<vector<int>> idxlist(cnt+1,vector<int>{});
    for(size_t i=0;i<N;i++){
        for(size_t j=0;j<6;j++){
           A[i][j]=mp[A[i][j]];
           idxlist[A[i][j]].push_back(i);//値A[i][j]はi番目のさいころが持っている
        }
    }
    


    /*

    // O(N^2)
    cnt = S.size();
    vector<double> dp(cnt+1,0);
   
    double tmpmax=0;
    for(int i=cnt;i>=0;i--){
        dp[i]=tmpmax+1;
        for(int j=0;j<N;j++){
            double tmpsum=0;
            for(int k=0;k<6;k++){
                if(A[j][k]>i){
                    tmpsum+=dp[A[j][k]]/6;
                }
            }
            tmpmax=max(tmpsum,tmpmax);
        }

        
    }
    
    printf("%.10f\n",dp[0]);
    */


    

    cnt = S.size();
    vector<double> dp(cnt+1,0);
    vector<double> tot(N,0);//さいころの数の分だけある.
    
    double tmpmax=0;
    //dp[i] i番目の値までいくときの期待値
    for(int i=cnt;i>=0;i--){
        dp[i]=tmpmax+1;//dp[i]を

        for(int idx:idxlist[i]){
            //dp[i]に関わっている iが入っているさいころリスト達
            //  idxのさいころは値が更新される
            tot[idx]+=dp[i]/6;   
            tmpmax = max(tot[idx],tmpmax);
        }

        
    }

    printf("%.10f\n",dp[0]);
    



}