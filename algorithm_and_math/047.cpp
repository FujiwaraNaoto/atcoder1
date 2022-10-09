/*
木ではないことがポイント.
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> P;

vector<vector<int>> G;
vector<int> color;

int main(){
    int N,M;
    cin>>N>>M;
    G=vector<vector<int>>(N,vector<int>{});
    color=vector<int>(N,0);
    vector<int> A(M),B(M);
    for(int i=0;i<M;i++){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }



    for(int i=0;i<N;i++){
        if(color[i]==0){//まだ色が塗られていないから
        queue<P> que;
        que.push(P{i,1});

        while(!que.empty()){
            auto [v,c]=que.front();
            que.pop();
            if(color[v]!=0) continue;//すでにとおった部分は除く.
            color[v]=c;

            for(int to:G[v]){
                if(color[to]==c){
                    cout<<"No"<<endl;
                    return 0;
                }else if(color[to]==-c){
                    continue;
                }else{
                    que.push(P{to,-c});
                }

            }
        }

          
        }
    }
    
    cout<<"Yes"<<endl;
    return 0;
            


}