#include <iostream>
#include <cmath>
using namespace std;
int isprime(int num)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int num;
    while (cin >> num)
    {
        if (num == 0)
            break;
        else
        {
            for (int i = 3; i < num / 2; i++)
            {
                if (isprime(i) == 1 && isprime(num - i) == 1)
                {
                    cout << num << " " << i << " + " << num - i << endl;
                    break;
                }
            }
        }
    }
}