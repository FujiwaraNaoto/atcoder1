/*
AC
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<ll> div(ll x){
    vector<ll> vec;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            vec.push_back(i);
            if(x/i!=i) vec.push_back(x/i);
        }
    }
    
    return vec;
}

int main(){
    ll N;
    cin>>N;
    vector<ll> prime=div(N);
    sort(prime.begin(),prime.end());
    for(ll x:prime){
        cout<<x<<endl;
    }
    return 0;

}