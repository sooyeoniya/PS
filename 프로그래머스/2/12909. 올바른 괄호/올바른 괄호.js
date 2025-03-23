// 내 풀이
function solution(s) {
  var answer = true;

  let stack = [];

  for (const c of s) {
    if (stack.length === 0) {
      stack.push(c);
    } else {
      if (c === "(") {
        stack.push(c);
      } else if (c === ")") {
        if (stack[stack.length - 1] === "(") {
          stack.pop(c);
        } else if (stack[stack.length - 1] === ")") {
          stack.push(c);
        }
      }
    }
  }

  if (stack.length !== 0) answer = false;

  return answer;
}

// 다른 사람 풀이
function solution(s) {
  let count = 0;

  for (const c of s) {
    count += c === "(" ? 1 : -1;
    if (count < 0) return false;
  }

  return count === 0;
}
