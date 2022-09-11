/*
経路圧縮
*/
#include<cmath>
#include<queue>
#include<iostream>
#include<set>
#include<vector>
#include<numeric>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;
const ll MOD=998244353;
const int N=1<<20;

vector<ll> nxt(N);


int find(int idx){
    if(nxt[idx]==idx) return idx;
    else{
        return nxt[idx]=find(nxt[idx]);
    }
}

int main(){
    int Q;
    ll x;
    int t;
    cin>>Q;
    vector<ll> A(N,-1);
    iota(nxt.begin(),nxt.end(),0);
    
    for(int i=0;i<Q;i++){
        cin>>t>>x;
        if(t==1){
            ll h=x;
            /*
            //ここのぶぶんを高速化
            while(A[h%N]!=-1){
                h++;
            }
            A[h%N]=x;
            */
           
            int i=h%N;
            i=find(i);
            A[i%N]=x;

            nxt[i]=find((i+1)%N);
            
        }else if(t==2){
                cout<<A[x%N]<<endl;
        }


    }
}