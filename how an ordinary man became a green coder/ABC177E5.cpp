//AC
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int MAX_N=1e+6;



vector<vector<int>> factor(MAX_N+1,vector<int>{});

// N(log(logN))

// MAX_Nまでの素数を調べる と 同時に　pの約数を列挙
void init(){
    vector<bool> isprime(MAX_N+1,true);
    isprime[0]=isprime[1]=false;
    
    set<int> prime;

    for(int i=2;i<=MAX_N;i++){
        if(isprime[i]){
            prime.insert(i);
            factor[i].push_back(i);//もちろん自分自身で割れる
            for(int p=2*i;p<=MAX_N;p+=i){
                isprime[p]=false;

                factor[p].push_back(i);//pはiで割り切れる つまり pはiの倍数
            
            }
        }
    }
    
}




int main(){
    int N;
    cin>>N;
    
    vector<int> A(N);
    for(int i=0;i<N;i++)cin>>A[i];

    init();

    map<int,int> mp;

    for(int i=0;i<N;i++){
        for(int x: factor[A[i]]){//A[i]が何で割り切れるのかがx
            mp[x]++;
        }
    }

    bool ispairwise=true;
    bool issetwise=true;

    for(auto [num,cnt]:mp){
        if(num==1) continue;

        if(cnt>=2) ispairwise = false;
        if(cnt>=N) issetwise = false;//全てのAで(1以外で)割り切れる数字
    }

    if(ispairwise){
        cout<<"pairwise coprime"<<endl;
    }else if(issetwise){
        cout<<"setwise coprime"<<endl;
    }else{
        cout<<"not coprime"<<endl;
    }
    return 0;
    
}