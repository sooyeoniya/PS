// 풀이 시간: 47m49s98
// 시간 복잡도: O(1001^2)
// 공간 복잡도: O(1001^2)
// 참고: https://nnnlog.tistory.com/38
import java.util.*;

public class Main {
    static final long MOD = 1000000000000000000L;
    static long[][] P = new long[1001][1001];
    static double N;

    public static long fibonacci(int i, int j) {
        // 이미 계산된 값 반환
        if (P[i][j] != 0) return P[i][j];
        // 현재 숫자 계산
        double cur = N - i - Math.PI * j;
        // P[n] = 1 (0 ≤ n ≤ π)
        if (0 <= cur && cur <= Math.PI) return 1;
        // P[n] = P[n-1] + P[n-π] (그 외)
        return P[i][j] = (fibonacci(i + 1, j) + fibonacci(i, j + 1)) % MOD;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextDouble();
        System.out.print(fibonacci(0, 0));
    }
}
