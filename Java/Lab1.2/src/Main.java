import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter number for n: ");
        int n = input.nextInt();

        for (char i = 'a'; i < 'a' + n; i++) {
            for (char j = 'a'; j < 'a' + n; j++) {
                for (char k = 'a'; k < 'a' + n; k++) {
                    System.out.printf("%c%c%c%n", i, j, k);
                }
            }
        }
        input.close();
    }
}