/*
AC
王道のやりかた
O(N √Amax ) 
*/
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int INF=1<<30;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N=2*100000;
/*
set<int> prime(){
    vector<bool> is_prime(MAX_N+1,true);
    is_prime[0]=is_prime[1]=false;
    set<int> ret;

    for(int p=2;p<=MAX_N;p++){
        if(is_prime[p]){
            ret.insert(p);
            for(int i=2*p;i<=MAX_N;i+=p){
                is_prime[i]=false;
            }
        }
    }
    

    return ret;
}
*/

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    map<int,ll> mp;
    vector<vector<int>> div(MAX_N+1,vector<int>{});
    for(int i=0;i<N;i++){
        cin>>A[i];
        mp[A[i]]++;
    }

    vector<vector<int>> division(N,vector<int>{});

    for(int i=0;i<N;i++){
        for(int k=1;1LL*k*k<=A[i];k++){
            if(A[i]%k==0){
                division[i].push_back(k);

                if(A[i]/k!=k){
                    division[i].push_back(A[i]/k);
                }
            }
        }
    }

    ll ans=0;
    for(int i=0;i<N;i++){
        for(int p:division[i]){
            //A[i]はpで割ることができる
            //pが合成数の場合も考えられている
            ans+=mp[A[i]/p]*mp[p];
        }
    }

    cout<<ans<<endl;
    

}