/*
尺取り方　典型
AC
*/
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];
    int l=0,r=0;
    
    set<int> kind;
    map<int,int> mp;
    int ans=0;
    //[l,r)
    while(l<N){

        while(r<N && kind.size()<=K){
            if(kind.count(a[r])){
                mp[a[r]]++;
                r++;
               
            }else{//新種の場合
                if(kind.size()<K){
                    kind.insert(a[r]);
                    mp[a[r]]++;
                    r++;
                }else{
                    //K+1種類目になってしまう
                    break;//while文を抜ける
                }
            }
        }

        if(kind.size()<=K){
            ans = max(ans,r-l);
        }

        mp[a[l]]--;
        if(mp[a[l]]==0){
            kind.erase(a[l]);
        }
        l++;

    }

    cout<<ans<<endl;



}
