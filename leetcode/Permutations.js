function swap(arr, i, j) {
  const tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

function generatePermutation(first, arr, len, result) {
  if (len === 0) {
    result.push([...first]);
  } else {
    for (let i = 0; i < len; ++i) {
      first.push(arr[i]);
      swap(arr, i, len - 1);
      generatePermutation(first, arr, len - 1, result);
      swap(arr, len - 1, i);
      first.pop();
    }
  }
  return result;
}

function permute(nums) {
  return generatePermutation([], nums, nums.length, []);
}
