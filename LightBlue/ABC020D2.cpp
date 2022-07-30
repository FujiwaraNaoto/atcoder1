#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

//x^y mod=MOD 
ll mod_pow(ll x,ll y,ll MOD){
    ll ret=1;
    while(y>0){
        if(y&1){
            ret*=x;
            ret%=MOD;
        }
        y/=2;
        x=x*x%MOD;
    }

    return ret;
}


ll inv2=mod_pow(2,MOD-2,MOD);//2の逆元

ll gcd(ll x,ll y){
    if(y==0) return x;
    else return gcd(y,x%y);
}

map<ll,ll> prime_factor(ll n){
    map<ll,ll> mp;
    //nを素因数分解
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }

    if(n!=1)mp[n]++;

    return mp;
}

ll func(ll N,ll K){

    auto primeK=prime_factor(K);//Kの素因数分解
    int k=primeK.size();

    //cout<<"K="<<K<<endl;
    vector<ll> factors;//素因数分解した際の素数のみを取り出す
    for(auto [x,_]:primeK){
        factors.push_back(x);
        //cout<<"x="<<x<<endl;
    }


    ll ret=0;
    for(int S=0;S<(1<<k);S++){
        ll l=1;
        
        int bitcnt=0;

        for(int i=0;i<k;i++){
            if((S>>i)&1){
                bitcnt++;
                l*=factors[i];
            }
        }
            //S=0のときは n=1
        ll tmp = l*(1+N/l)%MOD*(N/l)%MOD*inv2%MOD;
        //ll tmp=(1+N/l)*(N/l)/2*l;

        if(bitcnt%2==0){
            ret +=tmp;
            
            //ret%=MOD;
        }else{//bitcnt%2==1の場合
            ret-=tmp;
            ret+=MOD;
            ret%=MOD;

        }

    }
    //cout<<"ret="<<ret<<endl;
    return ret;
}



int main(){
    ll N,K;
    cin>>N>>K;

    ll ans=0;
    for(ll d=1;d*d<=K;d++){
        if(K%d==0){//Kの約数がd
            
            ans += func(N/d,K/d);
            ans%=MOD;
            if(K/d!=d){
                // K/(K/d) = d
                ans += func(N/(K/d),d);
                ans%=MOD;
            }
        }
    }

    cout<<(ans*K)%MOD<<endl;



}