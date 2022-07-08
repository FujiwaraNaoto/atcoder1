/*
BigIntクラスを作り上げる

bigint[nelem] のようにして,配列巨大なIntとみなす

//各々のメソッドに関して,完成 とつけるべし
*/
#include<vector>
#include<sstream>//for ostream and istream
#include<iostream>



class BigInt{
    typedef long long ll;
public:
    size_t nelem;//配列のサイズ
    std::vector<ll> bigint;
    ll base=1000;

    explicit BigInt(long long x){
        //明示的 costructor
        nelem=0;
        
        while(x>0){
            bigint.push_back(x%base);
            x/=base;
            nelem++;
        }
    }

    BigInt(){//何も引数無しの場合　
        //default constructor
        nelem=1;
        bigint.push_back(1LL*0);
    }


    BigInt(){
        //copy constructor
    }

    ~BigInt(){
        //destructor
        //メモリの解法
        std::vector<ll>().swap(bigint);


    }

    //代入演算子
    //a=bみたいにして用いる a.operator(b)を意味する
    BigInt& BigInt::operator=(const BigInt& x);


    operator<<(){
        //cin outにも対応できるようにする
    }


    operator<(){
        //比較演算子にも対応できるようにする

    }

    operator==(){
        //bitintが等しいかどうか
    }


    ostream& operator<<(ostream& s, const BigInt& x){
        //リトルエンディアンでならんでるけど...
        return s<<x.bigint;
        
    }

    istream& operator>>(istream& s,BigInt& x){
        //ここ,どうする?
        return s;
    }
}

//代入演算子 
//完成
BigInt& BigInt::operator=(const BigInt & x){

    //自己代入に対応できるようにする
    if(&x!=this){
        if(nelem!=x.nelem){
            std::vector<ll>().swap(bigint);//領域の解法
            nelem = x.nelem;
            bigint=std::vector<ll>(x.nelem); 
        }

        for(size_t i=0;i<nelem;i++){
            //endian 方式にするのか?
            bigint[i]=x.bigint[i];
        }
        
    }

    return *this;
}