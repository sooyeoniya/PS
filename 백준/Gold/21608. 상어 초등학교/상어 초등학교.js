const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

/**
 * [우선순위]
 * 1. 비어있는 칸 중, 좋아하는 학생이 많이 인접한 칸
 * 2. 인접한 칸 중, 비어있는 칸이 가장 많은 칸
 * 3. 행의 번호가 가장 작은 칸, 열의 번호가 가장 작은 칸
 */

const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];

const N = +input.shift();
const studentPreferences = input.map((el) => el.split(" ").map(Number));
const seatingChart = Array.from({ length: N }, () => Array(N).fill(0));

/**
 * 인접한 빈칸과 친구 수를 기반으로 점수 계산
 */
function calculateSeatScore(x, y, favoriteStudents) {
  let emptyCount = 0;
  let friendCount = 0;

  for (let k = 0; k < 4; k++) {
    const adjacentX = x + dx[k];
    const adjacentY = y + dy[k];

    if (adjacentX < 0 || adjacentX >= N || adjacentY < 0 || adjacentY >= N)
      continue;

    if (seatingChart[adjacentX][adjacentY] === 0) {
      emptyCount += 1;
    } else if (favoriteStudents.includes(seatingChart[adjacentX][adjacentY])) {
      friendCount += 1;
    }
  }

  // 빈칸을 더하는 이유: 우선순위대로 자리 선정하기 위함
  return friendCount === 0 ? emptyCount : 10 ** friendCount + emptyCount;
}

/**
 * 모든 빈칸을 확인하여 최고 점수 자리 선택
 */
function selectBestSeat(studentNumber, favoriteStudents) {
  let maxScore = -1;
  let seatX = -1;
  let seatY = -1;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (seatingChart[i][j] === 0) {
        let seatPoint = calculateSeatScore(i, j, favoriteStudents);
        if (maxScore < seatPoint) {
          maxScore = seatPoint;
          [seatX, seatY] = [i, j];
        }
      }
    }
  }
  seatingChart[seatX][seatY] = studentNumber;
}

function solution() {
  let satisfaction = 0;
  let studentPreferencesMap = {};

  for (let i = 0; i < studentPreferences.length; i++) {
    const [studentNumber, ...favoriteStudents] = studentPreferences[i];
    studentPreferencesMap[studentNumber] = favoriteStudents;
    selectBestSeat(studentNumber, favoriteStudents);
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      satisfaction += Math.floor(
        calculateSeatScore(i, j, studentPreferencesMap[seatingChart[i][j]]) / 10
      );
    }
  }

  console.log(satisfaction);
}

solution();
