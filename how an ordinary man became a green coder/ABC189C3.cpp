/*
TLE
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;

class segment_tree{
    public:
        
        vector<int> dat;
        int n=1;
        segment_tree(int n_){    
            while(n < n_){
                n*=2;
            }
            dat = vector<int>(2*n-1,INF);// 0,1,2,...,2*n-1,2*n-2
        }


        void update(int k,int a){
            k+=n-1;
            dat[k] = a;
            while(k>0){
                k = (k-1)/2;
                dat[k]=min(dat[2*k+1],dat[2*k+2]);
            }
        }

        //[a,b)
        int query(int a,int b,int k,int l,int r){
            if(r<=a || b<=l) return INF;
            if(a<=l && r<=b) return dat[k];
            else{

                ll vl = query(a,b,2*k+1,l,(l+r)/2);
                ll vr = query(a,b,2*k+2,(l+r)/2,r);
                return min(vl,vr);
            }
        }

        //[a,b)の範囲でのmin
        int query(int a,int b){
            return query(a,b,0,0,n);
        }

        int operator[](int index){
            index += n-1;
            return dat[index];
        }
};


int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    segment_tree seg(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        seg.update(i,A[i]);
    }

    /*
    ll ans=0;
    for(int l=0;l<=N;l++){
        for(int r=l+1;r<=N;r++){
            ll temp = seg.query(l,r);
            //cout<<"temp="<<temp<<endl;
            ans=max(ans,seg.query(l,r)*(r-l));
        }
    }
    */

    //尺取り法で行けるかも　と思った
    ll ans=0;
    int l=0,r=0;
    //[l,r]
    while(l<N){

        int minA;
        while(r<N){
            int length = r-l;
            minA = seg.query(l,r);
            if(ans<minA*length){
                ans = temp;
                if(r<N){
                    r++;
                }
            }else{

            }            
        }

        if(A[l]==minA){

        }
        if(l+1<r){
            l++;
        }


        
    }

    cout<<ans<<endl;
    



}
