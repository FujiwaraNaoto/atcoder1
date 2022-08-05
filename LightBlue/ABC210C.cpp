/*
尺取り法 クリア
*/
#include<iostream>
#include<map>
#include<numeric>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    int N,K;
    cin>>N>>K;
    vector<int> c(N);
    for(int i=0;i<N;i++)cin>>c[i];

    int l=0,r=0;
    int ans=0;
    
    set<int> st;
    //[l,r]=K つまりr-l+1==K
    map<int,int> mp;
    int cnt=0;
    while(l<N){
        
        while(r<N && r-l+1<=K){
            //r-l+1==Kで終了 このときはrがはいるs
            //r個目を入れることを考える
           
            mp[c[r]]++;
            if(!st.count(c[r])){
                st.insert(c[r]);
                cnt++;
            }
            r++;
        }

        ans=max(ans,cnt);
        if(mp[c[l]]==1){
            st.erase(c[l]);
            cnt--;
        }
        mp[c[l]]--;

        l++;



    }

    cout<<ans<<endl;
}