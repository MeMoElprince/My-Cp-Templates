/*
    author:  Mustafa Elsharawy
    @Date: 2023-04-18
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct DSU
{
    vector < int > par, sz;
    DSU(int start)
    {
        constexpr int N = 1e6 + 5;
        par = sz = vector < int > (N);
        for(int i = start; i < N; i++)
            par[i] = i, sz[i] = 1;
    }
    DSU(int N, int start)
    {
        N += 5;
        par = sz = vector < int > (N);
        for(int i = start; i < N; i++)
            sz[i] = 1, par[i] = i;
    }
    int findParent(int node)
    {
        if(par[node] == node)
            return node;
        else
            return par[node] = findParent(par[node]);
    }
    bool join(int a, int b)
    {
        int la = findParent(a);
        int lb = findParent(b);
        if(la == lb)    
            return 0;
        if(sz[la] < sz[lb])
            swap(la, lb);
        sz[la] += sz[lb], par[lb] = la;
        return 1;
    }
    bool sameGroup(int a, int b)
    {
        return findParent(a) == findParent(b);  
    }
    int groupSize(int node)
    {
        return sz[findParent(node)];
    }

};

int main()
{
    
}