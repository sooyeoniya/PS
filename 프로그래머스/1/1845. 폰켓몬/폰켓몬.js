function solution(nums) {
    const numsArr = [...new Set(nums)];
    const count = nums.length / 2;
    return count > numsArr.length ? numsArr.length : count;
}