import java.util.Scanner;

public class Inverse {
    public static void main(String[] args) {
        int n,u=0,x=0,y=0,v=1;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of columns and rows:");
        n=sc.nextInt();
        int a[][]= new int[n][n];
        int b[][]= new int[n][n];
        double c[][]= new double[n][n];
        int s[][]= new int[n-1][n-1];
        System.out.println("Enter the elements of matrix:");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                a[i][j]=sc.nextInt();
            }
        }
        sc.close();
        int d;
        d=Determinant(a,n);
        for(int i=0;i<n;i++) {
            for (int j = 0; j < n; j++) {
                x=0;
                y=0;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (k != i && l != j) {
                            s[x][y] =a[k][l];
                            y++;
                            u=1;
                        }
                    }
                    if(u==1) {
                        x++;
                        y = 0;
                    }
                    u=0;
                }
                b[i][j]=Determinant(s,n-1);
            }
        }
        if(n%2==0){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = v * b[i][j];
                    v = v * (-1);
                }
                v = v * (-1);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = v * b[i][j];
                    v = v * (-1);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c[i][j]=(double)b[j][i]/d;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(c[i][j]+" ");
            }
            System.out.print("\n");
        }
    }
    public static int Determinant(int a[][],int n){
        int d1=0,d2=0;
        if(n>2) {
            for (int k = 0; k < n; k++) {
                int p = 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if ((j - i == k) || (j - i == k - n)) {
                            p *= a[i][j];
                        }
                    }
                }
                d1 += p;
            }
            for (int k = 0; k < n; k++) {
                int p = 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if ((j + i == k) || (j + i == k + n)) {
                            p *= a[i][j];
                        }
                    }
                }
                d2 += p;
            }
        }
        else if(n==2){
            d1=a[0][0]*a[1][1];
            d2=a[0][1]*a[1][0];
        }
        else{
            d1=a[0][0];
        }
        int d;
        d=d1-d2;
        return d;
    }
}
