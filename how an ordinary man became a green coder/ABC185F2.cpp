/*
xorが足し算のように振る舞うことがポイント
みるからにseg木
AC

*/
#include<iostream>
#include<vector>
using namespace std;



class segment_tree{
    public:
        
        vector<int> dat;
        int n=1;
        segment_tree(int n_){    
            while(n < n_){
                n*=2;
            }
            dat = vector<int>(2*n-1,0);// 0,1,2,...,2*n-3,2*n-2
        }


        void update(int k,int a){
            k+=n-1;
            dat[k] = a;
            while(k>0){
                k = (k-1)/2;
                dat[k]=dat[2*k+1]^dat[2*k+2];
            }
        }

        //[a,b)
        int query(int a,int b,int k,int l,int r){
            if(r<=a || b<=l) return 0;
            if(a<=l && r<=b) return dat[k];
            else{

                int vl = query(a,b,2*k+1,l,(l+r)/2);
                int vr = query(a,b,2*k+2,(l+r)/2,r);
                return vl^vr;
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
    int N,Q;
    cin>>N>>Q;
    segment_tree seg(N);
    
  

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        seg.update(i,A[i]);
    }


    for(int i=0;i<Q;i++){
        int t,x,y;
       
        cin>>t>>x>>y;
        if(t==1){
            x--;
            A[x]=A[x]^y;
            seg.update(x,A[x]);

        }else{//t==2
            x--;
            //[x,y)
            int ans = seg.query(x,y);

            cout<<ans<<endl;
        }
    }


}