//https://qiita.com/drken/items/ae02240cd1f8edfc86fd
//中国剰余定理

inline long long  mod(long long  a,long long m){
    return (a%m+m)%m;
}


long long  extGcd(long long  a,long long  b,long long& x,long long& y){
    long long  d=a;
    if(b!=0){
        d=extGcd(b,a%b,y,x);
        y-=(a/b)*x;
    }else{
        x=1;y=0;
    }

    return d;
}



// x ≡ bi (mod mi)
// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
std::pair<long long, long long> ChineseRem(const std::vector<long long> &b, const std::vector<long long> &m) {
  long long r = 0, M = 1;
  for (int i = 0; i < (int)b.size(); ++i) {
    long long p, q;
    long long d = extGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
    if ((b[i] - r) % d != 0) return std::make_pair(0, -1);
    long long tmp = (b[i] - r) / d * p % (m[i]/d);
    r += M * tmp;
    M *= m[i]/d;
  }
  return std::make_pair(mod(r, M), M);
}






/*

x ≡ b1 (mod m1)
x ≡ b2 (mod m2)
を解く

return first= xの解
return second= mod

*/
std::pair<long long,long long> chinese_rem(long long b1,long long m1,long long b2, long long m2){
    
    //d=m1*p+m2*q
    auto [d,p,q] = ext_gcd(m1,m2);


    long long lcm=(m1/d)*m2;
    
    if((b2-b1)%d !=0){
        //(r,m)  = r (mod m)
        return std::make_pair(0,-1);
    }

    long long c=(b2-b1)/d;
   
   
    c*=p;

    c%=(m2/d);
    c*=m1;
    c%=lcm;

    long long x=b1+c;
    x%=lcm;
    x+=lcm;
    x%=lcm;

    return std::make_pair(x,lcm);
};



long long gcd(long long x,long long y){
    return y==0?x:gcd(y,x%y);
}

long long lcm(long long x,long long y){

    return x/gcd(x,y)*y;
}


std::pair<long long,long long> chinese_rem2(const std::vector<long long>& b,const std::vector<long long>& m){

    std::assert(b.size()==m.size());
    int n=b.size();

    long long x=0;
    long long M=1;
    for(int i=0;i<n;i++){
        
        auto [c,flag]=chinese_rem(x,M,b[i],m[i]);
        if(flag==-1){
            return make_pair(0,-1);
        }

        M=lcm(M,m[i]);
        x=c;
        
    }
    
    return make_pair((x%M + M)%M ,M);
}

