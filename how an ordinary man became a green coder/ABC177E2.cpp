//TLE and WA
#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
const int MAXN=1e+6;

int gcd(int x,int y){
    if(y==0) return x;
    else return gcd(y,x%y);
}

vector<set<int>> prime(){
    vector<set<int>> st(MAXN+1);
    //pはjで割り切れる
    for(int j=1;j<=MAXN;j++){
        for(int p=2*j;p<=MAXN;p+=j){
            st[p].insert(j);
        }
    }
    return st;
}




int main(){
    int N;
    cin>>N;

    map<int,int> mp;
    vector<int> A(N);
    vector<int> cnt(1000000+1);

    for(int i=0;i<N;i++){
        cin>>A[i];

        // 計算量 sqrt(A[i])
        for(int j=2;j*j<=A[i];j++){
            if(A[i]%j==0){
                mp[j]++;
                if(A[i]/j !=j) mp[A[i]/j]++;
                
            }
        }
        if(A[i]!=1){
            mp[A[i]]++;
        }
    }
    
    bool flag1=false;
    bool flag2=false;
    //約数列挙した際に同じ数字がかぶる場合 gcd(Ai,Aj)=1は無理
    for(auto[_,cnt]:mp){
        if(cnt>=2) flag1=true;
        if(flag1) break;
        if(cnt>=N) flag2=true;//全てのA[i]で存在する
        if(flag2) break;
        
    }

    /*
    for(auto [num,cnt]:mp){
        cout<<"num="<<num<<",cnt="<<cnt<<endl;
    }
    */

    if(!flag1){
        cout<<"pairwise coprime"<<endl;
        return 0;

    }else{
        //int ans=A[0];//A[0] ~ A[N-1]の中でgcd(A[0],A[1],A[2],...,A[N-1])を探す
        /*
        for(int i=1;i<N;i++){
            ans = gcd(ans,A[i]);
        }
        */


        if(!flag2){
            cout<<"setwise coprime"<<endl;
            return 0;
        }else{
            cout<<"not coprime"<<endl;
            return 0;
        }
    }

    return 0;

}