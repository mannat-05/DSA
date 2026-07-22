#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;

public:
    // Constructor
    FenwickTree(int size) 
	{
        n = size;
        tree.assign(n+1, 0); // 1-indexed
    }

    // Add value to index (point update)
    void add(int idx, int val) 
	{
        for (++idx; idx <= n; idx += idx & -idx) 
		{
            tree[idx] += val;
        }
    }

    // Prefix sum query [0..idx]
    int sum(int idx) {
        int s = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            s += tree[idx];
        }
        return s;
    }

    // Range sum query [l..r]
    int rangeSum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    FenwickTree ft(n);

    // Build tree by adding elements
    for (int i = 0; i < n; i++) {
        ft.add(i, arr[i]);
    }

    // Queries
    cout << "Prefix sum up to index 2: " << ft.sum(2) << "\n";       // 1+2+3 = 6
    cout << "Range sum [1..3]: " << ft.rangeSum(1, 3) << "\n";       // 2+3+4 = 9

    // Update: add 5 to index 2
    ft.add(2, 5); // arr[2] becomes 8

    cout << "Prefix sum up to index 2 after update: " << ft.sum(2) << "\n"; // 1+2+8 = 11
    cout << "Range sum [2..4]: " << ft.rangeSum(2, 4) << "\n";              // 8+4+5 = 17
}
