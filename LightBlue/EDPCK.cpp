/*
AC

再帰だと間に合わない
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<string>

using namespace std;
map<int,bool> mp;

vector<int> A;
int N;
int minA=1<<30;

//再帰だと深すぎて無理な場合あり
//石の個数num個 で 自分の番になった際に負ける場合をfalseとする
bool dfs(int num){
    if(mp.count(num)) return mp[num];
    
    cout<<"num="<< num<<endl;
    
    if(num<minA) return false;//負け確定

    for(int i=0;i<N;i++){
        bool flag=dfs(num-A[i]);
        if(!flag){
            //相手をnum-A[i]で負かすことができるから,numで回ってきた場合はtrue
            return mp[num]=true;
        }
    }

    return mp[num]=false;
}

int main(){
    int K;
    cin>>N>>K;
    A= vector<int>(N);
    
    
    for(int i=0;i<N;i++){
        cin>>A[i];
        minA=min(minA,A[i]);
    }
    
    // if(dfs(K)){
    //     cout<<"First"<<endl;
    // }else{
    //      cout<<"Second"<<endl;
    // }

    vector<bool> stone(K+1,false);

    for(int i=0;i<minA;i++)stone[i]=false;//i個の石で自分の番になったら負ける

    for(int i=minA;i<=K;i++){
        for(int j=0;j<N;j++){
            if(i-A[j]>=0){
                if(!stone[i-A[j]]){//(i-A[j])個で相手に渡すことで, i個目の場合は自分は勝つことができる
                    stone[i]=true;
                }
            }
        }
    }
    
    if(stone[K]){
        cout<<"First"<<endl;
    }else{
         cout<<"Second"<<endl;
    }





    

    return 0;

}