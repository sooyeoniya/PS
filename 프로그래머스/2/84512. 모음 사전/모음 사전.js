const vowel = ['A', 'E', 'I', 'O', 'U'];
const dictionary = [];

function solution(word) {   
    reculsive();
    return dictionary.indexOf(word);
}

function reculsive(curWord = '', length = 0) {
    if (length > 5) return;
    
    dictionary.push(curWord);
    
    for (let word of vowel) {
        reculsive(curWord + word, length + 1);
    }
}