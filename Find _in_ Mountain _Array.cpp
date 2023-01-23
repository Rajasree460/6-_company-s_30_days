/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

        class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      int n = mountainArr.length();
        
      int bitonic_point = findpeak(mountainArr, n);

      if(target > mountainArr.get(bitonic_point)) {
        return -1;
      }

      int bin = binary_search(mountainArr, target, bitonic_point);

      if(bin != -1) {
        return bin;
      }
      else {
        return reverse_binary_search(mountainArr, n, target, bitonic_point);
      }

      return -1;
}
    
int findpeak(MountainArray &nums, int n) {
  int start = 0;
  int end = n - 1;

  while(start <= end) {
    int mid = start + (end - start) / 2;

    if(nums.get(start) > nums.get(start + 1)) {
      return start;
    }
    if(nums.get(end) > nums.get(end - 1)) {
      return end;
    }

    if(nums.get(mid) > nums.get(mid - 1) && nums.get(mid) > nums.get(mid + 1)) {
      return mid;
    }
    else if(nums.get(mid + 1) > nums.get(mid)) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }

  return -1;
}

int binary_search(MountainArray &arr, int to_search, int bitonic_point) {
  int start = 0;
  int end = bitonic_point - 1;

  while(start <= end) {
    int mid = start + (end - start) / 2;

    if(arr.get(mid) == to_search) {
      return mid;
    }
    else if(to_search < arr.get(mid)) {
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
  }
  return -1;
}

int reverse_binary_search(MountainArray &arr, int n, int to_search, int bitonic_point) {
  int start = bitonic_point;
  int end = n - 1;

  while(start <= end) {
    int mid = start + (end - start) / 2;

    if(arr.get(mid) == to_search) {
      return mid;
    }
    else if(to_search < arr.get(mid)) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }
  return -1;
}
};
