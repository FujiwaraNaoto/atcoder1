/*
AC 100点
Hの制約が小さいため,全探索
*/
#include<iostream>
#include<map>
#include<vector>
#include<bit>
using namespace std;

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<int>> P(H,vector<int>(W));

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>P[i][j];
        }
    }
   
   int ans=0;

   for(int S=0;S<(1<<H);S++){//行を全探索
        map<int,int> kind;
        for(int j=0;j<W;j++){//j列目に注目する
            int x=-1;
            bool flag=true;
          
            for(int i=0;i<H;i++){//i行目に注目する
                if((S>>i)&1){
                   
                    if(x==-1)x=P[i][j];
                    else{
                        if(x!=P[i][j])flag=false;
                    }
                }
            }
            if(flag){
                kind[x]+=__builtin_popcount(S);
            }
            
        }

        for(auto [_,s]:kind){
            ans=max(ans,s);
        }

    }

    cout<<ans<<endl;
    

    return 0;
}