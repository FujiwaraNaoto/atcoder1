/*
g++ ABC270D3.cpp -o p -o2

AC

*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1<<30;

map<P,int> memo;

int K;
vector<int> A;

int dfs(int turn,int remain){
    if(remain==0) return 0;

    if(memo.count(P{turn,remain})) return memo[P{turn,remain}];

    if(turn==0){
        int ret=-INF;
        for(int j=0;j<K;j++){
            if(remain-A[j]>=0){
                ret=max(dfs(1,remain-A[j])+A[j],ret);
            }
        }
        return memo[P{turn,remain}]=ret;
    }else{

        //turn=1
        int ret=INF;
         for(int j=0;j<K;j++){
            if(remain-A[j]>=0){
                ret=min(dfs(0,remain-A[j]),ret);
            }
        }
        return memo[P{turn,remain}]=ret;


    }
    
}

int main(){
    int N;
    cin>>N>>K;
    A=vector<int>(K);
    for(int i=0;i<K;i++){
        cin>>A[i];
    }

    int ans=dfs(0,N);
    cout<<ans<<endl;
/*
  
*/

}
