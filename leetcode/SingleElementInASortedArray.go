func singleNonDuplicate(nums []int) int {
  start, end := 0, len(nums)
  for end - start > 1 {
    mid := start + (end - start) / 2
    if nums[mid] == nums[mid - 1] {
      if mid % 2 == 0 {
        end = mid - 1
      } else {
        start = mid + 1
      }
    } else if nums[mid] == nums[mid + 1] {
      if mid % 2 == 0 {
        start = mid + 2
      } else {
        end = mid
      }
    } else {
      return nums[mid]
    }
  }
  return nums[start]
}
