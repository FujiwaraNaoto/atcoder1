/*
Moのアルゴリズム [l,r]バージョン

Moのアルゴリズムのテンプレート


N*Nの升目がある.クエリがQ個.



縦をD段に分けた場合,一段当たりN/D. 
横の移動トータルで N*D回.
縦の移動は トータルで (N/D)Q回
計算量は O(N*D + (N/D)Q)
D=√Q でmin 
この時の計算量はO(N√Q)


縦をN/D段ごとに分けた場合,一段当たりD. 
横の移動トータルで (N^2)/D回.
縦の移動は トータルで DQ回
計算量は O(N^2/D + DQ)
D=N/√Q でmin
この時の計算量はO(N√Q)






*/



#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<numeric>
#include<cmath>
#include<functional>



int main(){
    int N,Q;
    std::cin>>N>>Q;
    std::vector<int> A(N);//value
    for(int i=0;i<N;i++){
        std::cin>>A[i];
    }

    std::vector<int> L(Q),R(Q);//0<=L,Q<N
    for(int i=0;i<Q;i++){
        std::cin>>L[i]>>R[i];
        L[i]--;R[i]--;
    }


    const int D = max((int)(N/sqrt(Q)),1);
    std::vector<int> order(Q);
    std::iota(order.begin(),order.end(),0);

    
    std::sort(order.begin(),order.end(),
    [&](const int& i,const int& j){
        int di=R[i]/D,dj=R[j]/D;

        if(di==dj){
            return L[i]<L[j];
        }else{
            return di<dj;
        }
    });
    
    
   
    std::vector<int> cnt(1e6);   

    int ans;

    auto add=[&](int idx,int x=1){
        //A[idx]が入った際の処理を書く
    };



    auto del=[&](int idx){
        //A[idx]が出ていく際の処理を書く
        add(idx,-1);
    };

    std::vector<bool> ansoutput(Q);    

    int l=0,r=-1;//[l,r]の範囲内のAの値を用いた処理を書く

    for(int idx:order){

        while(r<R[idx]){
            r++;
            add(r);
        }

        while(R[idx]<r){
            del(r);
            r--;
        }

        while(l<L[idx]){
            del(l);
            l++;
        }

        while(L[idx]<l){
            l--;
            add(l);
        }
        //L[idx]=lとなっている

        ansoutput[idx]=ans;



    }


    for(int i=0;i<Q;i++){
        std::cout<<ansoutput[i]<<std::endl;
    }

}