/*
第一回アルゴリズム実技検定 G

再帰を用いた全探索 INFにすることに気を付ける
AC
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

vector<vector<ll>> A;

vector<vector<int>> points(3,vector<int>{});

int N;

ll calc(){
    
    ll ret=0;

    for(int i=0;i<3;i++){
        int n = points[i].size();
        
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                int n1 = points[i][j];
                int n2 = points[i][k];
                ret += A[n1][n2];//n1とn2のペア
            }
        }

    }     

    return ret;
}




ll dfs(int id){

    if(id==N){
        return calc();
    }

    ll ret=-INF;

    for(int k=0;k<3;k++){
        points[k].push_back(id);
        ret = max(ret,dfs(id+1));
        points[k].pop_back();
    }
    return ret;

}


int main(){
    
    cin>>N;

    A = vector<vector<ll>>(N,vector<ll>(N,0));

    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            cin>>A[i][j];
            A[j][i]=A[i][j];
        }
    }

    ll ans = dfs(0);

    

    cout<<ans<<endl;

    

}
