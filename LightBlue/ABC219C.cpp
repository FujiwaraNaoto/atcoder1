#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD=998244353;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
typedef pair<int,int> P;

int main(){
    string X;
    int N;
     cin>>X;
    cin>>N;
    vector<string> S(N);
   
    for(int i=0;i<N;i++){
        cin>>S[i];
    }

    sort(S.begin(),S.end(),
    [&](const string& lhs,const string& rhs){
        for(int i=0;i<min(lhs.size(),rhs.size());i++){
            if(lhs[i]==rhs[i]) continue;
            else{
                return X.find(lhs[i])<X.find(rhs[i]);
            }
        }

        return lhs.size()<rhs.size();
    });

    for(int i=0;i<N;i++){
        cout<<S[i]<<endl;
    }

}