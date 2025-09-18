const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const N = +input[0];
const dice = input[1].split(" ").map(Number);

if (N === 1) {
  const sum = dice
    .sort((a, b) => a - b)
    .slice(0, 5)
    .reduce((acc, cur) => acc + cur, 0);
  console.log(sum);
} else {
  const visibleFaces = [];

  // 주사위의 반대편 면끼리 비교하여 더 작은 값만 선택 (한쪽 방향에서 보이는 3면만 사용)
  visibleFaces.push(Math.min(dice[0], dice[5])); // A-F 쌍
  visibleFaces.push(Math.min(dice[1], dice[4])); // B-E 쌍
  visibleFaces.push(Math.min(dice[2], dice[3])); // C-D 쌍
  visibleFaces.sort((a, b) => a - b);

  let sum = 0;

  // 꼭짓점 (기본 3면, 바닥쪽에 있는 건 2면)
  sum +=
    visibleFaces.slice(0, 2).reduce((acc, cur) => acc + cur, 0) * 4 + // 바닥쪽 꼭짓점 (2면 보임)
    visibleFaces.slice(0, 3).reduce((acc, cur) => acc + cur, 0) * 4; // 위쪽 꼭짓점 (3면 보임)

  // 꼭짓점 아닌 모서리(기본 2면, 바닥쪽에 있는 건 1면)
  sum +=
    visibleFaces[0] * (N - 2) * 4 + // 바닥쪽 모서리 (1면 보임)
    visibleFaces.slice(0, 2).reduce((acc, cur) => acc + cur, 0) * (N - 2) * 8; // 위쪽 모서리 (2면 보임)

  // 가운데 (기본 1면)
  sum += visibleFaces[0] * (N - 2) * (N - 2) * 5; // 바닥쪽 빼고 나머지 5면 (1면 보임)

  console.log(sum);
}
