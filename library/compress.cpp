#include<iostream>
#include<vector>
#include<set>
#include<map>

//座圧
//重複した要素あった時に使える?
void comp(std::vector<int>& x){
    std::set<int>s(x.begin(),x.end());
    std::map<int,int> mp;

    int cnt=0;
    for(int p:s){
        mp[p]=cnt++;
    }

    for(auto& p: x){
        p=mp[p];
    }
}


//座標圧縮
template <class T> struct compress{
    
    std::set<T> st;
    std::map<T,int> mp;
    int sz;
    compress(const std::vector<T>& a):sz(0){
        for(auto x:a){
            st.insert(x);
        }
        
        for(auto x:st){
            mp[x]=sz++;
        }
    }

    int val(const T& x){
        //ベクトルaの要素xに対応した要素を取り出す
        return mp[x];
    }

    int size(){
        return sz;
    }

};