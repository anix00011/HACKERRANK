import java.util.*;
import java.util.stream.IntStream;

public class test {
    public static void climbingTheLeaderboard(int[] scores, int n, int[] alice) {
        int[] array = IntStream.range(0,n).map(i->scores[n-i-1]).distinct().toArray();
        int index = 0;
        for(int score: alice) {
            index = Arrays.binarySearch(array,score);
            if(index<0) index=-index-2;
            System.out.println(array.length-index);
        }
    }
    public static void main(String args[])
    {
        Scanner s1=new Scanner(System.in);
        int n=s1.nextInt();
        int[] scores=new int[n];
        for(int i=0;i<n;i++) scores[i]=s1.nextInt();
        int m=s1.nextInt();
        int[] alice=new int[m];
        for(int i=0;i<m;i++) alice[i]=s1.nextInt();
        climbingTheLeaderboard(scores,n,alice);
    }
}
