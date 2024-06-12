import java.io.*;

public class Main {
    static int N;
    static boolean[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new boolean[7][N];
        match(0, N, false, 0);
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < N; ++j) {
                if (arr[i][j]) System.out.print('A');
                else System.out.print('B');
            }
            System.out.println();
        }
    }
    public static void match(int st, int ed, boolean team, int day) {
        if (day == 7) return;
        int mid = (st + ed) / 2;
        for (int i = st; i < ed; ++i)
            arr[day][i] = (i < mid) == team;
        match(st, mid, !team, day + 1);
        match(mid, ed, team, day + 1);
    }
}