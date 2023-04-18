/*
    author:  Mustafa Elsharawy
    @Date: 2023-04-18
*/

#include <bits/stdc++.h>
using namespce std;

// My maths templates

struct Maths
{

    // Greatest Common Divisor

    long long GCD(long long a, long long b)
    {
        return !b ? a : GCD(b, a % b);
    }

    // Least Common Multiple

    long long LCM(long long a, long long b)
    {
        return a / GCD(a, b) * b;
    }

    // permutuation

    long long nPr(long long n, long long r)
    {
        if(r > n) return 0;
        long long res = 1;
        while(r-- > 0)
            res *= n--;
        return res;
    }

    // Combination
    
    long long nCr(long long n, long long r)
    {
        if(r > n) return 0;
        long long res = 1, k = 1;
        // condition for minimum choice
        if (n - r < r) r = n - r;
        if(n < 1) return 0;
        while (r > 0)
        {
            res *= n, k *= r;
            long long m = __gcd(res, k);
            res /= m, k /= m, n--, r--;        
        }
        return res;
    }

    // Number % x

    long long bigMod(string s, long long mod){
        long long res = 0;
        for(auto& c : s)
            res = (res * 10 + (c - '0')) % mod;
        return res;
    }

    // Fast power in O(log(N))

    long long fastPower(long long a, long long b)
    {
        long long res = 1;
        while(b)
        {
            if(b & 1) res *= a;
            b >>= 1;
            a *= a;
        }
        return res;
    }
    
    // Fast power using mod in O(log(N))

    long long fastPower(long long a, long long b, long long mod = 1e9 + 7)
    {
        long long res = 1;
        while(b)
        {
            if(b & 1) res *= a % mod;
            res %= mod;
            b >>= 1;
            a *= a % mod;
            a %= mod;
        }
        return res;
    }

    // Check whether the number is prime or not in O(sqrt(N))

    bool isPrime(long long num)
    {
        if(num < 2 || (num % 2 == 0 && num != 2))
            return 0;
        for(long long i = 3; i * i <= num; i++)
            if(num % i == 0)
                return 0;
        return 1;
    }

    // Function to get the number of divisors of a number in O(sqrt(N))

    int numOfDivisors(long long num)
    {
        ll res = 0;
        for(long long i = 1; i * i <= num; i++)
        {
            if(num % i == 0)
            {
                res += 2;
                if(i * i == num)
                    res--;
            }
        }
        return res;
    }

    // Function to get the divisors of a number in O(sqrt(N))

    vector<long long> getDivisors(long long num, bool sorted = 1)
    {
        vector<long long> res;
        for(long long i = 1; i * i <= num; i++)
        {
            if(num % i == 0)
            {
                res.push_back(i);
                if(i * i != num)
                    res.push_back(num / i);
            }
        }
        if(sorted)
            sort(res.begin(), res.end());
        return res;
    }
    
    // Function to get prime factors of any number in O(sqrt(N))

    vector<long long> primesFactors(long long num)
    {
        vector<long long> res;
        for(long long i = 2; i * i <= num; i++)
        {
            while(num % i == 0)
            {
                res.push_back(i);
                num /= i;
            }
        }
        if(num > 1)
            res.push_back(num);
        return res;
    }

    // Function to get all primes value in range 2 -> 1e7
    
    vector<long long> primesSeive(long long num = 1e7)
    {
        num += 5;
        vector<int> is_prime(num, true);
        is_prime[0] = is_prime[1] = 0;
        for(long long i = 2; i * i <= num; i++)
        {
            if(is_prime[i])
                for(long long j = i + i; j <= num; j += i)
                    is_prime[j] = 0;
        }
        vector<long long> res;
        for(int i = 2; i < num; i++)
        {
            if(is_prime[i])
                res.push_back(i);
        }
        return res;
    }
}Maths;


int main()
{

}