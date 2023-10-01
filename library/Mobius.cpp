/*
メビウス関数
*/

struct Mobius{

    std::vector<int> lists;
    std::vector<bool> isprime;
    int n;
    Mobius(int n_):n(n_){
        lists=std::vector<int>(n+1,1);
        isprime=std::vector<bool>(n+1,true);

        init();
    }

    void init(){

        isprime[0]=isprime[1]=false;
        for(long long i=2;i<=n;i++){
            if(!isprime[i]) continue;//iが素数でない場合


            lists[i]=(-1)*lists[i];

            for(long long j=2*i;j<=n;j+=i){
                isprime[j]=false;

                if( ((j/i)%i)==0 ){
                    //jは (i*i)で割れる
                    lists[j]=0;
                }
                lists[j]*=(-1);
            }
        }
    
    }

    int operator()(int n){
        return lists[n];
    }

    
};