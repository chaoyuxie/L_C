class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (target == nums[mid]) {
                return mid;
            } else if (nums[high] < nums[mid]) {  // 左侧有序
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {  // 右侧有序
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

const auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            int m = (i + j) >> 1;
            if (target == nums[m])
                return m;
            else if ((nums[i] <= target && target < nums[m]) || (nums[m] < nums[i] && (target < nums[m] || nums[i] <= target)))
                j = m - 1;
            else if ((nums[m] < target && target <= nums[j]) || (nums[j] < nums[m] && (target <= nums[j] || nums[m] < target)))
                i = m + 1;
            else
                break;
        }
        return -1;
    }
};