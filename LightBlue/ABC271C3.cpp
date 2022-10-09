/*
二分探索でAC
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll INF=1LL<<60;

int main(){
    int N;
    cin>>N;

    vector<int> a(N);
    vector<bool> read(N+2,false);
    int sz=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(a[i]>N || read[a[i]])sz++;
        else{
            read[a[i]]=true;
        }
    }
    vector<int> sum(N+2,0);//累積和
    for(int i=N;i>=0;i--){
        //i巻目を読むことができる
        sum[i]=sum[i+1]+(read[i]?1:0);
    }

    //lbは読めるがubが読めない
    int lb=0,ub=N+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;//midを読むことができるかどうか
        int cnt=0;
        for(int i=1;i<=mid;i++){
            if(read[i]) continue;
            else{
                cnt+=2;
            }
        }
        if(cnt<=(sum[mid+1]+sz)){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    cout<<lb<<endl;
    //cout<<(lb==0 ? -1:lb)<<endl;


}