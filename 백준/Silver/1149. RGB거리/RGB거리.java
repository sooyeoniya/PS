// https://st-lab.tistory.com/128
// Java 입출력과 관련된 클래스들을 import
import java.io.BufferedReader;  // BufferedReader 클래스는 문자 입력 스트림에서 문자를 읽는 데 사용됨
import java.io.InputStreamReader;  // InputStreamReader 클래스는 바이트 스트림을 문자 스트림으로 변환하는 데 사용됨
import java.io.IOException;  // 입출력 예외를 처리하기 위한 IOException 클래스
import java.util.StringTokenizer;  // StringTokenizer 클래스는 문자열을 토큰으로 분리하는 데 사용됨

public class Main {
    final static int R = 0;  // Red 색상을 나타내는 상수
    final static int G = 1;  // Green 색상을 나타내는 상수
    final static int B = 2;  // Blue 색상을 나타내는 상수

    public static void main(String[] args) throws IOException {  // 메인 메서드 정의, IOException을 던질 수 있음
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  // BufferedReader 객체 생성, InputStreamReader를 사용하여 System.in(표준 입력)을 감쌈
        StringTokenizer st;  // StringTokenizer 객체 선언

        int N = Integer.parseInt(br.readLine());  // 표준 입력에서 한 줄을 읽고 정수로 변환
        int[][] Cost = new int[N][3];  // N x 3 크기의 2차원 배열 선언, 각 집을 색칠하는 비용을 저장

        for (int i = 0; i < N; ++i) {  // N번 반복하여 각 집의 색칠 비용을 입력받음
            st = new StringTokenizer(br.readLine(), " ");  // 입력받은 한 줄을 공백(" ")을 기준으로 분리
            Cost[i][R] = Integer.parseInt(st.nextToken());  // 첫 번째 토큰을 정수로 변환하여 Cost[i][R]에 저장
            Cost[i][G] = Integer.parseInt(st.nextToken());  // 두 번째 토큰을 정수로 변환하여 Cost[i][G]에 저장
            Cost[i][B] = Integer.parseInt(st.nextToken());  // 세 번째 토큰을 정수로 변환하여 Cost[i][B]에 저장
        }

        for (int i = 1; i < N; ++i) {  // 첫 번째 집을 제외한 나머지 집들에 대해 최소 비용을 계산
            Cost[i][R] += Math.min(Cost[i - 1][G], Cost[i - 1][B]);  // i번째 집을 Red로 색칠하는 최소 비용 계산
            Cost[i][G] += Math.min(Cost[i - 1][R], Cost[i - 1][B]);  // i번째 집을 Green으로 색칠하는 최소 비용 계산
            Cost[i][B] += Math.min(Cost[i - 1][R], Cost[i - 1][G]);  // i번째 집을 Blue로 색칠하는 최소 비용 계산
        }

        System.out.println(Math.min(Cost[N - 1][R], Math.min(Cost[N - 1][G], Cost[N - 1][B])));  // 마지막 집까지 색칠한 후, 최소 비용을 출력
    }
}
