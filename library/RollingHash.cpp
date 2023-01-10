/*
ローリングハッシュ
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<cassert>

class RollingHash{

    long long  gcd(long long  x,long long  y){
        return y?gcd(y,x%y):x;
    }

    public:

        std::vector<long long> h; 
        std::vector<long long> powBase;
        int len;
        std::string str;
        long long mod;
        long long base;
        RollingHash(const std::string& str,long long  base_,long long  mod_):base(base_),mod(mod_){
            len=str.size();
            h = std::vector<long long>(len+1,0);
            powBase = std::vector<long long>(len+1,0);


            assert(gcd(base_,mod_)==1);
            h[0]=0;
            for(int i=1;i<=len;i++){
                h[i]=(h[i-1]*base%mod + (int)str[i-1])%mod; 
            }

            powBase[0]=1;
            for(int i=1;i<=len;i++){
                powBase[i]=powBase[i-1]*base%mod;
            }


        }

        RollingHash(const std::string& str){
            RollingHash(str,1e6+7,1e9+7);
        }



        long long  get_hash(int idx){
            assert(0<=idx && idx<len);
            return h[idx+1];
        }

        long long pow(int i){
            assert(0<=i && i<=len);
            return powBase[i];
        }

        //0-indexed [l,r]
        long long  get_hash(int l,int r){
            assert(0<=l && r<len);
            assert(l<=r);

            l++;r++;//1 indexに調節
            // h[r] - h[l-1]
            return (h[r] - (powBase[r-l+1]*h[l-1])%mod + mod)%mod;
        }

        long long getBase()const{
            return base;
        }

        long long getMod()const{
            return mod;
        }

        std::string getString()const{
            return str;
        }

        //[l,r]
        std::string getString(int l,int r)const{
            return str.substr(l,r-l+1);
        }


};

