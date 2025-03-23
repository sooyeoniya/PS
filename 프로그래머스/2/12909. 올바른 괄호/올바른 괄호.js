function solution(s){
    var answer = true;

    let stack = [];
    
    for (const c of s) {
        if (stack.length === 0) {
            stack.push(c);
        } else {
            if (c === '(') {
                stack.push(c);
            } else if (c === ')') {
                if (stack[stack.length - 1] === '(') {
                    stack.pop(c);
                } else if (stack[stack.length - 1] === ')') {
                    stack.push(c);
                }
            }
        }
    }

    if (stack.length !== 0) answer = false;

    return answer;
}