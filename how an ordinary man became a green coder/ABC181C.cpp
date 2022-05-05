//AC 外積
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> x(N),y(N);
    
    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
    }

    bool flag=false;
    //同一直線=外積が0
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                int dx1 = x[i]-x[k];
                int dy1 = y[i]-y[k];

                int dx2 = x[j]-x[k];
                int dy2 = y[j]-y[k];
                //外積
                int cross = abs(dx1*dy2-dx2*dy1);
                if(cross==0){
                    flag=true;
                }
            }
        }
    }

    cout<<(flag?"Yes":"No")<<endl;

}