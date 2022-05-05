/*
制約が小さいのでbit全探索
AC
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int H,W,K;
    cin>>H>>W>>K;
    vector<vector<char>> c(H,vector<char>(W));
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            cin>>c[y][x];
        }
    }


    int ans=0;
    
    for(int S1=0;S1<(1<<H);S1++){

        for(int S2=0;S2<(1<<W);S2++){
            vector<vector<char>> temp=c;
            for(int y=0;y<H;y++){
                if((S1>>y)&1){
                    for(int x=0;x<W;x++){
                        temp[y][x]='R';//赤色に塗る
                    }
                }
            }
            

            for(int x=0;x<W;x++){
                if((S2>>x)&1){
                    for(int y=0;y<H;y++){
                        temp[y][x]='R';//赤色に塗る
                    }
                }
            }

            int cnt=0;
            for(int y=0;y<H;y++){
                for(int x=0;x<W;x++){
                    if(temp[y][x]=='#') cnt++;
                }
            }

            if(cnt==K)ans++;

        }
    }

    cout<<ans<<endl;



}