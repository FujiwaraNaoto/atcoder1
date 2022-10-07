/*

dp[h[i]] = max((dp[ 1~(h[i]-1) ]までのmax)+a[i], dp[h[i]])

(dp[ 1~(h[i]-1) ]までのmax)はbinary indexed treeで考える.

AC

*/
#include<iostream>
#include<vector>
#include<tuple>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1LL<<60;

template<class Type> class BinaryIndexTree{
public:
    int bitsize;
    std::vector<Type> bit;

    BinaryIndexTree(int bitsize_):bitsize(bitsize_+1){
      bit=std::vector<Type>(bitsize+2,0);
    }
   ~BinaryIndexTree(){
     std::vector<Type>().swap(bit);
   }
    
    //i番目の要素を更新　iは0から
    void update(int i,Type x){
        i+=1;//ここ大事 インデックスを1からに補正する
      while(i<bitsize){
        bit[i]=max(x,bit[i]);
        i+= i&-i;
      }
    }

   //0~iまでの中で最大値
    Type get(int i){
     Type ans=-INF;
     i+=1;
     while(i>0){
        ans=max(ans,bit[i]);
        i -= i&-i;
     }

     return ans;

    }
};


int main(){
    int N;
    cin>>N;
    vector<int> h(N),a(N);
    map<int,int> mp;
    for(int i=0;i<N;i++){
        cin>>h[i];
        mp[h[i]]=0;//高さは事前に座圧しておく.
    }
    for(int i=0;i<N;i++){
        cin>>a[i];
    }

    int sz=1;
    for(auto [x,_]:mp){
        mp[x]=sz++;
    }
    vector<P> flowers(N);
    for(int i=0;i<N;i++){
        flowers[i]=P{mp[h[i]],a[i]};
    }

    BinaryIndexTree<ll> bit(N+1);
    
    vector<ll> dp(N+1,0);
    for(int i=0;i<N;i++){
        auto [t,point] = flowers[i];

        //0 ~ t-1のなかで最大値
        ll tmp = bit.get(t-1)+point;
        if(tmp>dp[t]){
            dp[t]=tmp;
            bit.update(t,tmp);
        }

    }

    ll ans=0;
    for(int i=0;i<=N;i++){
        //cout<<"dp["<<i<<"]="<<dp[i]<<endl;
        ans=max(ans,dp[i]);
    }

    cout<<ans<<endl;




}