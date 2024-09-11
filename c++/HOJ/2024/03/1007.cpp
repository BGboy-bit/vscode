#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> q;

    while (q--) {
        int type, l, r, x;
        cin >> type >> l >> r;
        l--; r--; // Convert to zero-based index

        if (type == 1) {
            cin >> x;
            for (int i = l; i <= r; ++i) {
                a[i] += x;
            }
        } else if (type == 2) {
            bool allEqual = true;
            for (int i = l + 1; i <= r; ++i) {
                if (a[i] != a[l]) {
                    allEqual = false;
                    break;
                }
            }
            cout << (allEqual ? 1 : 0) << "\n";
        } else if (type == 3) {
            bool strictlyIncreasing = true;
            for (int i = l + 1; i <= r; ++i) {
                if (a[i] <= a[i - 1]) {
                    strictlyIncreasing = false;
                    break;
                }
            }
            cout << (strictlyIncreasing ? 1 : 0) << "\n";
        } else if (type == 4) {
            bool strictlyDecreasing = true;
            for (int i = l + 1; i <= r; ++i) {
                if (a[i] >= a[i - 1]) {
                    strictlyDecreasing = false;
                    break;
                }
            }
            cout << (strictlyDecreasing ? 1 : 0) << "\n";
        } else if (type == 5) {
            bool found_peak = false;
            int i = l;
            // First, find strictly increasing sequence
            while (i < r && a[i] < a[i + 1]) {
                i++;
            }
            // If no increase or already at the end, no peak
            if (i == l || i == r) {
                cout << 0 << "\n";
                continue;
            }
            // Now, the sequence must be strictly decreasing
            found_peak = true;
            while (i < r) {
                if (a[i] <= a[i + 1]) {
                    found_peak = false;
                    break;
                }
                i++;
            }
            cout << (found_peak ? 1 : 0) << "\n";
        }
    }

    return 0;
}
