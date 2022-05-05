//最小公倍数問題
// AC
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y){
    //x>y
    if(y==0)return x;
    else {
        return gcd(y,x%y);
    }
}

ll lcm(ll x,ll y){
    return x/gcd(x,y) * y;
}

int main(){
    ll A,B;
    cin>>A>>B;

    ll ans = lcm(A,B);

    cout<<ans<<endl;
}