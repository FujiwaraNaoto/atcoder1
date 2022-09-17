/*
倍数
計算量は ざっくり見積もってO(NlogN)
AC
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<59;
const int MAX_N=200000;

vector<vector<int>> d(200000+1,vector<int>{});



void init2(){
    for(int i=1;i<=MAX_N;i++){
        for(int k=i;k<=MAX_N;k+=i){
            d[k].push_back(i);//kの約数を列挙していく.　前計算でO(NlogN)
        }
    }
}


int main(){


    int N;
    cin>>N;
    vector<int> A(N);
    map<int,int> mp;
    for(int i=0;i<N;i++){
        cin>>A[i];
        mp[A[i]]++;
    }

    init2();

    ll ans=0;
    /*
    for(size_t i=0;i<N;i++){
        for(int t: d[A[i]]){
            if(mp.count(t)){
                ans += 1LL*mp[t]*mp[A[i]/t];

            }
        }
    }
    */

    
    for(auto [c,_]:mp){
        for(int t :d[c]){
            //cはtで割れる
            if(mp.count(t) && mp.count(c/t)){
                //cout<<"c="<<c<<",t="<<t<<",c/t="<<c/t<<endl;
                //cout<<1LL*mp[t]*mp[c]*mp[c/t]<<endl;
                ans+=1LL*mp[t]*mp[c]*mp[c/t];
            }
        
        }
    }
    

    cout<<ans<<endl;

}