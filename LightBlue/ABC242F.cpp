/*
AC
包除原理
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;


//xのy乗
ll mod_pow(ll x,ll y,ll mod){
    ll power=x;
    ll ret = 1;
    while(y>0){
        if(y&1){
           ret = ret*power%mod;
        }
        power = power*power%mod;
        y = y>>1;
    }
    return ret;

}



struct combination{
    typedef long long ll;
    std::vector<ll> fact,ifact;
    combination(ll n): fact(n+1),ifact(n+1){
        fact[0]=1;//0!=1通り
        for(ll i=1;i<=n;i++) fact[i] = fact[i-1]*i%MOD;
        //ifact[n] = fact[n].inv();
        
        // n!の逆元がifact[n]
        ifact[n] = mod_pow(fact[n],MOD-2,MOD);// n!を(mod-2)乗した後でmodであまりをとった
        for(ll i=n;i>=1;i--) ifact[i-1] = ifact[i]*i%MOD;
    }

    ll operator()(ll n,ll k){
        if(k<0 || k>n) return 0;
        // n!/( k!*(n-k)! )
        return (fact[n]*ifact[k])%MOD * ifact[n-k]%MOD;
    }

} comb(2510);



//H=N W=Mで固定
vector<vector<ll>> func(int b,int H,int W){
    
    vector<vector<ll>> d(H+1,vector<ll>(W+1,0));

    for(int h=0;h<=H;h++){
        for(int w=0;w<=W;w++){
            for(int i=0;i<=h;i++){//h行のうち,i行個を占領する
                for(int j=0;j<=w;j++){//w行のうち,j行個を占領する
                    ll now= comb(i*j,b);// (i+j) C b

                    now*=comb(h,i);
                    now%=MOD;
                    now*=comb(w,j);
                    now%=MOD;

                    if((h-i+w-j)%2==1){//引き算
                        d[h][w]+=MOD-now;
                        d[h][w]%=MOD;
                    }else{
                        d[h][w]+=now;
                        d[h][w]%=MOD;
                    }
                }
            }
        }
    }

    return d;

}


int main(){
    ll N,M,B,W;
    cin>>N>>M>>B>>W;

    auto db=func(B,N,M);
    auto dw=func(W,N,M);
    ll ans=0;

    for(int bi=0;bi<=N;bi++){
        for(int bj=0;bj<=M;bj++){
            for(int wi=0;wi<=N;wi++){
                for(int wj=0;wj<=M;wj++){
                    if(bi+wi>N) break;
                    if(bj+wj>M) break;

                    ll now=comb(N,bi)*comb(N-bi,wi)%MOD;

                    now*=comb(M,bj);
                    now%=MOD;

                    now*=comb(M-bj,wj);
                    now%=MOD;

                    
                    now*=db[bi][bj];
                    now%=MOD;
                    now*=dw[wi][wj];
                    now%=MOD;

                    ans+=now;
                    ans%=MOD;
                }

            }

        }

    }

    cout<<ans<<endl;



}