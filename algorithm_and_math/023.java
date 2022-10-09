import java.util.Scanner;

public class Main {
    
    void solve(){
        try(Scanner sc = new Scanner(System.in)){
            int N=sc.nextInt();
            double [] B = new double[N];
            double [] R = new double[N];

            for(int i=0;i<N;i++){
                B[i] = sc.nextDouble();
                R[i] = sc.nextDouble();
            }

            double Redans=0,Blueans=0;
            for(int i=0;i<N;i++){
                Redans += B[i]/N;
                Blueans += R[i]/N;
            }
        
            System.out.println(Redans + Blueans);
        }

        

    }

    public static void main(String[] args){
        new Main().solve();
    }
    
}


