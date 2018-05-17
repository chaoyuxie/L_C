//////////////////////////////////////////////////////////////////////////////////////////////
//正负号标记法                                                                               //
//                                                                                          //
//遍历数组nums，记当前元素为n，令nums[abs(n) - 1] = -abs(nums[abs(n) - 1])                    //
//                                                                                          //
//再次遍历nums，将正数对应的下标+1返回即为答案，因为正数对应的元素没有被上一步骤标记过。           //
//////////////////////////////////////////////////////////////////////////////////////////////

class Solution
{
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] > 0 ? -nums[abs(nums[i]) - 1] : nums[abs(nums[i]) - 1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                result.push_back(i + 1);
            else
                nums[i] = -nums[i];
        }
        return result;
    }
};