/*
 使用するさいは Main.javaというファイル名で
 */
import java.util.Scanner;


public class Main{
    void solve(){
        try(Scanner sc = new Scanner(System.in)){
            int N = sc.nextInt();
            int K = sc.nextInt();
            boolean [] stones = new boolean[K+1];
            int [] A = new int[N];
            for(int i=0;i<=K;i++) stones[i]=false;
            for(int i=0;i<N;i++) A[i]=sc.nextInt();
            
            for(int i=0;i<=K;i++){
                for(int j=0;j<N;j++){
                    if(i-A[j]>=0 && !stones[i-A[j]]){
                        stones[i]=true;
                    }
                }
            }

            if(stones[K]){
                System.out.println("First");
            }else{
                System.out.println("Second");
            }
            

        }
    }

    public static void main(String[] args){
        new Main().solve();
    }
}