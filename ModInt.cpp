#include<sstream>
#include<iostream>


class ModInt{
    long long x;
public:
    const long long int modint=998244353;

    ModInt(long long x_):x(x_){};
    ModInt():x(0){};

    ModInt& operator=(long long x_){
        x=(ModInt)x_
        
    }

    //静的でないメンバー参照は特定のオブジェクトを基準とする相対参照である必要があります    
    friend inline ModInt operator+(const ModInt& arg1,const ModInt& arg2){
        return ModInt((arg1.x+arg2.x)%modint);
    }

    friend inline ModInt operator+(const ModInt& arg1,const ModInt& arg2){
        return ModInt((arg1.x-arg2.x+modint)%modint);

    }

    friend inline ModInt operator*(const ModInt& arg1,const ModInt& arg2){

    }


    ModInt modpow(const ModInt& arg1,ll n){
        //x^n
        if(modint==1){
            return 0;
        }
        ModInt ret=1;

        ll 

    }

    ModInt modpow(const long long  arg1,long long  n){
        //x^n
        if(modint==1){
            return 0;
        }
        long long  ret=1;

        long long p=arg1%modint;
        while(n>0){
            if(n&1){
                ret=ret*p%modint;
            }
            p=p*p%modint;
            n>>=1;
        }

    }


};
