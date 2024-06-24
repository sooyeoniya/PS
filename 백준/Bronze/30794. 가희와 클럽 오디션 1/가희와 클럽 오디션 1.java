import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int lv = Integer.parseInt(st.nextToken());
		
		switch(st.nextToken()) {
			case "miss":
				bw.write(String.valueOf(0));
				break;
			case "bad":
				bw.write(String.valueOf(lv * 200));
				break;
			case "cool":
				bw.write(String.valueOf(lv * 400));
				break;
			case "great":
				bw.write(String.valueOf(lv * 600));
				break;
			case "perfect":
				bw.write(String.valueOf(lv * 1000));
				break;
			default:
				break;
		}
		bw.flush();
		bw.close();
	}
}