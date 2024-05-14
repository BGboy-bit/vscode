import java.util.Scanner;

public class hello {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int n = stdin.nextInt();
        int ans = 1;
        for (int i = 1; i <= n; i++) ans *= i;
        System.out.println(ans);
        stdin.close();
    }
}
