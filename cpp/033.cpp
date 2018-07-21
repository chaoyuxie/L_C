class Solution(){
    public :
        int search(vector<int> & nums, target){
            int left = 0;
int right = nums.size() - 1;
while (left <= right)
{
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[right] < nums[mid])
    {
        if (target >= nums[left] && target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    else
    {
        if (target > nums[mid] && target <= nums[high])
            low = mid + 1;
        else
            high = mid - 1;
    }
}
return -1;
}
}
;

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