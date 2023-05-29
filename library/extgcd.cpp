#include<iostream>
#include<tuple>


//[g,x,y], ax+by=g
std::tuple<long long,long long,long long> ext_gcd(long long a,long long b){
    
    long long d=a;

    if(b!=0){

        auto [d,x,y]=ext_gcd(b,a%b);
        return std::make_tuple(d,y,x-(a/b)*y);

    }else{

        return std::make_tuple(d,1,0);
    }

}




//拡張ユークリッド互除法
long long int ext_gcd(long long int a, long long int b, long long int &x, long long int &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  long long int q = a / b;
  long long int g = ext_gcd(b, a-q*b, x, y);
  long long int z = x-q*y;
  x = y;
  y = z;
  return g;
}


long long int gcd(long long int x,long long int y){
    return (y==0?x:gcd(y,x%y));
}
 
 
//aとmは互いに素, a^(-1) mod m
long long int modinv(long long int a, long long int m) 
{
    if(gcd(a,m)!=1) return -1;//逆元が存在しない
    long long int x, y;
    ext_gcd(a, m, x, y);
    x %= m;
    if (x < 0)
        x += m;
    return x;
}