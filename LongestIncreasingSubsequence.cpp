/*
    author:  Mustafa Elsharawy
    @Date: 2023-08-08
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector < int > lisValues(vector<int>& nums)
{
    int n = nums.size();
    vector < int > res;
    vector < int > test1;
    vector < int > test2;
    for(int i = 0; i < n; i++)
        if(test1.empty() || test1.back() < nums[i])
        {
            test1.push_back(nums[i]);
            test2.push_back(i);
        }
        else
        {
            int idx = lower_bound(begin(test1), end(test1), nums[i]) - begin(test1);
            test1[idx] = nums[i];
            test2[idx] = i;
        }
    int len = test1.size();
    test1.clear();
    test2.clear();
    for(int i = 0; i < n; i++)
        if(test1.empty() || test1.back() < nums[i])
        {
            test1.push_back(nums[i]);
            test2.push_back(i);
            if(test1.size() == len)
            {
                break;
            }
        }
        else
        {
            int idx = lower_bound(begin(test1), end(test1), nums[i]) - begin(test1);
            test1[idx] = nums[i];
            test2[idx] = i;
        }
    int j = 0;
    for(int i = 0; i < test1.size(); i++)
    {
        if((i < test1.size() - 1 && test2[i] > test2[i+1]) || (i > 0 && test2[i] < test2[i-1]))
        {
            for(; j < n; j++)
            {
                if(i > 0 && i < test1.size() - 1)
                {
                    if(nums[j] > test1[i-1] && nums[j] < test1[i+1] && j > test2[i-1] && j < test2[i+1])
                    {
                        test1[i] = nums[j], test2[i] = j;
                        break;
                    }
                }
                else if(i > 0)
                {
                    if(nums[j] > test1[i-1] && j > test2[i-1])
                    {
                        test1[i] = nums[j], test2[i] = j;
                        break;
                    }
                }
                else
                {
                    if(nums[j] < test1[i+1] && j < test2[i+1])
                    {
                        test1[i] = nums[j], test2[i] = j;
                        break;
                    }
                }
            }
        }
    }
    for(auto & i : test1)
        res.push_back(i);
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; 
        cin >> n;
        vector < int > nums(n);
        for(auto & i : nums)
            cin >> i;
        vector < int > res = lisValues(nums);
        cout << res.size() << "\n";
        for(auto & i : res)
            cout << i << " ";
        cout << "\n\n";
    }
}