class Solution
{
  public:
    bool isPalindrome(int x)
    {
        long tmp = abs(x);
        long reverse = 0;

        while (tmp)
        {
            reverse = reverse * 10 + (tmp % 10);
            tmp /= 10;
        }
        return reverse == x;
    }
};