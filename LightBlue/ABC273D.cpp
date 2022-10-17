/*
二分探索を使用した良問
*/
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<tuple>
using namespace std;
typedef long long ll;

int main(){
    int H,W,rs,cs;
    cin>>H>>W>>rs>>cs;
    
    int N;
    cin>>N;
    vector<int> r(N),c(N);//y座標がr x座標がc
    map<int,vector<int>> mp_r,mp_c;//mp_cはrを固定してcを探す
    for(int i=0;i<N;i++){
        cin>>r[i]>>c[i];
        
        mp_c[r[i]].push_back(c[i]);
        mp_r[c[i]].push_back(r[i]);
    }

    int Q;
    cin>>Q;
    vector<char> d(Q);
    vector<int> l(Q);
    for(int i=0;i<Q;i++){
        cin>>d[i]>>l[i];
    }

    for(auto& [_,p]:mp_c){ sort(p.begin(),p.end());}
    for(auto& [_,p]:mp_r){ sort(p.begin(),p.end());}

    int nowr=rs;//今いるy座標
    int nowc=cs;//今いるx座標
    for(int i=0;i<Q;i++){
        int len = l[i];
        if(d[i]=='L'){

            int left=1;
            //今いる座標x=nowcよりも左に行く
            auto it = lower_bound(mp_c[nowr].begin(),mp_c[nowr].end(),nowc);

            if(it!=mp_c[nowr].begin()){
                it--;
                left = (*it)+1;
            }

            nowc = max(left,nowc-len );


        }else if(d[i]=='R'){
            int right=W;
            //今いる座標x=nowcよりも右に行く
            auto it = upper_bound(mp_c[nowr].begin(),mp_c[nowr].end(),nowc);

            if(it!=mp_c[nowr].end()){//it==mp_c[now].endの場合はleft=W
                right=(*it)-1;//石の座標の一つ前
            }

            nowc = min(right,nowc+len );



        }else if(d[i]=='U'){

            
            int up=1;
            //今いる座標y=nowrよりも↑に行く
            auto it = lower_bound(mp_r[nowc].begin(),mp_r[nowc].end(),nowr);

            if(it!=mp_r[nowc].begin()){
                it--;
                up = (*it)+1;
            }

            nowr = max(up,nowr-len );

        }else{
            //d[i]=='D'

            int down=H;
            //今いる座標y=nowrよりも下に行く(yの値が増える)
            auto it = upper_bound(mp_r[nowc].begin(),mp_r[nowc].end(),nowr);

            if(it!=mp_r[nowc].end()){//it==mp_r[nowc].endの場合はdown=H
                down=(*it)-1;//石の座標の一つ前
            }

            nowr = min(down,nowr+len );


        }

        cout<<nowr<<' '<<nowc<<endl;

    
    
    }



}