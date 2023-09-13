/*
    author: Mustafa Elsharawy
    created: 2023-09-13 07:52:42
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;

struct Fenwick_Tree 
{
    vector < ll > Tree;
    int n;
 
    Fenwick_Tree(ll N){
        n = N + 1;
        Tree.assign(n + 10, 0);
    }
 
    ll lowest_bit(ll idx){
        return (idx & -idx);
    }
 
    void build(vector < ll >& nums){
        for(int i = 0; i < (int)nums.size(); i++)
            add(i, nums[i]);
    }
 
    void add(ll idx, ll val){
        idx++;
        while(idx <= n){
            Tree[idx] += val;
            idx += lowest_bit(idx);
        }
    }
 
    ll get_sum(ll idx){
        ll sum = 0;
        idx++;
        while(idx){
            sum += Tree[idx];
            idx -= lowest_bit(idx);
        }
        return sum;
    }
 
    ll query(ll l, ll r){
        if(l > r) swap(l, r);
        return get_sum(r) - get_sum(l - 1);
    }
 
};

int main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int testCase = 1;
    // cin >> testCase;
    while (testCase--)
    {
        int n;      cin >> n;
        Fenwick_Tree ft(n);
        vector < ll > nums(n);
        for(auto & i : nums)    cin >> i;
        ft.build(nums);
        ft.add(0, 1);
        cout << ft.query(0, 0);
    }
    return 0;
}