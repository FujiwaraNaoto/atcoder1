import java.util.Scanner;

public class Main {
    
    void solve(){
        try(Scanner sc = new Scanner(System.in)){
            int N=sc.nextInt();
            double [] P = new double[N];
            double [] Q = new double[N];

            double ansPoint=0;
            for(int i=0;i<N;i++){   
                P[i] = sc.nextDouble();
                Q[i] = sc.nextDouble();
                ansPoint+=Q[i]/P[i];
            }
            
            
            System.out.println(ansPoint);
        }

        

    }

    public static void main(String[] args){
        new Main().solve();
    }

}


