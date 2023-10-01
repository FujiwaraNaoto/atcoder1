const ll MOD=1000000000+7;


vector<vector<ll> > mat(vector<vector<ll> > A,vector<vector<ll> > B,int N){
    //A*B
    vector<vector<ll> > C(N,vector<ll>(N));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ll ans=0;
            for(int k=0;k<N;k++){
                ans = (ans + A[i][k]*B[k][j]%MOD)%MOD;
            }
            C[i][j] = ans;
        }
    }
    return C;

}


//行列xのy乗
vector<vector<ll> > multi_matrix(vector<vector<ll> >x, ll y ,int N){

    vector<vector<ll> > pow(N,vector<ll>(N));
    for(int i=0;i<N;i++) pow[i][i]=1;//単位行列
    
    while(y>0){
        if(y&1){
            pow = mat(pow,x,N);
        }
        y = y>>1;
        x = mat(x,x,N);
    }

    return pow;
} 