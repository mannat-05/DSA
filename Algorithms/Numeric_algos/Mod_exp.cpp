#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007; 

int mod_pow(long long base, long long exp)
{
    long long ans=1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp%2 != 0)
        {
            ans=(ans*base)%MOD;
        }
        base=(base*base) % MOD;
        exp/=2;
    }
    return ans;
}

int main()
{
    long long base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;
    cout << "Result of " << base << "^" << exp << " mod " << MOD << " is: ";
    cout << mod_pow(base, exp) << endl;
    return 0;
}