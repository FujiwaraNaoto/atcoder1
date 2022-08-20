#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main(){
    ll N,K;
    cin>>N>>K;
    

    vector<bool> is_prime((1e+6)+1,true);//√N 以下の素数を記録
    is_prime[0]=is_prime[1]=false;

    set<ll> prime_st;
    for(int p=2;p<=1e+6;p++){
        if(is_prime[p]){//pが素数のとき
            prime_st.insert(p);//素数を入れる
            for(ll j=2*p;j*j<=1e+6;j+=p){
                is_prime[j]=false;//エラトステネスの篩
            }
        }
    }





    //N-(K-1) ~ NのK個
    // factor[0]がN-(K-1)  factor[K]がNに対応
    vector<ll> deno(K+1);//分母 1~K
    vector<ll> nominator(K+1);//分子 1~K
    
    //初期化
    ll offset = N-(K-1);
    for(ll i=offset;i<=N;i++){
        // i=N-(K-1)からi=NのK個
        nominator[i-offset]=i;//分子
    }
    for(ll i=1;i<=K;i++) deno[i]=i;//分母




    ll ans=1;

    for(ll p:prime_st){
            
        ll start=((N-K+1)+(p-1))/p*p;//N-k+1以上で一番最初のpの倍数
        ll end = N/p*p;//N以下の数字で最後の素数
            
        ll tempcnt=0;

        for(ll k=start;k<=end;k+=p){
                while(nominator[k - offset]%p==0){
                    nominator[k - offset]/=p;
                    tempcnt++;
                }                                
        }

            for(ll k=p;k<=K;k+=p){
                //pの倍数
                //if(k%p==0){
                    while(deno[k]%p==0){
                        deno[k]/=p;
                        tempcnt--;
                    }

                
            }

            ans =ans * (tempcnt+1)%mod;
    }


    for(ll i=offset;i<=N;i++){//i=N-(K-1) ~ N
        if(nominator[i-offset]!=1LL){
            //素因数を含む事になる
            //iを素因数分解するべし

            ans = ans*2LL%mod;
        }
    }


    cout<<ans<<endl;
    //n ~ Nまでの中でk!に存在しない素数がいくつか
    





}