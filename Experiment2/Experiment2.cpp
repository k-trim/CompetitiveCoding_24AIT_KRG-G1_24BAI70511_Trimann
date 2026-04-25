#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int totalOnes = 0;

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        if (a[i] == 1) totalOnes++;
    }

    int maxGain = -1e9, current = 0;
    for (int i = 0; i < n; i++) 
    {
        int val = (a[i] == 0) ? 1 : -1;
        current = max(val, current + val);
        maxGain = max(maxGain, current);
    }

    if (totalOnes == n) cout << n - 1;
    else cout << totalOnes + maxGain;
    return 0;
}