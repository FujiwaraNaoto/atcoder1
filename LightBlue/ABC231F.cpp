/*
AC
高橋君がプレゼントi,
青木君がプレゼントjのとき

A[i]>=A[j]
B[i]<=B[j]


*/
#include<iostream>
#include<map>
#include<numeric>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

template<class Type> struct binary_indexed_tree{
    int N;
    vector<Type> bit;
    
  

    binary_indexed_tree(int n):N(n+1){
        bit = vector<Type>(n+1,0);
        N=n+1;
    }



    void add(int x,Type a){
        x++;//1から始めるための補正
        //for(int i=x; i<=N; i+=(i&-i)) bit[i] = addition(bit[i],a);
        while(x<=N){
            //bit[x] = addition(bit[x],a);
            bit[x] =bit[x]+a;
            x += x&-x;
        }
    }

    
    Type sum(int x){
        x++;//1から始まることに注意
        Type ret=0;
        //for(int i=x; i>0; i-=(i&-i)) ret = addition(ret,bit[i]);
        while(x>0){
            ret = ret+bit[x];
            x -= x&-x;
        }
        
        return ret;
    }

    //[l,r]の範囲
    // rはN-1以下
    Type get(int l,int r){
        if(r>N) return 0;//配列の外へのアクセス
        if(l>r) return 0;//本来は l<=r となるのでおかしい
        if(l==0) return sum(r);//[0,r]//ここでoutなわけか
        else return (sum(r) - sum(l-1));
    }
};

void compress(vector<int>& A){
    set<int> st;
    for(int a:A){
        st.insert(a);
    }
    
    map<int,int> mp;
    int cnt=0;//最初は0
    for(auto a:st){
        mp[a]=cnt;
        cnt++;
    }
    for(int i=0;i<A.size();i++){
        A[i]=mp[A[i]];
    }

}

int main(){
    int N;
    cin>>N;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
       
    }
    compress(A);
    compress(B);
    map<int,vector<int>> d;//同じAのときにも対策が可能
    for(int i=0;i<N;i++){
        d[A[i]].push_back(B[i]);
    }


    binary_indexed_tree<int> BIT(N);
   
    ll ans=0;
    
    for(auto [_,bs]:d){//aの昇順から見ていく aに属するbについて
        for(int b:bs){
            BIT.add(b,1);
        }

        for(int b:bs){
            // 
            ans+=BIT.get(b,N-1);

        }

    }

    cout<<ans<<endl;

}