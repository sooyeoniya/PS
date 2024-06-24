import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lv = sc.nextInt();
        String str = sc.next();
        sc.close();
        int score;
        switch (str) {
            case "bad": score = lv * 200; break;
            case "cool": score = lv * 400; break;
            case "great": score = lv * 600; break;
            case "perfect": score = lv * 1000; break;
            default: score = 0;
        }
        System.out.print(score);
    }
}