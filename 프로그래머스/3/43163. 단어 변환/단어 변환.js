let answer = Infinity;
let targetWord = "";
let wordsArr;

function solution(begin, target, words) {
    targetWord = target;
    wordsArr = words;

    const visited = Array(begin.length).fill(false);
    dfs(begin, visited);
    
    if (answer !== Infinity) return answer;
    return 0;
}

function dfs(word, visited, step = 0) {
    if (word === targetWord) {
        answer = Math.min(answer, step);
        return;
    }

    wordsArr.forEach((nextWord, nextWordIndex) => {
        if (visited[nextWordIndex]) return;
        visited[nextWordIndex] = true;
        if (oneMatch(word, nextWord)) dfs(nextWord, visited, step + 1);
        visited[nextWordIndex] = false;
    });
    
    return;
}

function oneMatch(word1, word2) {
    let diff = 0;
    for (let i = 0; i < word1.length; i++) {
        if (word1[i] !== word2[i]) {
            diff += 1;
        }
    }

    if (diff === 1) return true;
    return false;
}