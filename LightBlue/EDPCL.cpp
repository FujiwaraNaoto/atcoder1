/*
map を使用するとTLE 

memoならAC
*/
#include<iostream>
#include<vector>
#include<tuple>
#include<map>
using namespace std;
typedef long long ll;
typedef tuple<int,int> TP;
typedef pair<int,int> P;
vector<ll> a;
int N;

map<P,ll> memo;



ll memo2[3005][3005];

bool isVisit[3005][3005];
/*
ll dfs(int l=0,int r=N-1){

    if(l>r) return 0;
    int cnt=l+(N-1-r);

    if(memo.count(make_pair(l,r))) return memo[make_pair(l,r)];
    
    if(cnt%2==0){
        return memo[make_pair(l,r)] = max( dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
    }else{
        //turn==1
        return memo[make_pair(l,r)] = min( dfs(l+1,r)-a[l],dfs(l,r-1)-a[r]);
    }   
}
*/

ll dfs(int l=0,int r=N-1){

    if(l>r) return 0;
    if(isVisit[l][r])return memo2[l][r];

    isVisit[l][r]=true;
    int cnt=l+(N-1-r);

    if(cnt%2==0){
        return memo2[l][r] = max( dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
    }else{
        //turn==1
        return  memo2[l][r]  = min( dfs(l+1,r)-a[l],dfs(l,r-1)-a[r]);
    }
    
}




int main(){
    
    cin>>N;
    a = vector<ll>(N);
    for(int i=0;i<N;i++) cin>>a[i];

    cout<<dfs()<<endl;


}