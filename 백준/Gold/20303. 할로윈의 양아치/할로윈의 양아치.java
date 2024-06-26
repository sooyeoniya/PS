// 풀이 시간: 2h06m43s27 + 57m25s13(참고)
// 시간 복잡도: O(N + M + G * K)
// 공간 복잡도: O(N + M + G + K)
import java.io.*;
import java.util.*;

public class Main {
    static class Group {
        int num, total; // 그룹별 아이들 수, 총 사탕 수
        public Group(int num, int total) {
            this.num = num;
            this.total = total;
        }
    }
    static int N, M, K;
    static int relationNum, totalCandy; // 각 그룹 별 친구 관계 수와 총 사탕 수 임시 저장용
    static int[] c; // 아이들 별 사탕 수
    static boolean[] visited; // 방문 여부
    static ArrayList<Integer>[] relation; // 각 아이 별 친구 관계
    static ArrayList<Group> group; // 친구 관계 그룹

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 아이들 수
        M = Integer.parseInt(st.nextToken()); // 아이들 친구 관계 수
        K = Integer.parseInt(st.nextToken()); // 공명을 위한 최소 아이들 수

        // 배열 초기화
        c = new int[N];
        visited = new boolean[N];
        relation = new ArrayList[N];
        for (int i = 0; i < N; ++i)
            relation[i] = new ArrayList<>();
        group = new ArrayList<>();

        // 사탕 수 입력
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            c[i] = Integer.parseInt(st.nextToken());

        // 친구 관계 입력 (인접 리스트)
        for (int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            relation[a].add(b);
            relation[b].add(a);
        }

        // 친구 관계별 그룹으로 나누기
        for (int i = 0; i < N; ++i) {
            // 매번 초기화
            relationNum = 0;
            totalCandy = 0;
            // 방문하지 않은 아이
            if (!visited[i]) {
                dfs(i);
                group.add(new Group(relationNum, totalCandy)); // 그룹 생성
            }
        }

        // 그룹 조합 중 K 미만인 아이들 수로 만들 수 있는 가장 큰 사탕 수 (노션 참고)
        int[][] dp = new int[2][K];
        for (Group cur : group) {
            for (int i = 0; i < K; ++i) {
                if (i >= cur.num)
                    dp[1][i] = Math.max(dp[0][i], dp[0][i - cur.num] + cur.total);
                else
                    dp[1][i] = dp[0][i];
            }
            // 슬라이딩 윈도우
            for (int i = 0; i < K; ++i)
                dp[0][i] = dp[1][i];
        }

        // 가장 큰 값 출력
        bw.write(Integer.toString(dp[1][K - 1])); // 정수 -> 문자열
        bw.flush();
        bw.close();
    }

    public static void dfs(int idx) {
        visited[idx] = true;
        relationNum++;
        totalCandy += c[idx];
        // 친구 관계에 있는 아이 방문
        for (int next : relation[idx])
            if (!visited[next]) dfs(next);
    }
}