/*
満点解答
復習すべし
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<bit>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

map<int,int> prime_factor(ll n){
    //n の素因数分解
    map<int,int> mp;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }

            mp[i]=cnt;
        }
    }

    if(n!=1)mp[n]=1;//nが素数自身の場合

    return mp;

}

//i=1~N まででGCD(i,K)=1となる すべてのiの和
ll solve(ll N,ll K){

    auto mp = prime_factor(K);//Kを素因数分解 
    vector<pair<int,int>> v;
    for(auto [x,t]:mp){// Kはxでt回われる
        v.emplace_back(x,t);
    }

    int m = mp.size();
    ll res=0;
    for(int S=0;S<(1<<m);S++){
        int cnt=__builtin_popcount(S);
        ll l=1;
        for(int i=0;i<m;i++){//平方数は数えない(メビウス関数を考えよ)
            if((S>>i)&1){
                l*=v[i].first;
            }
        }

        ll x=N/l;

        ll tmp = x*(x+1)/2*l;
        if(cnt%2==1){
            res-=tmp;
        }else{
            res+=tmp;
        }
    }

    return res;


}



int main(){
    ll N,K;
    cin>>N>>K;

    ll ans=0;

    //Kの約数g
    //Σ(i=1~N) i/gcd(i,K)
    for(ll g=1;g*g<=K;g++){
        if(K%g==0){
            //cout<<"g="<<g<<",solve("<<N/g<<","<<K/g<<")="<<solve(N/g,K/g)<<endl;
            ans+=solve(N/g,K/g);
            ans%=MOD;
            if(K/g!=g){
                //cout<<"K/g="<<K/g<<",solve("<<N/(K/g)<<","<<g<<")="<<solve(N/(K/g),g)<<endl;
                ans+=solve(N/(K/g),g);//K/(K/g)=g
                ans%=MOD;
            }
        }
    }

    cout<<(ans*K)%MOD<<endl;


}