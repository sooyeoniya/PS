import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine()); // N 입력
        int[] dp = new int[N + 1]; // 해당 작업까지 걸리는 시간

        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken()); // 작업 시간
            int num = Integer.parseInt(st.nextToken()); // 선행 작업 개수
            dp[i] = time; // 해당 작업에 대한 작업 시간 추가
            for (int j = 0; j < num; ++j) {
                int temp = Integer.parseInt(st.nextToken()); // 선행 작업 번호
                dp[i] = Math.max(dp[i], dp[temp] + time); // 더 작업 시간이 긴 값으로 갱신
            }
            ans = Math.max(ans, dp[i]);
        }
        bw.write(ans + "\n");
        bw.flush(); // 자원 해제를 위해 버퍼에 있는 모든 내용을 강제로 출력 스트림에 밀어 넣음
        bw.close();
        br.close();
    }
}
