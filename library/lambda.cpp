/*
無名関数
*/

#include<functional>
function<void(int,int)> tree_dp = [&](int pos,int pre){
            //頂点posから頂点iへ
            for(int i:G[pos]){
                if(i==pre) continue;
                tree_dp(i,pos);
                c[pos]+=c[i];
            }
        };
