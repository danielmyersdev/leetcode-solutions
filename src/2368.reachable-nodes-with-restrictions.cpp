/*
 * @lc app=leetcode id=2368 lang=cpp
 *
 * [2368] Reachable Nodes With Restrictions
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class UnionFind
{
private:
    int n;
    int *parent;
    int *sz;

    int root(int a)
    {
        if (parent[a] == a)
            return a;
        // path compression
        int rootA = root(parent[a]);
        parent[a] = rootA;
        return rootA;
    }

public:
    UnionFind(int n) : n(n), parent(new int[n]), sz(new int[n])
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    ~UnionFind()
    {
        delete[] parent;
        delete[] sz;
    }
    void unite(int a, int b)
    {
        int rootA = root(a);
        int rootB = root(b);
        // assert rootA != rootB because of tree structure
        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];
    }
    int size(int a)
    {
        return sz[root(a)];
    }
};
class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        sort(restricted.begin(), restricted.end());
        UnionFind uf(n);
        for (auto it = edges.begin(); it != edges.end(); ++it)
        {
            vector<int> &edge = *it;
            int a = edge[0];
            int b = edge[1];
            if (!binary_search(restricted.begin(), restricted.end(), a) && !binary_search(restricted.begin(), restricted.end(), b))
            {
                uf.unite(a, b);
            }
        }
        return uf.size(0);
    }
};
// @lc code=end
