//TLE and WA
// mpは使わなくても根本的な解決にはならないみたいやな
// O(N(√Amax))
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
            st[p].insert(j);//pはjで割り切れる
        }
    }
    return st;
}




int main(){
    int N;
    cin>>N;

    map<int,int> mp;
    vector<int> A(N);
    vector<int> cnt(MAXN+1,0);

    for(int i=0;i<N;i++){
        cin>>A[i];

        // 計算量 sqrt(A[i])
        for(int j=1;j*j<=A[i];j++){
            if(A[i]%j==0){
                cnt[j]++;               
                if(A[i]/j !=j) cnt[A[i]/j]++;
            }
        }
        
    }
    
    bool flag1=false;
    bool flag2=false;
    
    //約数列挙した際に同じ数字がかぶる場合 gcd(Ai,Aj)=1は無理
   

    //i=1の時は考えない　どのA[i]も約数1を持つゆえ
    for(int i=2;i<=MAXN;i++){
        if(cnt[i]>=2) flag1=true;
       
        if(cnt[i]>=N) flag2=true;
        
    }

  

    if(!flag1){
        cout<<"pairwise coprime"<<endl;
        return 0;

    }else{
        //int ans=A[0];//A[0] ~ A[N-1]の中でgcd(A[0],A[1],A[2],...,A[N-1])を探す
       
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