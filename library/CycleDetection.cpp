/*
ref

https://drken1215.hatenablog.com/entry/2023/05/20/200517

*/
#include<vector>


//Gは有効グラフ
std::vector<int> vs;
/*
seenが行き掛け順
finishedが帰りがけ順
*/
/*
DAG(一つの頂点から一つの行先しかない)のときに使う

*/

int dfs(int now,const std::vector<std::vector<int>>& G,std::vector<bool>& seen,std::vector<bool>&finished){

       if(seen[now] && !finished[now]){
            //nowがサイクルの入り口
            return now;
        }

        if(seen[now] && finished[now]){
            return -1;
        }

        seen[now]=true; 
        
        int res=-1;
        for(int to:G[now]){
            res=std::max(res,dfs(to,G,seen,finished));
        }
       
        finished[now]=true;

        if(res==-1){
            return -1;

        }else if(res==now) {
            //nowがサイクルの始まりだと気付いたとき
            
            vs.push_back(now);

            return -1;

        }else{
            vs.push_back(now);
            return res;
        }
}

int main(){
    for(int i=0;i<N;i++){
            
            if(!seen[i]){
                vs.clear();
                dfs(i,G,seen,finished);
                for(int v:vs){
                    incycle[v]=true;
                }
            }
            
    }

}

