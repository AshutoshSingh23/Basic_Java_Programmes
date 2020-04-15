import java.util.Scanner;

public class no_of_characters {
    public static void main(String[] args){
        String s;
        Scanner sc = new Scanner(System.in);
        int p=0;
        System.out.println("Enter the String:");
        s=sc.nextLine();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' ')
                p++;
        }
        System.out.println("The number of characters in the given string is: "+p);
    }
}
