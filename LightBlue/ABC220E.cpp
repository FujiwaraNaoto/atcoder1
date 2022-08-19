/*
模範解答 AC
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD=998244353;

int main(){
    int n,d;
    cin>>n>>d;
    vector<ll> f(n+1),g(n+1);//f[i]で

    vector<ll> two(n+1);
    two[0]=1;//2^0
    for(int i=0;i+1<=n;i++){
        two[i+1]=2*two[i];
        two[i+1]%=MOD;
    }
    //根を使うやつがg
    // g[i]=g[i-1]+(葉を使う場合のパスの総数)　をやりたいのである
    for(int i=1;i<=n;i++){
        int l=i-1,r=d-l;//dが深さ 左側が必ず葉となるケース
        ll leaf=0;//必ず片方は葉をつかうpath
        
        if(0<=r && r<=l){
            leaf=two[max(l-1,0)]*two[max(r-1,0)];
            leaf%=MOD;

            if(l!=r){//l==rの時は二倍しない
                leaf*=2;
                leaf%=MOD;
            }
        }

        g[i]=g[i-1]+leaf;//根をつかうpath
        g[i]%=MOD;
    }

    for(int i=1;i<=n;i++){
        //f[i]=f[i-1]*2+g[i]をやりたいのである
        f[i]=f[i-1]*2;
        f[i]%=MOD;
        f[i]+=g[i];
        f[i]%=MOD;

    }

    ll ans=f[n]*2;
    ans%=MOD;
    cout<<ans<<endl;
}