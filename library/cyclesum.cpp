//ABC179E
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<numeric>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,int> P;
typedef pair<int,P> PP;
const ll MOD=1e9+7;



ll f(ll n,ll m){
    n%=m;

    return n*n%m;
}




int main(){
    ll N,X,M;
    cin>>N>>X>>M;

    /*
    初項X(1番目), 漸化式f,項数N(1-index)のときの　1~N項の総和
    
    */

    map<ll,int> mp;
    vector<ll> cycleorder;
    vector<ll> history;

    ll now=X;
    ll nowend=-1;

    int idx=0;
    while(1){       
        if(mp.count(now)){
            int p=mp[now];
            
            for(int i=p;i<idx;i++){
                cycleorder.push_back(history[i]);
            }

            nowend=now;
            break;
        }
        mp[now]=idx;
        idx++;

        history.push_back(now);
        now = f(now,M);
    }

   

    int cyclelen=cycleorder.size(),offsetlen=history.size()-cycleorder.size();
  
  

    vector<ll> historycumsum(history.size()+1,0);
    historycumsum[0]=0;
    for(int i=0;i<history.size();i++){
        historycumsum[i+1]=historycumsum[i]+history[i];
    }


    vector<ll> cyclecumsum(cyclelen+1,0);// cyclecumsum[i]= cycleorder[0]~cycleorder[i-1]の和
    cyclecumsum[0]=0;
    for(int i=0;i<cyclelen;i++){
        cyclecumsum[i+1]=cyclecumsum[i]+cycleorder[i];
    }

    
       
        ll t=(N-offsetlen)/cyclelen;

        ll r=(N-offsetlen)%cyclelen;

        ll ans=0;
        
        ans+=historycumsum[offsetlen];
        
        ans+=t*cyclecumsum.back();

        
        ans+=cyclecumsum[r];
        
        
        cout<<ans<<endl;








}