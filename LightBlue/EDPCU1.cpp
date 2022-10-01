/*
educational dp contenst U
*/

/*
模範解答
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;


vector<vector<ll>> a;


ll f(int S,int sub,int n){
    vector<int> s_idx,sub_idx;

    

    for(int i=0;i<n;i++){
        if((S>>i)&1){
            s_idx.push_back(i);
        }
    }

    for(int i=0;i<n;i++){
        if((sub>>i)&1){
            sub_idx.push_back(i);
        }
    }

    ll ret=0;
    /*
    if(s_idx.empty()){
        for(int i=0;i<sub_idx.size();i++){
            for(int j=i+1;j<sub_idx.size();j++){
                ret+=a[i][j];
            }
        }
        return ret;
    }

    if(sub_idx.empty()){
        for(int i=0;i<s_idx.size();i++){
            for(int j=i+1;j<s_idx.size();j++){
                ret+=a[i][j];
            }
        }
        return ret;
    }
    */


    for(int i:s_idx){
        for(int j:sub_idx){
            ret+=a[i][j];
        }
    }

    return ret;

}

int main(){
    int N;
    cin>>N;
    a = vector<vector<ll>>(N,vector<ll>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }

    
    //vector<ll> dp(1<<N,-INF);
    //dp[0]=0;
     
    vector<ll> dp(1<<N,0),cst(1<<N,0);

    for(int S=0;S<(1<<N);S++){
        ll tmp=0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if( ((S>>i)&1) && ((S>>j)&1) ){
                    tmp+=a[i][j];
                }
            }
        }
        cst[S]=tmp;
    }

   

    for(int S=0;S<(1<<N);S++){//
        for(int sub=S;sub>0;sub=S&(sub-1)){
            //空集合とS自身を除くので
            //cout<<"S="<<S<<",sub="<<sub<<endl;

            //if(sub==S || sub==0) continue;

            dp[S]=max(dp[S],dp[S-sub]+cst[sub]);

        }
        
    }

    cout<<dp[(1<<N)-1]<<endl;


}