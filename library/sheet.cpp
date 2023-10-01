/*
ABC218C, ABC307C
*/

struct Sheet{

    int h,w;
    int cntsharp=0;
    char c;
    vector<string> s;
    Sheet(int h_,int w_,char c):h(h),w(w),c(c){
        
        s=vector<string>(h,string(w,c));
    };

    Sheet(vector<string> s_):h(s_.size()),w(s_[0].size()),s(s_){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(s[i][j]=='#')cntsharp++;
            }
        }
    };
    

    bool isin(int i,int j){
        return (0<=i && i<h && 0<=j && j<w);
    }

    bool copy(const Sheet& a,int ei,int ej){
        
        vector<string> res=s;

        for(int i=0;i<a.h;i++){
            for(int j=0;j<a.w;j++){
                int ni=i+ei;
                int nj=j+ej;

                if(a.s[i][j]=='#'){
                    if(!isin(ni,nj)) return false;

                    res[ni][nj]='#';

                }
            }
        }

        s=res;
        return true;
    }

    void rotate(){
        //左回転
        vector<string> tmp(w,string(h,c));
       
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                tmp[j][h-i-1]=s[i][j];
            }
        }

        s=tmp;
        swap(h,w);

    }

    /*
    sにとって(ei,ej)を基準に
    (つまり,sの左端を(0,0)とし, (ei,ej)をxの基準とした際に)
    ずらしたときに同じになるか
    */
    bool issame(const Sheet& x,int ei,int ej){
        
        if(x.cntsharp!=cntsharp) return false;
        
        
        for(int i=0;i<x.h;i++){
            for(int j=0;j<x.w;j++){
                int ni=i+ei;
                int nj=j+ej;
                if(x.s[i][j]=='#'){
                    if(!isin(ni,nj)) return false;
                    if(s[ni][nj]=='#') continue;
                    else return false;
                }

                if(x.s[i][j]=='.' && isin(ni,nj) && s[ni][nj]=='#') return false;

            }
        }

        return true;
    }

    bool operator==(const Sheet& x)const{
        return s==x.s;
    }


};


