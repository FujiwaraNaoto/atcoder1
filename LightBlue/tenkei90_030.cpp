/*
AC
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int MAX_N=1e7;

vector<bool> is_prime(MAX_N+1,true);

vector<int> prime_factor(int n){
    is_prime[0]=is_prime[1]=false;
    vector<int> ret;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            ret.push_back(i);
            for(int p=2*i;p<=n;p+=i){
                is_prime[p]=false;
            }
        }
    }
    return ret;
}

int main(){
    int N,K;
    cin>>N>>K;
    auto prime = prime_factor(MAX_N);
    vector<int> cnt(N+1,0);

    for(int p:prime){
        for(int k=p;k<=N;k+=p){
            cnt[k]++;
        }
    }

    int ans=0;
    for(int i=2;i<=N;i++){
        if(cnt[i]>=K)ans++;
    }
    cout<<ans<<endl;

}