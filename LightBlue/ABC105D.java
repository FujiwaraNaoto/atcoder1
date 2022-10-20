/*
 *AC
 ABC105D
 */

import java.util.Scanner;
import java.util.stream.IntStream;
import javax.swing.text.StyledEditorKit;

import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;


class Main {

    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        HashMap<Long,ArrayList<Integer>> mp = new HashMap<>();//map<String,int> みたいなもの
        int N=sc.nextInt();
        long M =sc.nextLong();
        long[] A = new long[N+1];
        long[] sumA = new long[N+1];
        A[0]=0;
        for(int i=1;i<=N;i++){
            A[i] = sc.nextLong();
        }  

        for(int i=1;i<=N;i++){
            sumA[i] = sumA[i-1]+A[i];
        }

        for(int i=0;i<=N;i++){
            if(mp.get(sumA[i]%M)==null){
                mp.put(sumA[i]%M,new ArrayList<>());
            }
            mp.get(sumA[i]%M).add(i);
            
        }

        long ans=0;

        for(ArrayList<Integer> vec :mp.values()){
            long sz=vec.size();
            ans+=sz*(sz-1)/2;
        }

        System.out.println(ans);
     
    }
}
