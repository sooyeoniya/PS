import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        String c = sc.next();

        if (c.charAt(0) >= '0' && c.charAt(0) <= '9')
            printOut(Integer.parseInt(c) + 1); // c가 숫자인 경우
        else if (b.charAt(0) >= '0' && b.charAt(0) <= '9')
            printOut(Integer.parseInt(b) + 2); // b가 숫자인 경우
        else if (a.charAt(0) >= '0' && a.charAt(0) <= '9')
            printOut(Integer.parseInt(a) + 3); // a가 숫자인 경우
        sc.close();
    }

    public static void printOut(int num) {
        if (num % 3 == 0 && num % 5 == 0) System.out.print("FizzBuzz");
        else if (num % 3 == 0 && num % 5 != 0) System.out.print("Fizz");
        else if (num % 3 != 0 && num % 5 == 0) System.out.print("Buzz");
        else System.out.print(num);
    }
}