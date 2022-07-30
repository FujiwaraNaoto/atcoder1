/*
最大の桁数を目指す
*/
#include<cmath>
#include<queue>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1LL<<60;
typedef pair<ll,int> P;

int main(){
    ll N;
    cin>>N;
    
    vector<int>x;
    vector<P> C;
    vector<ll> cost(10);

    ll c;
    ll mincost=1LL<<60;
    for(int i=1;i<=9;i++){
        cin>>c;
        cost[i]=c;
        mincost = min(c,mincost);
        C.emplace_back(i,c);//cost index
    
    }
   
    int digitnum=N/mincost;// N/mincostを超えない最大の整数
    for(int len = digitnum;len>0;len--){
        for(int i=9;i>=1;i--){
            if( N>=cost[i] && (N-cost[i])/mincost==(len-1)){
                x.push_back(i);
                N-=cost[i];
                break;
            }
        }
    }
    
    
    if(x.size()==0){
        cout<<0<<endl;
    }else{
        for(int c:x){
            cout<<c;
        }
        cout<<endl;

    }

}