const visited = new Map();

function solution(operations) {
    var answer = [];
    const minHeap = new MinHeap();
    const maxHeap = new MaxHeap();

    operations.forEach(str => {
        const [command, n] = str.split(' ');
        const num = +n;
        if (command === 'I') {
            minHeap.add(num);
            maxHeap.add(num);
            visited.set(num, (visited.get(num) || 0) + 1);
        } else if (command === 'D') {
            if (num === 1) {
                validateValue(maxHeap);
                if (maxHeap.size()) {
                    const maxValue = maxHeap.poll();
                    visited.set(maxValue, visited.get(maxValue) - 1);
                }
            } else if (num === -1) {
                validateValue(minHeap);
                if (minHeap.size()) {
                    const minValue = minHeap.poll();
                    visited.set(minValue, visited.get(minValue) - 1);
                }
            }
        }
    });
    
    validateValue(minHeap);
    validateValue(maxHeap);

    if (minHeap.size() && maxHeap.size()) {
        answer.push(maxHeap.peek());
        answer.push(minHeap.peek());
    } else {
        answer = [0, 0];
    }
    return answer;
}

class Heap {
    constructor(compareFn) {
        this.heap = [];
        this.compare = compareFn;
    }
    
    add(item) {
        this.heap.push(item);
        this.bubbleUp();
    }

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

    #swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
    }

    bubbleUp() {
        let idx = this.size() - 1;
        while (idx > 0 && this.compare(this.heap[idx], this.heap[Math.floor((idx - 1) / 2)]) < 0) {
            this.#swap(idx, Math.floor((idx - 1) / 2));
            idx = Math.floor((idx - 1) / 2);
        }
    }

    bubbleDown() {
        let idx = 0;
        while (idx * 2 + 1 < this.size()) {
            let childIdx = idx * 2 + 1;
            if (childIdx + 1 < this.size() && this.compare(this.heap[childIdx + 1], this.heap[childIdx]) < 0) {
                childIdx++;
            }
            if (this.compare(this.heap[idx], this.heap[childIdx]) <= 0) break;
            this.#swap(idx, childIdx);
            idx = childIdx;
        }
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

const validateValue = (heap) => {
    while (heap.size() && visited.get(heap.peek()) === 0) {
        heap.poll();
    }
}
