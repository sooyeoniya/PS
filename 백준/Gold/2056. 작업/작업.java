import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine()); // N 입력
        ArrayList<ArrayList<Integer>> al = new ArrayList<>(); // 작업에 대한 후행 작업 간선 추가
        for (int i = 0; i <= N; ++i) al.add(new ArrayList<>()); // 배열 초기화

        int[] inDegree = new int[N + 1]; // 진입 차수
        int[] time = new int[N + 1]; // 작업 시간

        for (int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());
            inDegree[i] = Integer.parseInt(st.nextToken());
            for (int j = 0; j < inDegree[i]; ++j) {
                int num = Integer.parseInt(st.nextToken());
                al.get(num).add(i);
            }
        }
        bw.write(topologicalSort(N, al, inDegree, time) + "\n");
        bw.flush(); // 자원 해제를 위해 버퍼에 있는 모든 내용을 강제로 출력 스트림에 밀어 넣음
        bw.close();
        br.close();
    }
    
    public static int topologicalSort(int N, ArrayList<ArrayList<Integer>> al, int[] inDegree, int[] time) {
        Queue<Integer> q = new LinkedList<>();
        int[] result = new int[N + 1]; // 해당 작업까지 걸리는 시간
        for (int i = 1; i <= N; ++i) {
            if (inDegree[i] == 0) q.offer(i); // 진입 차수가 0이면 해당 작업 큐에 삽입
            result[i] = time[i]; // 각 작업에 대한 작업 시간 삽입
        }

        while(!q.isEmpty()) {
            int cur = q.poll(); // 큐의 최상위 요소 검색 후 제거

            for (int next : al.get(cur)) {
                result[next] = Math.max(result[next], result[cur] + time[next]);
                inDegree[next]--;
                if (inDegree[next] == 0) q.offer(next);
            }
        }

        int ans = -1;
        for (int i = 1; i <= N; ++i)
            ans = Math.max(ans, result[i]);
        return ans;
    }
}
