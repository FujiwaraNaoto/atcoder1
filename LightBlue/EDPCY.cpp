/*
AC 

dp[i]=i番目の壁に初めて到達する通り数

壁を0~N-1番目
ゴールをN番目にしている

*/
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
typedef pair<ll,ll> P;



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

};

combination comb(200000+10);

ll dp[3005];

int main(){
    /*
    N番目(0-indexex)が(H,W)
    */
   
    int H,W,N;
    cin>>H>>W>>N;
    int n=N+1;
    vector<P> wall(n);
    vector<ll> r(n),c(n);
    r[N]=H,c[N]=W;
    for(int i=0;i<N;i++){
        cin>>r[i]>>c[i];
    }

    for(int i=0;i<n;i++){
        wall[i]=P{r[i],c[i]};
    }
    

    sort(wall.begin(),wall.end(),
    [](const P& lhs,const P& rhs){
        if(lhs.first!=rhs.first){
            return lhs.first<rhs.first;
        }else{
            return lhs.second<rhs.second;
        }

    });

    /*
    0->(0,0)
    N+1->(H-1,W-1)
    */
    
    
    for(int i=0;i<n;i++){//i=0が最初の壁, i=Nがゴールの壁
        ll tmp=0;
        auto [wiy,wix]=wall[i];
        
        for(int j=0;j<i;j++){
            // wall[j]<wall[i]
            
            auto [wjy,wjx]=wall[j];

            ll dx=wix-wjx;//
            ll dy=wiy-wjy;
            //cout<<"dx="<<dx<<",dy="<<dy<<endl;

            if(dx<0 || dy<0) continue;
            // (dx+dy) C dx
            
            
            //障害物jからiへいく
           tmp += dp[j]*comb(dx+dy,dx)%MOD;
           tmp%=MOD;
        }
       
        //cout<<"wix="<<wix<<",wiy="<<wiy<<endl;
        //(1,1)から(H,W)へは (H-1+W-1) C (H-1)とおり
        dp[i]=(comb(wiy+wix-2,wiy-1)-tmp+MOD)%MOD;

    }
   

    cout<<dp[n-1]<<endl;
    //cout<<dp[N+1]<<endl;

  


}