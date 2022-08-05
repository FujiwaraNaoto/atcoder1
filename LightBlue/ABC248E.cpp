/*
模範解答
Infinityのコーナーケースに注意
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD=998244353;

ll gcd(ll x,ll y){
    if(y==0)return x;
    else return gcd(y,x%y);
}


int main(){
    int N,K;
    cin>>N>>K;
    
    vector<ll> x(N),y(N);
    for(int i=0;i<N;i++)cin>>x[i]>>y[i];

    if(K==1){
        cout<<"Infinity"<<endl;
        return 0;
    }
    map<tuple<ll,ll,ll>,int> mp;

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            //iとjで作った直線について考える
            
                
                ll b=y[j]-y[i];
                ll a=x[j]-x[i];
                if(a<0){
                    a=a*(-1);
                    b=b*(-1);
                }
                if(a==0){
                    b=1;
                }else{
                    //a>0 bは負の可能性あり
                    ll g=gcd(a,b);
                    a/=g; b/=g;
                }



            ll c=a*y[i]-b*x[i];
            /*
            これは iとjで作った直線に対して固有なものになる.
            というのも　(x[i]+a*k,y[i]+b*k)もこの点にたいして同一のcが得られる.
            */
           mp[{a,b,c}]++;

        }
    }

    ll ans=0;
    for(auto p:mp){
        ll cnt=p.second;
        //cout<<"cnt="<<cnt<<endl;
        if(cnt>=(1LL*K*(K-1)/2)) ans++;
    }
    cout<<ans<<endl;
   

}