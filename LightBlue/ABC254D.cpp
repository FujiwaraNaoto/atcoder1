/*
同じグループでまとめるということがポイント
*/
#include<iostream>
#include<vector>
#include<map>
typedef long long ll;
using namespace std;

int main(){
    ll N;
    cin>>N;
    vector<int> list(N+1);
    for(int i=1;i<=N;i++){
        list[i]=i;
    }

    for(ll i=2;i*i<=N;i++){
        for(ll k=i*i;k<=N;k+=(i*i)){
            while(list[k]%(i*i)==0){//きちんとこれでやらないとむり, 16とか
                 list[k]=list[k]/(i*i);
            }
           
        }
    }

    map<int,ll> mp;
    //mp[i] = グループi
    for(int i=1;i<=N;i++){
        mp[list[i]]++;
    }
    ll ans=0;
    for(auto [fi,la]:mp){
        ans+=la*la;
    }

    cout<<ans<<endl;




}
