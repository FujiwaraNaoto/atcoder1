//AC
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;


int main(){
    int N,K;
    cin>>N>>K;
    vector<vector<int>> T(N,vector<int>(N,0));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>T[i][j];
        }
    }

    vector<int> order;
    for(int i=1;i<N;i++)order.push_back(i);

    int ans=0;

    do{
        int time=0;
        int pre=0;//最初の街は0
        for(int j=0;j<(int)order.size();j++){
            int next = order[j];
            time+=T[pre][next];
            pre=next;
        }
        time+=T[pre][0];

        if(time==K) ans++;


    }while(next_permutation(order.begin(),order.end()));

    cout<<ans<<endl;

}
