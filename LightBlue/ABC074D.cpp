/*
模範解答
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<59;


int main(){
    int N;
    cin>>N;
    vector<vector<ll>> A(N,vector<ll>(N));

    vector<pair<ll,int>> dis;

    ll ans=0;
    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){

            cin>>A[i][j];

            if(i<j){
                dis.emplace_back(A[i][j],i*N+j);
                ans+=A[i][j];
            }
           
        }
    }

    sort(dis.begin(),dis.end());
    reverse(dis.begin(),dis.end());//大きい順に考える.

   
    for(auto [c,p]:dis){
        int i = p/N;
        int j = p%N;

        for(int k=0;k<N;k++){
            if(i==k || j==k || A[i][k]==INF || A[k][j]==INF) continue;
            if(A[i][k]+A[k][j]==c){
                ans -= c;//除外できる道
                A[i][j]=A[j][i]=INF;
                break;
            }else if(A[i][k]+A[k][j]<c){
                cout<<-1<<endl;
                return 0;
            }
        }
     
    }

    
    cout<<ans<<endl;

}
