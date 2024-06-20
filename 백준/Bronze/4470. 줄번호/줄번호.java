import java.io.*;

public class Main {
    static int N;
    static String[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new String[N + 1];
        for (int i = 1; i <= N; ++i) arr[i] = br.readLine();
        for (int i = 1; i <= N; ++i) System.out.println(i + ". " + arr[i]);
    }
}