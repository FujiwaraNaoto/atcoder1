#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
   
    vector<int> is_read(N+1,false);

    int a;
    int cnt=0;
    for(int i=0;i<N;i++){
        cin>>a;
        if(a>N || is_read[a])cnt++;
        else{
            is_read[a]=true;
        }
    }

    int last=N;
    int ans=0;
    
    for(int i=1;;i++){
        if(is_read[i]){
            if(N>0){
                ans=i;
                N--;
            }else{
                break;
            }
        }else{
            if(N<2)break;
            else{
                N-=2;
                is_read[i]=true;
                ans=i;
            }
        }
    }
    cout<<ans<<endl;

}