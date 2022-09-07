/*
色分け問題
AC
*/
#include<iostream>
#include<map>
#include<numeric>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<int>> G;
vector<int> color;

void dfs(int now,int pre,int c){
    color[now]=c;
    for(int to:G[now]){
        if(to==pre) continue;
        dfs(to,now,-c);

    }
}

int main(){
    int N;
    cin>>N;
    color=vector<int>(N,0);
    G = vector<vector<int>>(N,vector<int>{});
    vector<int> A(N-1),B(N-1);
    for(int i=0;i<N-1;i++){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    dfs(0,-1,1);

    vector<int> ans1,ansminus1;
    for(int i=0;i<N;i++){
        if(color[i]==1){
            ans1.push_back(i);
        }else{
            ansminus1.push_back(i);
        }
    }
    /*
    for(int i=0;i<N;i++){
        cout<<"color["<<i<<"]="<<color[i]<<endl;
    }
    */
   

    if(ans1.size()>=N/2){
        for(int t=0;t<N/2;t++){
            cout<<ans1[t]+1<<' ';
        }

    }else{

        for(int t=0;t<N/2;t++){
            cout<<ansminus1[t]+1<<' ';
        }

    }


}