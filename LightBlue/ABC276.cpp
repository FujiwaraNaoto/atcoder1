#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

int main(){
    int N;
    cin>>N;

    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i];
        P[i];
    }

   
    int idx=N-1;
    vector<int> perm;
    perm.push_back(P[N-1]);
    for(int n=N-2;n>=0;n--){
        if(P[n]<P[n+1]){
            perm.push_back(P[n]);
            idx=n;
        }else{//minP>P[n]
            break;
        }
    }
    idx--;
    //perm.push_back(P[idx]);
    //cout<<"idx="<<idx<<endl;

    sort(perm.begin(),perm.end());

    auto it=lower_bound(perm.begin(),perm.end(),P[idx]);
    it--;
    
    int tmp=*it;
    //cout<<"tmp="<<tmp<<endl;
    perm.erase(it);
    vector<int> ans;

    perm.push_back(P[idx]);

    for(int k=0;k<idx;k++){
        ans.push_back(P[k]);
    }

    ans.push_back(tmp);

    sort(perm.begin(),perm.end());
    reverse(perm.begin(),perm.end());

    for(int x:perm){
        ans.push_back(x);
    }

    for(int t=0;t<N;t++){
        cout<<ans[t]<<(t==N-1?'\n':' ');
    }

   


}