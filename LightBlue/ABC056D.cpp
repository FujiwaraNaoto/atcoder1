/*
ABC056D
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
    int N,K;
    cin>>N>>K;
    vector<ll> a(N);
    for(int i=0;i<N;i++) cin>>a[i];
    sort(a.begin(),a.end());

    ll ub=N-1;//すべて必要ない
    ll lb=0;//小さいほうから0枚のける.これが答えになる

    while((ub-lb)>=0){
        ll mid = (ub+lb)/2;
        
        // K-x 以上 K未満　である集合を作れるかどうか
        if(a[mid]>=K){//そもそもa[mid]はK以上ゆえ　必ず成立.
            ub=mid-1;    
            continue;
        }


        /*
        部分和問題に帰着. 
        {a[0],a[1],..,a[mid-1],a[mid+1],...,a[N-1]}のみ
        を使用することで　とりうることができる和の値がdp
        これはナップザック問題となる
        */
       /*
        vector<bool> dp(K,false);//0~K-1で考える
        dp[0]=true;//0枚選んで作れるゆえ
        */

        vector<vector<bool>> dp(N+1,vector<bool>(K,false));
        dp[0][0]=true;
        
        for(int i=0;i<N;i++){//i==N-1が終わり
            if(i==mid){
                dp[i+1]=dp[i];
               
                continue;
                
            }else{
                for(int j=0;j<K;j++){
                    if(dp[i][j]){
                        dp[i+1][j]=true;
                        if(j+a[i]<K){
                        dp[i+1][j+a[i]]=true;
                        }
                    }
                }
                
            }
            
        }

        

        for(int i=K-a[mid];i<K;i++){
            //a[mid]をはずすことができるかどうか
            // K-a[mid]<= i <K　となる fl[i]==trueが存在するかどうか
            if(dp[N][i]){
                //存在する場合,mid以上が必要なカードになる. つまりmid番目が減るため,-1
                ub=mid-1;
                break;
            }
            if(i==K-1){
                //mid以下の要素すべてが必要 midが含まれるため+1
                lb=mid+1;
            }
        }
    
    }
    cout<<lb<<endl;

}