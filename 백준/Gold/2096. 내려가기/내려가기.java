// 풀이 시간: 42m17s50 + 10m(메모리 초과 수정)
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int minScore = Integer.MAX_VALUE;
        int maxScore = 0;
        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][3];
        int[][] dpMax = new int[N][3];
        int[][] dpMin = new int[N][3];

        // 입력
        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; ++j) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (i == 0) { // dp 초기화 (첫 번째 줄 값 그대로 삽입)
                    dpMax[i][j] = arr[i][j];
                    dpMin[i][j] = arr[i][j];
                }
            }
        }

        // 최대 및 최소 점수 계산
        for (int i = 1; i < N; ++i) {
            dpMax[i][0] = Math.max(dpMax[i - 1][0], dpMax[i - 1][1]) + arr[i][0];
            dpMin[i][0] = Math.min(dpMin[i - 1][0], dpMin[i - 1][1]) + arr[i][0];

            dpMax[i][1] = Math.max(dpMax[i - 1][1], Math.max(dpMax[i - 1][0], dpMax[i - 1][2])) + arr[i][1];
            dpMin[i][1] = Math.min(dpMin[i - 1][1], Math.min(dpMin[i - 1][0], dpMin[i - 1][2])) + arr[i][1];

            dpMax[i][2] = Math.max(dpMax[i - 1][2], dpMax[i - 1][1]) + arr[i][2];
            dpMin[i][2] = Math.min(dpMin[i - 1][2], dpMin[i - 1][1]) + arr[i][2];
        }

        // 최대 및 최소 점수 구하기
        for (int i = 0; i < 3; ++i) {
            maxScore = Math.max(dpMax[N - 1][i], maxScore);
            minScore = Math.min(dpMin[N - 1][i], minScore);
        }

        bw.write(maxScore + " " + minScore);
        bw.flush();
        bw.close();
    }
}