class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int number = n + m;
        while (n > 0 && m > 0)
        {
            if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[--number] = nums1[--m];
            }
            else
            {
                nums1[--number] = nums2[--n];
            }
        }
        while (n > 0)
        {
            nums1[--number] = nums2[--n];
        }
    }
};