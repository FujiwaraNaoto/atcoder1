/*
優先度付きqueue
無名関数を用いた方法
*/
#include<queue>
#include<set>
#include<functional>
using namespace std;
typedef pair<int,int>P;

int main(){
    // firstにスタートからの距離
    // secondにその地点の座標
    priority_queue<P,vector<P>,function<bool(P,P)>>que(
        [&](const P& lhs,const P& rhs){
            //rhsの条件を満たすものの方が早く取り出される
            if(lhs.first!=rhs.first){
                return lhs.first>rhs.first;//歩数の小さい方が有利
        }
    );

}
