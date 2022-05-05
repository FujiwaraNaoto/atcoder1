/*
AC
典型90 max manhattan distanceをみよ
同時に √2 倍にしている

*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
const int INF = 1<<30;

int main(){
    int N;
    cin>>N;
    
    int minx = INF;
    int miny = INF;
    int maxx = -INF;
    int maxy = -INF;  
    vector<P> zahyo;

    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        zahyo.push_back(P(x+y,y-x));
        minx = min(x+y,minx);
        maxx = max(x+y,maxx);
        miny = min(y-x,miny);
        maxy = max(y-x,maxy);
    }

    int ans =0;
    for(int i=0;i<N;i++){
        int tempx = zahyo[i].first;
        int tempy = zahyo[i].second;

        int dis = max({ abs(minx - tempx),abs(maxx-tempx),abs(miny-tempy),abs(maxy-tempy)});
        ans = max(ans,dis);
    }
    cout<<ans<<endl;



}