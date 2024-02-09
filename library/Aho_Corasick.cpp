
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<cassert>
#include<unordered_map>
#include<optional>
#include<tuple>

struct Aho_Corasick{
    typedef std::unordered_map<char,int> MP;

    std::vector<MP> trie;
    std::vector<int> cnt;//cnt,treeの大きさは同じ
    const int root=0;
    
    Aho_Corasick(){
        trie.push_back(MP());
        cnt.push_back(0);
    }

    std::unordered_map<int,std::vector<std::string>> output;

    void add(const std::vector<std::string>& terms){
        for(const std::string& term:terms){
            add(term);
        }
    }

    //計算量は挿入する文字列の長さの和
    int add(const std::string& string){
        int now=root;//根
        for(char c:string){
            if(trie[now].count(c)){
                now=trie[now][c];
            }else{
                int pre=now;
                now=trie.size();
                cnt.push_back(0);
                trie.push_back(MP());
                trie[pre][c]=now;
            }
        }

        cnt[now]++;//終端文字列

        output[now].push_back(string);//終端ノードに対してsを入れる
        

        return now;
    }

    void match(const std::string& string){

        std::cout<<"target: string="<<string<<std::endl;
       
        int now=0;
        
        for(int i=0;i<string.size();i++){
            char c=string[i];
            //今の状態nowからcを用いて遷移する場所を探す.
            while(!go(now,c)){
                now=failure[now];
            }
            //go(now,string[i]).firstがtrue
            now=*go(now,c);

            for(const auto& x:output[now]){
                //ノードnowで終わる場合
                std::cout<<"start="<<i-x.size()+1<<",goal="<<i<<",string:"<<x<<std::endl;
            }
        }
        
    }

    std::vector<int> failure;
    std::vector<int> dist;
    

    //ノードnowから文字列cをうけていく場所
    std::optional<int> go(int now,char c){
        
        if(trie[now].count(c)){
            return trie[now][c];
        }else if(now==root) return root;
        else return {};
        
    }

    void bfs(){
      
      failure=std::vector<int>(trie.size(),0);
      dist=std::vector<int>(trie.size(),-1);
      std::queue<int> que;
      
      dist[root]=0;
      que.push(root);

      while(!que.empty()){
        int now=que.front();
        que.pop();
        
        for(auto [c,to]:trie[now]){
          //nowのキーc,toを取り出す
          //trie[now][c]=toとなる
         
            if(now!=root){
                int f=failure[now];//nowで失敗した場合に行きつく場所
                
                while(!go(f,c)){
                    f=failure[f];
                }
                //go(f,c).firstがtrueつまり状態fの次に文字cで行ける場所がある　もしくはfがroot
                failure[to]=*go(f,c);

                for(const auto& string:output[failure[to]]){
                    //ノードfailure[to]で終わる文字列たちをtoにもいれる
                    output[to].push_back(string);
                }
               
            }

            que.push(to);
            dist[to]=dist[now]+1;
            
        }

      }
      

    }
    
};
