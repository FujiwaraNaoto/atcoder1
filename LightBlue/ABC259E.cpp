/*
模範解答
*/
#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
typedef pair<int,int> P;

int main(){
    int n;
    cin>>n;
    vector<vector<P>> pe(n);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int p,e;
            cin>>p>>e;
            pe[i].emplace_back(p,e);
        }
    }


    map<int,int> mx;//firstがsecond回かけられている
    for(int i=0;i<n;i++){
        for(auto [p,e]:pe[i]){
            mx[p]=max(mx[p],e);
        }
    }

    map<int,int> cnt;//数字firstがsecond回出現する 　単独maxかどうかの判定
    for(int i=0;i<n;i++){
        for(auto [p,e]:pe[i]){
            if(mx[p]==e){
                cnt[p]++;
            }  
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        bool ok=false;
        for(auto [p,e]:pe[i]){
            if(mx[p]==e && cnt[p]==1)ok=true;//i番目の数字が1になるとLCMが変化する
        }
        if(ok)ans++;
    }
    //消しても変わらないもの　が一つも存在しないときは+1してはいけない
    /* 例えば入力例1の場合　5(もしくは14)を消しても問題ない
    このときに
    2^2 * 5^1 * 7^2=980 でこれが+1の部分に相当する.


    ans=nのときはn個の整数aiすべてが素因数にmaxをもっている状態.
    aiが1になるたびに1種類生成される.
    */

    if(ans<n) ans++;
    cout<<ans<<endl;



}