import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int b, c;
    Node (int b, int c) {
        this.b = b;
        this.c = c;
    }
    @Override
    public int compareTo(Node o) {
        return c - o.c;
    } // Node 객체를 c(비용) 필드 값을 기준으로 오름차순으로 정렬
}
public class Main {
    static int N, M, st, ed;
    static int[] ans;
    static ArrayList<ArrayList<Node>> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stt;
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        // 배열 크기 선언 및 전체 INF 값으로 초기화
        ans = new int[N + 1];
        Arrays.fill(ans, Integer.MAX_VALUE);
        // 2차원 인접리스트 배열 초기화 방법
        arr = new ArrayList<>();
        for (int i = 0; i <= N; ++i)
            arr.add(new ArrayList<>());

        int a, b, c;
        for (int i = 0; i < M; ++i) {
            stt = new StringTokenizer(br.readLine());
            a = Integer.parseInt(stt.nextToken());
            b = Integer.parseInt(stt.nextToken());
            c = Integer.parseInt(stt.nextToken());
            arr.get(a).add(new Node(b, c)); // a -> b 로 가는 비용 c
        }

        stt = new StringTokenizer(br.readLine());
        st = Integer.parseInt(stt.nextToken());
        ed = Integer.parseInt(stt.nextToken());

        dijkstra();

        bw.write(Integer.toString(ans[ed]));
        bw.flush();
        bw.close();
        br.close();
    }

    public static void dijkstra() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(st, 0));
        ans[st] = 0;
        while (!pq.isEmpty()) {
            Node curNode = pq.poll();
            int curPos = curNode.b;
            int curCost = curNode.c;

            if (ans[curPos] < curCost) continue;

            for (Node next : arr.get(curPos)) {
                int nextPos = next.b;
                int nextCost = curCost + next.c;
                if (ans[nextPos] > nextCost) {
                    ans[nextPos] = nextCost;
                    pq.add(new Node(nextPos, nextCost));
                }
            }
        }
    }
}