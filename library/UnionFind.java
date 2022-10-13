class UnionFind{

    
    public int[] rank;
    public int[] par;
    public int[] sz;
    

    public UnionFind(int size){
       
        rank= new int[size+1];
        par = new int[size+1];
        sz = new int[size+1];

        for(int i=0;i<=size;i++){
            par[i]=i;
            sz[i]=1;
            rank[i]=0;
        }
        
    }  

    public int find(int x){
        if(par[x]==x) return x;
        else return par[x]=find(par[x]);
    }

    public void merge(int u,int v){
        u = find(u);
        v = find(v);
        if(u==v) return;
        if(rank[u]>rank[v]){
            par[v]=u;
            sz[u]+=sz[v];
        }else{
            par[u]=v;
            //vの傘下へuが入る
            sz[v]+=sz[u];
            if(rank[u]==rank[v]) rank[v]++;   
        }
    }

    public boolean issame(int u,int v){
        return find(u)==find(v);
    }

    public int size(int u){
        u=find(u);
        return sz[u];
    }

}

