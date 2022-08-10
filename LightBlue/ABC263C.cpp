/*
再帰を使う発想がなかった.
*/
#include<iostream>
#include<vector>
using namespace std;

int N,M;

void dfs(int now,vector<int> vec){
    if(vec.size()>0 && vec[vec.size()-1]==M && vec.size()<N) return;

    if(vec.size()==N){

        for(int i=0;i<N;i++){
            cout<<vec[i]<<(i!=N-1?' ':'\n');
        }
        return;
    }
   
    
    for(int i=now+1;i<=M;i++){
        vector<int> tmp=vec;
        tmp.push_back(i);
        dfs(i,tmp);

        vector<int>().swap(tmp);
    }

}



int main(){
    
    cin>>N>>M;

    vector<int>tmp;
    dfs(0,tmp);
    


}