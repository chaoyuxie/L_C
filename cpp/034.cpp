class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);
        if (begin < nums.size() && nums[begin] == target)
        {
            return {begin, end - 1};
        }
        return {-1, -1};
    }

  private:
    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
                left = mid + 1;
        }
        return left;
    }
    int upper_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid;
            }
            else
                left = mid + 1;
        }
        return left;
    }
};