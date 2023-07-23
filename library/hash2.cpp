/*
ハッシュで乱数を割り当てる際に有効

yukicoder 1746から抜粋

https://cpprefjp.github.io/reference/random/uniform_int_distribution/op_call.html


*/
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<random>

const long long int INF=1LL<<60;


int main(){
    int N;
    std::cin>>N;
    std::vector<long long> a(N);
    for(int i=0;i<N;i++){
        std::cin>>a[i];
    }

    std::random_device seed_gen;
    std::mt19937_64 engine(seed_gen());

    std::uniform_int_distribution dist(1LL,1LL<<60);//[1,1LL<<60]までの乱数


    std::map<long long int,long long int> random_mp;

    //vに対し乱数を割り当てる
    for(long long int v:a){
        random_mp[v]=dist(engine);
    }



}