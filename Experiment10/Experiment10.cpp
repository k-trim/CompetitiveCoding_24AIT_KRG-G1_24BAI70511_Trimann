#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int k = 0;
        while (k < n && a[k] == 1) k++;
        
        if (k == n) 
        {
            if (n % 2 == 1) cout << "First\n";
            else cout << "Second\n";
        } 
        else 
        {
            if (k % 2 == 0) cout << "First\n";
            else cout << "Second\n";
        }
    }

    return 0;
}