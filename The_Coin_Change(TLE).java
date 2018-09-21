import java.util.*;
class test3 {
    static int rec(int[] a,int[][] b,int m,int n){
        if(n<0) return 0;
        if(n==0) return b[m][n]=1;
        if(m<=0&&n>=1) return 0;
        if(b[m][n]!=1) b[m][n]=rec(a,b,m,n-a[m-1])+rec(a,b,m-1,n);
        return b[m][n];
    }
    public static void main(String[] args) {
            Scanner s1=new Scanner(System.in);
            int n=s1.nextInt();
            int m=s1.nextInt();
            int[] a=new int[m];
            int[][] b=new int[m+1][n+1];
            for(int i=0;i<m;i++) a[i]=s1.nextInt();
            System.out.println(rec(a,b,m,n));
    }
}
