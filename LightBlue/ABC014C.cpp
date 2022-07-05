/*
累積和がポイント　
AC
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int KIND = 1000001;

int main(){
    vector<int> color(KIND+1,0);//0~1000001
    int n;
    cin>>n;
    int a,b;
    //[a,b)
    for(int i=0;i<n;i++){
        cin>>a>>b;
        color[a]++;
        color[b+1]--;
    }

    for(int i=1;i<=KIND;i++){
        color[i]+=color[i-1];
    }
    int ans=0;
    for(int i=0;i<=KIND;i++){
        ans = max(ans,color[i]);
    }
    cout<<ans<<endl;






}