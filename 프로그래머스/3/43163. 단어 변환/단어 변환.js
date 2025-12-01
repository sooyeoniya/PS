var answer = 0;
function solution(begin, target, words) {
    const visited = Array(words.length).fill(false);
    reculsive(begin, target, words, visited);
    return answer;
}

function reculsive(curWord, target, words, visited, count = 0) {
    if (curWord === target) {
        answer = count;
        return;
    }

    for (let i = 0; i < words.length; i++) {
        if (visited[i]) continue;
        if (!isOneLetterDifferent(words[i], curWord)) continue;
        visited[i] = true;
        reculsive(words[i], target, words, visited, count + 1);
        visited[i] = false;
    }
}

function isOneLetterDifferent(word1, word2) {
    let count = 0;
    for (let i = 0; i < word1.length; i++) {
       if (word1[i] !== word2[i]) count++;
    }
    
    if (count === 1) return true;
    return false;
}
