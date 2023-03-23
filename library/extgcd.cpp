#include<iostream>
#include<tuple>


//[g,x,y], ax+by=g
std::tuple<long long,long long,long long> extgcd(long long a,long long b){
    
    long long d=a;

    if(b!=0){

        auto [d,x,y]=extgcd(b,a%b);
        return std::make_tuple(d,y,x-(a/b)*y);

    }else{

        return std::make_tuple(d,1,0);
    }

}