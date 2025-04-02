function solution(answers) {    
    const cycle_1 = [1, 2, 3, 4, 5];
    const cycle_2 = [2, 1, 2, 3, 2, 4, 2, 5];
    const cycle_3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    
    const arr = [0, 0, 0];
    answers.forEach((answer, index) => {
        if (answer === cycle_1[index % cycle_1.length]) arr[0] += 1;
        if (answer === cycle_2[index % cycle_2.length]) arr[1] += 1;
        if (answer === cycle_3[index % cycle_3.length]) arr[2] += 1;
    });
    
    const result = [];
    const max = Math.max(...arr);
    arr.forEach((el, index) => { if (el === max) result.push(index + 1); });
    return result;
}