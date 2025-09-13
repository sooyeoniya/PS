const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, M] = input[0].split(" ").map(Number);

const arr = Array.from({ length: N + 1 }, () => []); // 각 학생 다음으로 와야하는 학생들 넣기
const inDegrees = Array.from({ length: N + 1 }, () => 0); // 진입 차수를 저장한 배열 (각 인덱스는 학생들의 번호 1~N)
const queue = [];
const answer = [];

// first 는 첫 번째 학생이고, 진입차수가 0임 (선행되어야 하는 값이 없으므로)
// second는 두 번째 학생이고 진입차수가 1임
for (let i = 1; i < M + 1; i++) {
  const [first, second] = input[i].split(" ").map(Number);
  arr[first].push(second);
  inDegrees[second]++;
}

// 순회하면서 진입차수가 0인 애가 있는 경우, 모두 큐에 삽입
for (let i = 1; i < N + 1; i++) {
  if (inDegrees[i] === 0) queue.push(i);
}

// 큐를 전부 돌면서 학생들 위상 정렬해주기
// 모든 학생들 다 돌기 전에 큐가 비면 순환참조 생기는거임
while (queue.length) {
  // 사실 진입차수 0인거면 그냥 다 넣어도됨 순서 노상관임. 그래서 shift 쓰면 O(N) 걸리니까 걍 O(1)인 pop 쓰겠음
  const currentStudent = queue.pop();
  answer.push(currentStudent);
  arr[currentStudent].forEach((nextStudentNumber) => {
    // 진입차수 -1 해주기 (연결된 간선 제거)
    inDegrees[nextStudentNumber]--;
    if (inDegrees[nextStudentNumber] === 0) {
      queue.push(nextStudentNumber);
    }
  });
}

console.log(answer.join(" "));
