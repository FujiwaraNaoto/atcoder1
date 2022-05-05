//AC
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


set<int> prime(int up){
    set<int> st;
    vector<bool> isprime(up+1,true);
    isprime[0]=isprime[1]=false;

    //pはjで割り切れる
    for(int j=2;j<=up;j++){
        if(isprime[j]){
            st.insert(j);
            for(int p=2*j;p<=up;p+=j){
                isprime[p]=false;
            }
        }
    }

    return st;
}




int main(){
    int N;
    cin>>N;

    map<int,int> mp;
    vector<int> A(N);
    vector<int> arrayA(MAXN+1,0);
    vector<int> cnt(MAXN+1,0);

    int maxA=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        arrayA[A[i]]++;
        maxA=max(maxA,A[i]);   

    }

    set<int> st = prime(maxA);

    for(int x:st){

        for(int i=x;i<=maxA;i+=x){
            cnt[x]+=arrayA[i];
        }

    }

    
    bool flag1=false;
    bool flag2=false;

    //i=1の時は考えない　どのA[i]も約数1を持つゆえ
    for(int i=2;i<=MAXN;i++){
        if(cnt[i]>=2) flag1=true;
       
        if(cnt[i]>=N) flag2=true;//A[i](i=0~N-1)全員で割り切れるものがある
        
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