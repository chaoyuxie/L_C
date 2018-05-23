///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//本题基本思路找到需要排序的元素的最大最以及最小值min_，max_
//确定数值之后找到第一个比main_大的数值的下标并break;正向查找
//再找到第一个比max_小的数值的下标并break;反向查找
//最后返回j-i+1;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution
{
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int i = 0, j = -1, max_ = INT_MIN, min_ = INT_MAX;

        for (int l = 0, r = nums.size() - 1; r >= 0; l++, r--)
        {
            max_ = max(max_, nums[l]);
            if (nums[l] != max_)
                j = l;

            min_ = min(min_, nums[r]);
            if (nums[r] != min_)
                i = r;
        }

        return (j - i + 1);
    }
};