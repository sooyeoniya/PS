const solution = (numbers) => {
  const digits = numbers.split("");
  let candidates = [];

  const makePermutations = (current, remaining, targetLength) => {
    if (current.length === targetLength) {
      const num = Number(current);
      if (!candidates.includes(num)) candidates.push(num);
      return;
    }

    remaining.forEach((digit, index) => {
      const next = current + digit;
      const nextRemaining = remaining.filter((_, i) => i !== index);
      makePermutations(next, nextRemaining, targetLength);
    });
  };

  for (let startIdx = 0; startIdx < digits.length; startIdx++) {
    const firstDigit = digits[startIdx];
    const restDigits = digits.filter((_, i) => i !== startIdx);

    for (let targetLength = 1; targetLength <= digits.length; targetLength++) {
      makePermutations(firstDigit, restDigits, targetLength);
    }
  }

  const isPrime = (num) => {
    if (num < 2) return false;
    for (let i = 2; i <= Math.sqrt(num); i++) {
      if (num % i === 0) return false;
    }
    return true;
  };

  return candidates.filter(isPrime).length;
};
