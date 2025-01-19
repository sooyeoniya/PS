const fs = require('fs');
const readline = require('readline');
// const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
// const inputs = fs.readFileSync(filePath).toString().trim().split('\n').map(el => el.trim());
// const inputs = fs.readFileSync(0, 'utf-8').trim().split('\n').map(el => el.trim());
const rl = readline.createInterface({
  input: process.platform === 'linux' ? process.stdin : fs.createReadStream('./input.txt'),
  output: process.stdout,
  terminal: false,
});

let input = [];
rl.on('line', (line) => input.push(line));
rl.on('close', () => {
  const T = +input[0];
  let idx = 1;

  for (let t = 0; t < T; t++) {
    const K = +input[idx++];
    const minHeap = new MinHeap();
    const maxHeap = new MaxHeap();
    const visited = new Map(); // 동기화 (값 존재 여부 관리)

    for (let k = 0; k < K; k++) {
      const [command, num] = input[idx++].split(' ');
      const n = +num;

      if (command === 'I') { // 삽입
        minHeap.add(n);
        maxHeap.add(n);
        visited.set(n, (visited.get(n) || 0) + 1); // 동일한 값이 여러 개 있을 수 있으므로 카운트

      } else if (command === 'D') { // 삭제
  
        if (n === 1) { // 최댓값 삭제
          validateValue(maxHeap, visited);
          if (maxHeap.size()) {
            const maxValue = maxHeap.poll(); // 최댓값 반환
            visited.set(maxValue, visited.get(maxValue) - 1);
          }
        } else if (n === -1) { // 최솟값 삭제
          validateValue(minHeap, visited);
          if (minHeap.size()) {
            const minValue = minHeap.poll();
            visited.set(minValue, visited.get(minValue) - 1);
          }
        }
      }
    }

    // 최종 출력 전 힙 동기화
    validateValue(minHeap, visited);
    validateValue(maxHeap, visited);

    if (minHeap.size() && maxHeap.size()) {
      console.log(`${maxHeap.peek()} ${minHeap.peek()}`);
    } else {
      console.log('EMPTY');
    }
  }
});

class Heap {
  constructor(compareFn) {
    this.heap = [];
    this.compare = compareFn;
  }

  // 삽입, O(logN)
  add(item) {
    this.heap.push(item);
    this.bubbleUp();
  }

  // 삭제, O(logN)
  poll() {
    if (this.size() === 1) return this.heap.pop();
    let root = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.bubbleDown();
    return root;
  }

  peek() {
    return this.heap[0];
  }

  size() {
    return this.heap.length;
  }

  bubbleUp() {
    let idx = this.size() - 1;
    const cur = this.heap[idx];
    while (idx > 0 && this.compare(cur, this.heap[Math.floor((idx - 1) / 2)]) < 0) {
      this.heap[idx] = this.heap[Math.floor((idx - 1) / 2)];
      idx = Math.floor((idx - 1) / 2);
    }
    this.heap[idx] = cur;
  }

  bubbleDown() {
    let idx = 0;
    const cur = this.heap[idx];
    while (idx * 2 + 1 < this.size()) {
      let child = idx * 2 + 1;
      if (child + 1 < this.size() && this.compare(this.heap[child + 1], this.heap[child]) < 0) {
        child++;
      }
      if (this.compare(cur, this.heap[child]) <= 0) break;
      this.heap[idx] = this.heap[child];
      idx = child;
    }
    this.heap[idx] = cur;
  }
}

class MinHeap extends Heap {
  constructor() {
    super((a, b) => a - b);
  }
}

class MaxHeap extends Heap {
  constructor() {
    super((a, b) => b - a);
  }
}

// 유효성 검증: 이미 삭제되어 값이 존재하지 않는 경우
const validateValue = (heap, visited) => {
  while (heap.size() && visited.get(heap.peek()) === 0) {
    heap.poll(); // 불필요한 루트 값 제거
  }
}
