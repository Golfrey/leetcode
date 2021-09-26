/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    int binarySearchLeft(const vector<int>& numbers, int left, int right, int target) {
        int flag = left;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(numbers[mid] == target)
                return mid;
            else if(numbers[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right < flag ? flag : right;
    }

    int binarySearchRight(const vector<int>& numbers, int left, int right, int target) {
        int flag = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(numbers[mid] == target)
                return mid;
            else if(numbers[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left > flag ? flag : left;
        
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target)
                return vector<int>{left + 1, right + 1};
            else if (numbers[left] + numbers[right] < target) {
                left = binarySearchLeft(numbers, left+1, right-1, target - numbers[right]);
            } else if (numbers[left] + numbers[right] > target) {
                //cout << 1;
                right = binarySearchRight(numbers, left + 1, right - 1,
                                          target - numbers[left]);
            }
            //cout << left << " " << right << endl;
        }
        return vector<int>{};
    }
};
// @lc code=end

