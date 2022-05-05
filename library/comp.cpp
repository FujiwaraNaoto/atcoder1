/*
座標圧縮
https://atcoder.jp/contests/abc221/editorial/2718
ABC221
*/
int comp(vector<int> &A){
    map<int,int> mem;
    for(auto p: A) mem[p]=0;
    int sz=0;
    for(auto &p:mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}