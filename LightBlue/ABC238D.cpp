//AC
#include<iostream>
using namespace std;
typedef long long ll;

bool dfs(ll a,ll s){
    if(a==0 && s==0) return true;

   
    if((a&1)==1){//(x,y)=(1,1)
        if((s-2)>=0 && (s&1)==0){
            return dfs((a-1)/2,(s-2)/2);
        }else return false;
    }
    //a&1==0のとき  少なくとも片方が必ず0
    if((s&1)==1){//(x,y)=(0,1) or (1,0)
        return dfs(a/2,(s-1)/2);
    }else{
        //s&1==0 (x,y)=(0,0)
        return dfs(a/2,s/2);
    }
    
    

   

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