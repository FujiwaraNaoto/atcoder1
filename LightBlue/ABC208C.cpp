/*
mapを使うと早くすむので楽.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int N;
    ll K;
    cin>>N>>K;
    vector<ll> A(N);
    map<ll,ll> mp;
    for(int i=0;i<N;i++){
        cin>>A[i];
        mp[A[i]]+=K/N;
    }
    ll rK=K%N;

    for(auto& p:mp){
        if(rK>0){
            p.second++;
            rK--;
        }else break;
    }

    
    for(int i=0;i<N;i++){
        cout<<mp[A[i]]<<endl;
    }


}