class Solution {
public:
    int gcd(int a, int b)
    {
        while(b != 0){
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long MOD = 1e9 + 7;
        long long lb = min(a,b), ub = 1LL*n * min(a, b);
        long long lcm = (1LL*a * b) / gcd(a, b);
        while(lb < ub)
        {
            long long mid = (lb + ub) / 2;
            if(((mid / a) + (mid / b) - (mid / lcm)) < n)
            {
                lb = mid + 1;
            }
            else
            {
                ub = mid;
            }
        }
        return (int) (lb % MOD);
    }
};