/*
Noが正しいのに
Yesとなるものを探す
AC
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef pair<int,int> P;

vector<vector<char>> rotate(vector<vector<char>> tmp,int n){
    vector<vector<char>> ret(n,vector<char>(n));

    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            ret[n-1-x][y]=tmp[y][x];
        }
    }

    return ret;
}

/*
P searchgrid(vector<vector<char>> tmp,int n){
    P p;
    p.first=201,p.second=201;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(tmp[y][x]=='#'){
                p.second=y;
                p.first=x;
                return p;
            }
        }
    }
    return p;
}
*/

P searchgrid(vector<vector<char>> tmp,int n){
    P p;
    p.first=201,p.second=201;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(tmp[y][x]=='#'){
                p.second=min(y,p.second);
                p.first=min(x,p.first);
            }
        }
    }

    return p;

}



int main(){
    int N;
    cin>>N;
    string input;
    vector<vector<char>> S(N,vector<char>(N)), T(N,vector<char>(N));
    int cntS=0,cntT=0;
    for(int i=0;i<N;i++){
        cin>>input;
        for(int j=0;j<N;j++){
            S[i][j]=input[j];
            if(S[i][j]=='#')cntS++;
        }
    }

    for(int i=0;i<N;i++){
        cin>>input;
        for(int j=0;j<N;j++){
            T[i][j]=input[j];
            if(T[i][j]=='#')cntT++;
        }
    }

    bool ans=false;

    for(int k=0;k<4;k++){

        auto [offsetSx,offsetSy]=searchgrid(S,N);
        auto [offsetTx,offsetTy]=searchgrid(T,N);
        int tmpcnt=0;
        for(int dy=0;dy+offsetSy<N && dy+offsetTy<N; dy++){
            for(int dx=0;dx+offsetSx<N && dx+offsetTx<N; dx++){
                if(S[offsetSy+dy][offsetSx+dx]==T[offsetTy+dy][offsetTx+dx]){
                    if(S[offsetSy+dy][offsetSx+dx]=='#'){
                        tmpcnt++;
                    }
                }else{
                    break;
                }
            }
        }

        /*
        これを両方に対しておこなわないと,
        本来No のはズなのに　cntS==tmpcnt だけから判断してYes になることがありうる.

        */
        if(tmpcnt==cntS && tmpcnt==cntT)ans=true;

        S=rotate(S,N);
    }

cout<<(ans?"Yes":"No")<<endl;
    
    

}