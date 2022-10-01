/*
map memoだとTLEする
再帰を用いた処理

どこで分けるか　がポイント　部分集合の利用
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;


vector<vector<ll>> a;
vector<bool> flag;

vector<ll> memo;

//map<ll,ll> memo;


ll f(int S,int n){
    if(flag[S]) return memo[S];
    //cout<<"S="<<S<<",n="<<n<<endl;
    flag[S]=true;

    vector<int> S_idx;

    for(int i=0;i<n;i++){
        if((S>>i)&1){
            S_idx.push_back(i);
        }
    }
    ll tmp=0;
    
    for(int i=0;i<S_idx.size();i++){
        for(int j=i+1;j<S_idx.size();j++){
            tmp+=a[S_idx[i]][S_idx[j]];
        }
    }
    
 
    ll ret=tmp;

    
        for(int sub=S;sub>0;sub=(sub-1)&S){//Sの部分集合sub
            if(sub==S || sub==0) continue;

            ret=max(ret,f(S-sub,n)+f(sub,n));
        }
    

    return memo[S]=ret;



    return ret;

}

int main(){
    int N;
    cin>>N;
    flag = vector<bool>(1<<N,false);
    memo = vector<ll>(1<<N);
    a = vector<vector<ll>>(N,vector<ll>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }

    cout<<f((1<<N)-1,N)<<endl;


}