import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, ans = 0;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1]; // 배열 초기화 필수
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; ++i) arr[i] = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; ++i) {
            int cnt = 0;
            for (int j = 1; j <= N; ++j) {
                if (i == j) continue;
                if (findBuilding(i, j)) cnt++;
            }
            ans = Math.max(cnt, ans);
        }
        System.out.println(ans);
    }

    public static boolean findBuilding(int i, int j) {
        if (i > j) {
            int temp = i;
            i = j;
            j = temp;
        }
        for (int k = i + 1; k < j; ++k) {
            double height = arr[i] + (double)(arr[i] - arr[j]) * (k - i) / (i - j);
            if (height <= arr[k]) return false;
        }
        return true;
    }
}
