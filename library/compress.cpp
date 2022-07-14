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