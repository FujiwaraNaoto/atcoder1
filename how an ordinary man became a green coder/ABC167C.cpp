/*
AC
bit全探索
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;

int main(){
    int N,M;
    ll X;
    cin>>N>>M>>X;

    vector<ll> C(N);
    vector<vector<ll>> A(N,vector<ll>(M,0));
    for(int i=0;i<N;i++){
        cin>>C[i];//本の値段
        for(int j=0;j<M;j++){
            cin>>A[i][j];//i番目の本で,j番目のアルゴリズム
        }
    }

    ll ans = INF; 
    for(int S=0;S<(1<<N);S++){
        //bitが立っている本を購入するとする
        
        vector<ll> algo(M,0);//最初はどのアルゴリズムも理解力0

        ll price=0;
        for(int i=0;i<N;i++){
            if((S>>i)&1){
                price+=C[i];

                for(int j=0;j<M;j++){
                    algo[j]+=A[i][j];
                }
            }
        }

        bool flag=true;
        for(int i=0;i<M;i++){
            if(algo[i]<X) flag=false;
        }

        if(flag){
            ans = min(ans,price);
        }
        
    }

    cout<<(ans==INF? -1: ans)<<endl;


}