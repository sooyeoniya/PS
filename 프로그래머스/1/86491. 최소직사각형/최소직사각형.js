function solution(sizes) {
    const maxArr = [];
    const minArr = [];
    
    sizes.forEach(([first, second]) => {
        maxArr.push(Math.max(first, second));
        minArr.push(Math.min(first, second));
    })
    
    const max = Math.max(...maxArr);
    const min = Math.max(...minArr);
    
    return max * min;
}
