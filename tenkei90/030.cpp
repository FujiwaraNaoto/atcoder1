/*
おそらくKが小さいから K種類未満の素因数を求めた方が早い
そんなことはなかった

AC
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;

set<int> prime(ll n){
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    set<int> ret;
    for(ll i=2;i<=n;i++){
        if(is_prime[i]){
            ret.insert(i);
            for(ll p=i*i;p<=n;p+=i){
                is_prime[p]=false;
            }
        }
    }

    return ret;

}

int main(){
    int N,K;
    cin>>N>>K;
    auto st = prime(1LL*N);

    vector<int> cnt(N+1,0);
    for(auto p:st){
        for(int i=p;i<=N;i+=p){
            cnt[i]++;
        }
    }

    int ans=0;
    for(int i=1;i<=N;i++){
        if(cnt[i]>=K)ans++;
    }
   
    cout<<ans<<endl;


}