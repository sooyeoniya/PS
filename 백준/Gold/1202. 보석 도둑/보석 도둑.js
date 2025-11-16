const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

class MaxHeap {
  constructor() {
    this.heap = [];
  }

  isEmpty() {
    return this.heap.length === 0;
  }

  push(value) {
    this.heap.push(value);
    this.bubbleUp();
  }

  pop() {
    if (this.heap.length === 0) return null;
    if (this.heap.length === 1) return this.heap.pop();

    const value = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.bubbleDown();
    return value;
  }

  swap(index1, index2) {
    [this.heap[index1], this.heap[index2]] = [
      this.heap[index2],
      this.heap[index1],
    ];
  }

  bubbleUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      if (this.heap[index].V <= this.heap[parentIndex].V) break;
      this.swap(index, parentIndex);
      index = parentIndex;
    }
  }

  bubbleDown() {
    let index = 0;
    while (true) {
      let nextIndex = index;
      const leftChildIndex = index * 2 + 1;
      const rightChildIndex = index * 2 + 2;

      if (
        leftChildIndex < this.heap.length &&
        this.heap[leftChildIndex].V > this.heap[nextIndex].V
      ) {
        nextIndex = leftChildIndex;
      }

      if (
        rightChildIndex < this.heap.length &&
        this.heap[rightChildIndex].V > this.heap[nextIndex].V
      ) {
        nextIndex = rightChildIndex;
      }

      if (nextIndex === index) break;
      this.swap(index, nextIndex);
      index = nextIndex;
    }
  }
}

const [N, K] = input.shift().split(" ").map(Number);
const jewels = input
  .splice(0, N)
  .map((el) => {
    const [M, V] = el.split(" ").map(Number);
    return { M, V };
  })
  .sort((a, b) => a.M - b.M);
const weights = input
  .splice(0, K)
  .map(Number)
  .sort((a, b) => a - b);

let jewelIndex = 0;
let totalValue = 0;
const heap = new MaxHeap();

for (let k = 0; k < K; k++) {
  const bagCapacity = weights[k];

  while (jewelIndex < N && jewels[jewelIndex].M <= bagCapacity) {
    heap.push(jewels[jewelIndex]);
    jewelIndex++;
  }

  if (!heap.isEmpty()) {
    const selectedJewel = heap.pop();
    totalValue += selectedJewel.V;
  }
}

console.log(totalValue);
