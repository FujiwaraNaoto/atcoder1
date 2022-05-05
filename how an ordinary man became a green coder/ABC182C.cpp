//AC
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string N;
    cin>>N;

    map<int,int> mp;
    int cnt=0;
    for(int i=0;i<(int)N.size();i++){
        
        mp[(N[i]-'0')%3]++;
        cnt= (cnt + (N[i]-'0')%3)%3;
    }
    int ans=-1;

    if(cnt%3==0){
        ans=0;//何も消さない
        
    }else if(cnt%3==1){

        if(mp[1]>=1){
           
            ans=1;
            mp[1]--;
            
        }else if(mp[2]>=2){
            ans=2;
            mp[2]-=2;
            
        }
    }else{
        //cnt%3==2
        if(mp[2]>=1){
            ans=1;
            mp[2]-=1;
            
        }else if(mp[1]>=2){
            ans=2;
            mp[1]-=2;
        }
    }

    if(mp[0]==0 && mp[1]==0 && mp[2]==0) ans=-1;

    cout<<ans<<endl;
    return 0;

}