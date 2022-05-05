//AC

#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin>>N;

    set<ll> st;

    for(ll a=2;a*a<=N;a++){
        ll ab = a*a;
        while(true){
            st.insert(ab);
            ab*=a;
            if(ab>N) break;

        }
    }
    cout<<N-st.size()<<endl;
}