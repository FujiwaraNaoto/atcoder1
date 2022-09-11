/*
二分探索で探す
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
const ll MOD=998244353;
const int N=1<<20;

int main(){
    int Q;
    ll x;
    int t;
    cin>>Q;
    vector<ll> A(N,-1);
    map<ll,ll> mp;
    set<ll> st;
    for(ll i=0;i<N;i++)st.insert(i);//最初はすべてが-1

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
           //これでもOK
            h%=N;
            auto it=st.lower_bound(h);//値がh以上 かつ残っている者
            if(it!=st.end()){
                h=*it;
                A[h%N]=x;
                st.erase(it);//要素をのける
            }else{
                it=st.lower_bound(0);//0以上の要素で最小のもの
                h=*it;
                A[h%N]=x;
                st.erase(it);
            }


        }else if(t==2){
                cout<<A[x%N]<<endl;
        }


    }
}