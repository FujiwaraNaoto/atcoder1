

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve{
    int n;
    vector<int> f,primes; 
    //primesにはn以下の素数が入る
    //f[i]には最初に iが2以上の数字で,最初に何で割り切れたのかを入れる
    Sieve(int n=1):n(n), f(n+1){
        //エラトステネスの篩を行なっている
        f[0]=f[1]=-1;
        for(ll i=2;i<=n;i++){
            if(f[i]) continue;
            primes.push_back(i);//素数
            f[i]=i;
            
            //これでも通用する普通は for(ll j=2*i;j<=n;j+=i)だけど
            for(ll j=i*i;j<=n;j+=i){
                if(!f[j]) f[j]=i;
            }
        }
    }

    //xの素因数分解
    vector<int> factorList(int x){
        vector<int> res;
        while(x!=1){
            res.push_back(f[x]);//f[x]はxが最初に何で割り切れたのかを記すものが入っている
            x /= f[x];
        }
        return res;
    }

    // 
    vector<P> factor(int x){
        vector<int> fl = factorList(x);
        if(fl.size()==0) return {};//xが約数を持たない場合
        vector<P> res(1,P(fl[0],0));//resの要素1で pair<int,int>(fl[0],0)
        for(int p: fl){
            //res.back()で後ろ側の要素から見ていく
            if(res.back().first==p){
                res.back().second++;//pの二乗以上 の要素がある場合 例えば 12=2^2 * 3とか
            }else{
                res.emplace_back(p,1);
            }
        }
        return res;
    }

    vector<int> divisor2(int x){
        auto ps=factor(x);
        vector<int> res = {1};
        for(auto [p,_]: ps){//xがpを因数に持つ　
            for(int i=res.size()-1; i>=0; i--){
                res.push_back(res[i]*p);//約数の列挙かな? 厳密な約数の列挙ではないけど
            }
        }
        res.erase(res.begin());//約数の中でも　1　を除ける
        return res;
    }
};