import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[][] arr;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; ++i) {
            String s = br.readLine();
            for (int j = 0; j < M; ++j)
                arr[i][j] = s.charAt(j) - '0'; // 문자 -> 숫자
        }

        bfs(0, 0);
        System.out.print(arr[N - 1][M - 1]);
    }

    public static void bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {x, y});
        visited[x][y] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cX = cur[0];
            int cY = cur[1];
            for (int i = 0; i < 4; ++i) {
                int nX = cX + dx[i];
                int nY = cY + dy[i];
                if (nX < 0 || nX >= N || nY < 0 || nY >= M || visited[nX][nY] || arr[nX][nY] == 0) continue;
                visited[nX][nY] = true;
                arr[nX][nY] = arr[cX][cY] + 1;
                q.add(new int[] {nX, nY});
            }
        }
    }
}