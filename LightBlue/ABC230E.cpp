#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    ll ans=0;
    
    
    ll k=N;
    while(k>0){
        // (N/(k+1),N/k]
        ll num=N/k-N/(k+1); // [N/i]=kとなるiの数
        ans+=k*num;
        
        k=N/(N/k+1);//次のk
    }

    cout<<ans<<endl;

}
