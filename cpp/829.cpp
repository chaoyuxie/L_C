////////////////////////////////////////////////////////////////////////////////
//本题思路如下：N = x + x+1 + x+2 + ... + x+k-1 = k(x+(k-1)/2)
//上式可以写成 2N = k(2x+k-1) ===> kx = N-k(k-1)/2>=k
//再次变换：N >= k(k+1)/2 ===> k<=sqrt(2N)
////////////////////////////////////////////////////////////////////////////////
//Solution 1:
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int result = 1;
        while (N % 2 == 0) {
            N /= 2;
        }
        for (int i = 3; i * i <= N; i += 2) {
            int count = 0;
            while (N % i == 0) {
                N /= i;
                ++count;
            }
            result *= count + 1;
        }
        if (N > 1) {
            result *= 2;
        }
        return result;
    }
};

//Solution 2:
class Solution
{
    public:
    int consecutiveNumbersSum(int N) 
    {
        int count = 1;
        for(int k = 2; k < sqrt(2*N); ++k)
        {
            if((N-k(k-1)/2)%k==0) count++;
        }
        return count;
    }
};