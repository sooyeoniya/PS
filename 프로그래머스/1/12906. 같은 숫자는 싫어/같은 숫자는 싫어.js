function solution(arr)
{
    let idx = 0;
    let answer = [arr[0]];
    
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] !== answer[idx]) {
            answer.push(arr[i]);
            idx += 1;
        }
    }
    
    return answer;
}