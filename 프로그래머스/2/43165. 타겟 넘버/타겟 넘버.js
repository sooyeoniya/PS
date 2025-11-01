function solution(numbers, target) {
    let answer = {value: 0};
    recursive(numbers,target,answer);
    return answer.value;
}


function recursive(numbers,target,answer,round=0,total=0) {
    if(round === numbers.length){
        if(total === target){
             answer.value+=1;
        }
        return;
    }
    recursive(numbers,target,answer,round+1,total - numbers[round]);
    recursive(numbers,target,answer,round+1,total +  numbers[round]);
}