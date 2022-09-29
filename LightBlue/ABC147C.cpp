#include<iostream>
#include<vector>
#include<map>
#include<bit>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    vector<vector<P>> is(N,vector<P>{});

    for(int i=0;i<N;i++){
        cin>>A[i];
        
        int x,y;
        for(int j=0;j<A[i];j++){
            cin>>x>>y;
            x--;//0indexにする
            is[i].push_back(P{x,y});
        }
    }

    int ans=0;//最初は正直者が0人とする

    for(int S=0;S<(1<<N);S++){
        //矛盾が起きているかどうか
        //最初は矛盾が起きていないと仮定
        bool is_contradiction=false;//集合Sが,正直者の集団とする.

        for(int i=0;i<N;i++){
            if((S>>i)&1){

                //iが正直者であるとする
                for(auto [x,y]:is[i]){
                    if(y==0){
                        //人xが嘘つき　という発言が正しい場合
                        if((S>>x)&1){
                            //Sの中にxが含まれていないべき 含まれていたら矛盾がある
                            is_contradiction=true;
                        }

                    }else{
                        //人xが正直　という発言が正しい場合
                        if(!((S>>x)&1)){
                            //Sの中にxが含まれているべき
                            is_contradiction=true;
                        }

                    }
                }

            }else{//不正直なものは判断材料にしない
            
            }
        }

        if(is_contradiction){
            continue;
        }else{
            ans=max(ans,__builtin_popcount(S));
        }

    }

    cout<<ans<<endl;



}