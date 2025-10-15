function solution(brown, yellow) {
  const totalBlocks = brown + yellow;
  let candidateWidth = 0;
  let candidateHeight = 0;

  const MIN_HEIGHT = 3;
  const BORDER_THICKNESS = 2;

  for (let height = MIN_HEIGHT; height <= totalBlocks / MIN_HEIGHT; height++) {
    if (totalBlocks % height === 0) {
      const width = totalBlocks / height;

      const innerWidth = width - BORDER_THICKNESS;
      const innerHeight = height - BORDER_THICKNESS;
      const isYellowMatch = innerWidth * innerHeight === yellow;

      if (isYellowMatch) {
        candidateWidth = width;
        candidateHeight = height;
        break;
      }
    }
  }

  return [Math.max(candidateWidth, candidateHeight), Math.min(candidateWidth, candidateHeight)];
}
