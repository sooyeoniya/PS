function solution(participant, completion) {
  const dist = new Map();

  participant.forEach((person) => {
    dist.set(person, (dist.get(person) || 0) + 1);
  });

  completion.forEach((person) => {
    dist.set(person, (dist.get(person) || 0) - 1);
  });

  let result = "";
  dist.forEach((count, person) => {
    if (count === 1) {
      result = person;
      return;
    }
  });
  return result;
}
