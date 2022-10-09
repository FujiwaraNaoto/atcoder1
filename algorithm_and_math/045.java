import java.util.Scanner;
import java.util.ArrayList;


public class Main {
   
   void solve(){

       
       
       try(Scanner sc = new Scanner(System.in)){
           int N=sc.nextInt();
           int M=sc.nextInt();
           int [] a = new int[M];
           int [] b = new int[M];
           @SuppressWarnings({"unchecked"})
           ArrayList<Integer>[] G = new ArrayList[N];

           for(int i=0;i<N;i++){
               G[i] = new ArrayList<Integer>();
           }
           
           for(int i=0;i<M;i++){   
               a[i] = sc.nextInt(); 
               a[i]--;
               b[i] = sc.nextInt(); 
               b[i]--;
               G[a[i]].add(b[i]);
               G[b[i]].add(a[i]);
           }

           int ans=0;
           for(int v=0;v<N;v++){
               int cnt=0;
               for(int j=0;j<G[v].size();j++){
                   if(G[v].get(j)<v)cnt++;
               }
               if(cnt==1) ans++;
           }    

           System.out.println(ans);
       
       
       }
       

      
       

   }

   public static void main(String[] args){
       new Main().solve();
   }

}


