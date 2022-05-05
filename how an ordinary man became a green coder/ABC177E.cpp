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
   
    for(int i=0;i<N;i++){
        cin>>A[i];
        /*
        for(int j=2;j*j<=A[i];j++){
            if(A[i]%j==0){
                mp[A[i]/j]++;
                if(j*j!=A[i])mp[j]++;
            }
        }
        */
        int tempA=A[i];
        for(int j=2;j*j<=tempA;j++){
            if(tempA%j==0){
                mp[j]++;
                while(tempA%j==0){
                    
                    tempA/=j;

                }
                
            }
            if(tempA>1) mp[tempA]++;
        }

       

    }

    
    bool flag1=false;
    //約数列挙した際に同じ数字がかぶる場合 gcd(Ai,Aj)=1は無理
    for(auto[num,cnt]:mp){
        if(cnt>=2) flag1=true;
    }
    if(!flag1){
        cout<<"pairwise coprime"<<endl;
        return 0;

    }else{
        int ans=A[0];//A[0] ~ A[N-1]の中でgcd(A[0],A[1],A[2],...,A[N-1])を探す
        for(int i=1;i<N;i++){
            ans = gcd(ans,A[i]);
        }

        if(ans==1){
            cout<<"setwise coprime"<<endl;
            return 0;
        }else{
            cout<<"not coprime"<<endl;
            return 0;
        }
    }

    return 0;

}