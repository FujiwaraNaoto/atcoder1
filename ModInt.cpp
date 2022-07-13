#include<sstream>
#include<iostream>
using namespace std;

class ModInt{
    long long x;
public:
    static const long long modint=998244353;

    ModInt(long long x_):x(x_){

        if(x>=0){
            x=x%modint;
        }else{
            //負の場合. 0以上にする操作を行う
            x=x%modint;
            x=(x+modint)%modint;
        }
    };
    ModInt():x(0){};

    ModInt& operator=(long long x_){
        x=(ModInt)x_
        
    }

  
    ModInt& operator*=(const ModInt& arg){
        
        x=x*arg.x;
        return *this;
    } 

    ModInt& operator/=(const ModInt& arg){
        
    }

    ModInt& operator+=(const ModInt& arg){
        x=(x+arg.x)%modint;
        return *this;
    }

    ModInt& operator-=(const ModInt& arg){
        x=(x-arg.x+modint)%modint;
        return *this;
    }



    //静的でないメンバー参照は特定のオブジェクトを基準とする相対参照である必要があります    
    // static long long modint=998244353; とすればよいかな
    friend ModInt operator+(const ModInt& arg1,const ModInt& arg2){
        return ModInt((arg1.x+arg2.x)%modint);
    }

    friend ModInt operator-(const ModInt& arg1,const ModInt& arg2){
        return ModInt((arg1.x-arg2.x+modint)%modint);

    }

    friend ModInt operator*(const ModInt& arg1,const ModInt& arg2){
        return (arg1.x*arg2.x)%modint;
    }

    friend ModInt operator/(const ModInt& arg1, const ModInt& arg2){
        ModInt inv=div();

        return arg1*inv%modint;
    }

    //等しいかどうか
    friend bool operator==(const ModInt& arg1, const ModInt& arg2){
        return (arg1.x==arg2.x);
    }

    //等しくないかどうか
    friend bool operator!=(const ModInt& arg1, const ModInt& arg2){
        return !(arg1==arg2);
    }

    
    ModInt modpow(const ModInt& arg1,long long n){
        //arg1^n
        if(modint==1){
            return 0;
        }

        ModInt ret=1;
        while(n>0){
            if(n&1){
                ret*=arg1;
            }
            arg1*=arg1;
            n>>=1;
        }

        return ret;

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

    ModInt ModInv(ModInt x){
        //逆数
        if(x%modint==)
        return modpow(x,modint-2);        

    }




};

/*
inline std::ostream<<(ostream&s) 
*/



int main(){

}