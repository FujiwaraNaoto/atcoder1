
typedef long long ll;
ll gcd(ll x,ll y){

    return y ? gcd(y,x%y):x;
}
