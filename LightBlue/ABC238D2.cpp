#include<iostream>
using namespace std;
typedef long long ll;

bool dfs(ll a,ll s){
   
    if(a==0 && s==0) return true;

    for(int x=0;x<2;x++){//位の決め打ち
        for(int y=0;y<2;y++){

            if((s-(x+y))<0) continue;
            if((s-(x+y))%2!=0)continue;
            
            if((a&1)!=((x&y)&1)){
                //a&1==1のときは x and yの1の位は必ず1
                
                continue;
            }
            return dfs(a/2,(s-(x+y))/2);
           

        }
    }

    return false;
}


int main(){
    int T;
    cin>>T;
    ll a,s;
    for(int i=0;i<T;i++){
        cin>>a>>s;
        cout<<(dfs(a,s)?"Yes":"No")<<endl;
    }
}
