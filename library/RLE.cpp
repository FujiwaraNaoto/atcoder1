/*
ランレングス圧縮
*/
#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <vector>
#include<fstream>
typedef long long ll;

std::vector<std::pair<char,int>> compress(const std::string& s){
    int n=s.size();
    std::vector<std::pair<char,int>> res;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(i+1<n && s[i]==s[i+1]){
            cnt++;//i+1のぶん
        }else{
            //i=n-1 or s[i]!=s[i+1]
            if(cnt>0){
                res.emplace_back(s[i],cnt);
            }
            cnt=1;//i+1のぶん
        }
    }
    return res;
}

std::vector<std::pair<char,int>> RLE(const std::string& s){
    int lens=s.size();

    std::vector<std::pair<char,int>> res;
    char tmpc=s[0];
    int idx=0;
    
    while(idx<lens){
        
        int tmp=0;
        while(idx<lens && s[idx]==tmpc){
            tmp++;
            idx++;
        }
        res.push_back(std::make_pair(tmpc,tmp));
        if(idx<lens){
            tmpc=s[idx];
        }
    }

    return res;
}