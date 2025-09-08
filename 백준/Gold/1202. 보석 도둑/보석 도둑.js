const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

// 시간 복잡도: O(NlogN + KlogN)
// push할 때 logN 걸리는데 이 작업을 보석 개수만큼 N번 반복
// pop할 때 logN 걸리는데 이 작업을 가방 개수만큼 K번 반복
// 공간 복잡도: O(N) - Heap 크기

const [N, K] = input.splice(0, 1)[0].split(" ").map(Number);
const jewels = input
  .splice(0, N)
  .map((el) => {
    const [M, V] = el.split(" ").map(Number);
    return { M, V };
  })
  .sort((a, b) => a.M - b.M); // 보석 무게 기준 오름차순 정렬
const weights = input
  .splice(0, K)
  .map(Number)
  .sort((a, b) => a - b); // 가방 무게 오름차순 정렬

// 우선순위 큐 (Max Heap) - 가격이 높은 순서대로
class PriorityQueue {
  constructor() {
    this.heap = [];
  }

  push(value) {
    this.heap.push(value); // 배열 끝에 새 값 추가
    this.heapifyUp(); // 힙 속성을 유지하기 위해 위로 올라가며 정렬
  }

  pop() {
    if (this.heap.length === 0) return null; // 빈 힙이면 null 반환
    if (this.heap.length === 1) return this.heap.pop(); // 요소가 1개면 그냥 제거

    const max = this.heap[0]; // 최댓값(루트) 저장
    this.heap[0] = this.heap.pop(); // 마지막 요소를 루트로 이동
    this.heapifyDown(); // 힙 속성을 유지하기 위해 아래로 내려가며 정렬
    return max; // 원래 최댓값 반환
  }

  heapifyUp() {
    let index = this.heap.length - 1; // 새로 추가된 요소의 인덱스
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2); // 부모 노드 인덱스
      if (this.heap[parentIndex].V >= this.heap[index].V) break; // 부모가 더 크면 중단
      // 부모와 자식 위치 바꾸기
      [this.heap[parentIndex], this.heap[index]] = [
        this.heap[index],
        this.heap[parentIndex],
      ];
      index = parentIndex; // 부모 위치로 이동
    }
  }

  heapifyDown() {
    let index = 0; // 루트부터 시작
    while (true) {
      let maxIndex = index; // 현재 최댓값의 인덱스
      const leftChild = 2 * index + 1; // 왼쪽 자식 인덱스
      const rightChild = 2 * index + 2; // 오른쪽 자식 인덱스

      // 왼쪽 자식이 더 크면
      if (
        leftChild < this.heap.length &&
        this.heap[leftChild].V > this.heap[maxIndex].V
      ) {
        maxIndex = leftChild;
      }
      // 오른쪽 자식이 더 크면
      if (
        rightChild < this.heap.length &&
        this.heap[rightChild].V > this.heap[maxIndex].V
      ) {
        maxIndex = rightChild;
      }

      if (maxIndex === index) break; // 더 이상 바꿀 게 없으면 중단

      // 현재 노드와 더 큰 자식 노드 위치 바꾸기
      [this.heap[index], this.heap[maxIndex]] = [
        this.heap[maxIndex],
        this.heap[index],
      ];
      index = maxIndex; // 아래로 이동
    }
  }

  isEmpty() {
    return this.heap.length === 0;
  }
}

let jewelIndex = 0;
let totalValue = 0;
const pq = new PriorityQueue();

// 각 가방에 대해 처리
for (let k = 0; k < K; k++) {
  const bagCapacity = weights[k];

  // 현재 가방에 들어갈 수 있는 모든 보석을 우선순위 큐에 추가
  while (jewelIndex < N && jewels[jewelIndex].M <= bagCapacity) {
    pq.push(jewels[jewelIndex]);
    jewelIndex++;
  }

  // 우선순위 큐에서 가격이 가장 높은 보석을 선택
  if (!pq.isEmpty()) {
    const selectedJewel = pq.pop();
    totalValue += selectedJewel.V;
  }
}

console.log(totalValue);
