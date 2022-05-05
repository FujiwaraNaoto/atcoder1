

// 特殊な剰余と原始根
// (924844033, 5)
// (998244353, 3)
// (1012924417, 5)
// (167772161, 3)
// (469762049, 3)
// (1224736769, 3)
 
#define MOD 998244353
#define root 3
typedef long long ll;
 
unsigned int add(const unsigned int x, const unsigned int y)
{
    return (x + y < MOD) ? x + y : x + y - MOD;
}
 
unsigned int sub(const unsigned int x, const unsigned int y)
{
    return (x >= y) ? (x - y) : (MOD - y + x);
}
 
unsigned int mul(const unsigned int x, const unsigned int y)
{
    return (unsigned long long)x * y % MOD;
}
 
unsigned int mod_pow(unsigned int x, unsigned int n)
{
    unsigned int res = 1;
    while(n > 0){
        if(n & 1){ res = mul(res, x); }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
 
unsigned int inverse(const unsigned int x)
{
    return mod_pow(x, MOD - 2);
}
 
void ntt(vector<int>& a, const bool rev = false)
{
    unsigned int i, j, k, l, p, q, r, s;
    const unsigned int size = a.size();
    if(size == 1) return;
    vector<int> b(size);
    r = rev ? (MOD - 1 - (MOD - 1) / size) : (MOD - 1) / size;
    s = mod_pow(root, r);
    vector<unsigned int> kp(size / 2 + 1, 1);
    for(i = 0; i < size / 2; ++i) kp[i + 1] = mul(kp[i], s);
    for(i = 1, l = size / 2; i < size; i <<= 1, l >>= 1){
        for(j = 0, r = 0; j < l; ++j, r += i){
            for(k = 0, s = kp[i * j]; k < i; ++k){
                p = a[k + r], q = a[k + r + size / 2];
                b[k + 2 * r] = add(p, q);
                b[k + 2 * r + i] = mul(sub(p, q), s);
            }
        }
        swap(a, b);
    }
    if(rev){
        s = inverse(size);
        for(i = 0; i < size; i++){ a[i] = mul(a[i], s); }
    }
}
 
 //こいつが大事
vector<int> convolute(const vector<int>& a, const vector<int>& b)
{
    const int size = (int)a.size() + (int)b.size() - 1;
    int t = 1;
    while(t < size){ t <<= 1; }
    vector<int> A(t, 0), B(t, 0);
    for(int i = 0; i < (int)a.size(); i++){ A[i] = a[i]; }
    for(int i = 0; i < (int)b.size(); i++){ B[i] = b[i]; }
    ntt(A), ntt(B);
    for (int i = 0; i < t; i++){ A[i] = mul(A[i], B[i]); }
    ntt(A, true);
    A.resize(size);
    return A;
}




/*
NTTクラス
*/

class NTT{

    private:
        ll MOD;
        const ll root=3;
        ll add(const ll x, const ll y)
        {
            return (x + y < MOD) ? x + y : x + y - MOD;
        }
        
        ll sub(const ll x, const ll y)
        {
            return (x >= y) ? (x - y) : (MOD - y + x);
        }
        
        ll mul(const ll x, const ll y)
        {
            return x * y % MOD;
        }
        
        ll mod_pow(ll x, ll n)
        {
            ll res = 1;
            while(n > 0){
                if(n & 1){ res = mul(res, x); }
                x = mul(x, x);
                n >>= 1;
            }
            return res;
        }
        ll inverse(const ll x)
        {
            return mod_pow(x, MOD - 2);
        }


        void ntt(vector<ll>& a, const bool rev = false){

                unsigned int i, j, k, l, p, q, r, s;
                const unsigned int size = a.size();
                if(size == 1) return;
                vector<ll> b(size);
                r = rev ? (MOD - 1 - (MOD - 1) / size) : (MOD - 1) / size;
                s = mod_pow(root, r);
                vector<ll> kp(size / 2 + 1, 1);
                for(i = 0; i < size / 2; ++i) kp[i + 1] = mul(kp[i], s);
                for(i = 1, l = size / 2; i < size; i <<= 1, l >>= 1){
                    for(j = 0, r = 0; j < l; ++j, r += i){
                        for(k = 0, s = kp[i * j]; k < i; ++k){
                            p = a[k + r], q = a[k + r + size / 2];
                            b[k + 2 * r] = add(p, q);
                            b[k + 2 * r + i] = mul(sub(p, q), s);
                        }
                    }
                    swap(a, b);
                }
                if(rev){
                    s = inverse(size);
                    for(i = 0; i < size; i++){ a[i] = mul(a[i], s); }
                }
            }

    public:
        NTT(ll mod=998244353):MOD(mod){}; 

        //
        //vector<ll> c = ntt(a,b)みたいにして使う
        vector<ll> operator()(const vector<ll>& a, const vector<ll>& b){
            const int size = (int)a.size() + (int)b.size() - 1;
            ll t = 1;
            while(t < size){ t <<= 1; }

            vector<ll> A(t, 0), B(t, 0);
            
            for(int i = 0; i < (int)a.size(); i++){ A[i] = a[i]; }
            for(int i = 0; i < (int)b.size(); i++){ B[i] = b[i]; }
            
            ntt(A), ntt(B);
            for (int i = 0; i < t; i++){ A[i] = mul(A[i], B[i]); }
            ntt(A, true);
            A.resize(size);
            
            return A;
        }
};







//NTT
////////////////////////////////////////////
typedef long long ll;
#define MOD 998244353
#define root 3
 
ll add(const ll x, const ll y)
{
    return (x + y < MOD) ? x + y : x + y - MOD;
}
 
ll sub(const ll x, const ll y)
{
    return (x >= y) ? (x - y) : (MOD - y + x);
}
 
ll mul(const ll x, const ll y)
{
    return x * y % MOD;
}
 
ll mod_pow(unsigned ll x, ll n)
{
    ll res = 1;
    while(n > 0){
        if(n & 1){ res = mul(res, x); }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
 
ll inverse(const ll x)
{
    return mod_pow(x, MOD - 2);
}
 
void ntt(vector<ll>& a, const bool rev = false)
{
    unsigned int i, j, k, l, p, q, r, s;
    const unsigned int size = a.size();
    if(size == 1) return;
    vector<ll> b(size);
    r = rev ? (MOD - 1 - (MOD - 1) / size) : (MOD - 1) / size;
    s = mod_pow(root, r);
    vector<ll> kp(size / 2 + 1, 1);
    for(i = 0; i < size / 2; ++i) kp[i + 1] = mul(kp[i], s);
    for(i = 1, l = size / 2; i < size; i <<= 1, l >>= 1){
        for(j = 0, r = 0; j < l; ++j, r += i){
            for(k = 0, s = kp[i * j]; k < i; ++k){
                p = a[k + r], q = a[k + r + size / 2];
                b[k + 2 * r] = add(p, q);
                b[k + 2 * r + i] = mul(sub(p, q), s);
            }
        }
        swap(a, b);
    }
    if(rev){
        s = inverse(size);
        for(i = 0; i < size; i++){ a[i] = mul(a[i], s); }
    }
}
 
 //こいつが大事
vector<ll> convolute(const vector<ll>& a, const vector<ll>& b)
{
    const int size = (int)a.size() + (int)b.size() - 1;
    int t = 1;
    while(t < size){ t <<= 1; }
    vector<ll> A(t, 0), B(t, 0);
    for(int i = 0; i < (int)a.size(); i++){ A[i] = a[i]; }
    for(int i = 0; i < (int)b.size(); i++){ B[i] = b[i]; }
    ntt(A), ntt(B);
    for (int i = 0; i < t; i++){ A[i] = mul(A[i], B[i]); }
    ntt(A, true);
    A.resize(size);
    return A;
}

