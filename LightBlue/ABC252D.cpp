/*
真ん中を決め打ちで全探索
Sunuke festival
AC
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const ll INF = 1LL<<60;


int main(){
    int N;
    cin>>N;
    
    vector<int> A(N);
    map<int,int>mp;
    set<int> st;
    for(int i=0;i<N;i++){
        cin>>A[i];
        st.insert(A[i]);
    }

    int cnt=0;
    for(int s:st){
        mp[s]=cnt++;
    }
    vector<int> cnt2(cnt+1,0);

    for(int i=0;i<N;i++){
        A[i]=mp[A[i]];
        cnt2[A[i]]++;
    }
    vector<int> cntsum(cnt+1,0);

    cntsum[0]=cnt2[0];
    for(int i=1;i<=cnt;i++){
        cntsum[i]=cnt2[i]+cntsum[i-1];
    }

    ll ans=0;
    for(int i=1;i<=cnt;i++){//真ん中を決め打ちで全探索
        ans+=1LL*cntsum[i-1]*cnt2[i]*(N-cntsum[i]);
    }
    
    cout<<ans<<endl;


}