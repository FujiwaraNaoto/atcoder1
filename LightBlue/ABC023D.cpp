/*
模範解答
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    vector<ll> H(N),S(N);
    for(int i=0;i<N;i++){
        cin>>H[i]>>S[i];
    }

    ll ub=1LL<<50;//このときは必ずOK
    ll lb=0;

    while((ub-lb)>1){
        ll mid = (ub+lb)/2;
        bool flag=false;
        vector<ll> tm(N);
        for(int i=0;i<N;i++){
            ll t;
            if((mid-H[i])<0) flag=true;
            tm[i]=(mid-H[i])/S[i];
           
        }
        sort(tm.begin(),tm.end());
        for(int i=0;i<N;i++){//風船全部を割る場合にはN-1秒かかる
            // tm[i]=>iとなるべき
            // 時刻iまででi+1個までしか割ることができない故
            if(tm[i]<i) flag=true;//被る者があるとまずい
        }
        //時間は単調増加になるべき　当然正の値

        if(flag){
            //もう少し制限高さを高くする
            lb=mid;
        }else{
            ub=mid;//もう少し低くしてみる
        }

    }

    cout<<ub<<endl;


}