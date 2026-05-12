#include <iostream>
#include <vector>

using namespace std;

// Power of 2 just below or equal to max N for binary lifting
const int MAXN = 1000005;
int bit[MAXN];
int n_size;

// Standard BIT update
void update(int i, int val) {
    for (; i <= n_size; i += i & -i) bit[i] += val;
}

// Binary Lifting on BIT to find the k-th 'alive' person in O(log N)
int find_kth(int k) {
    int idx = 0;
    // Start from the highest power of 2
    for (int i = 1 << 19; i > 0; i >>= 1) {
        if (idx + i <= n_size && bit[idx + i] < k) {
            idx += i;
            k -= bit[idx];
        }
    }
    return idx + 1;
}

int main() {
    // Fast I/O is mandatory for 10^6 elements
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    n_size = n;

    // Fill BIT: everyone starts as 1 (alive)
    for (int i = 1; i <= n; i++) update(i, 1);

    int current_pos = 1;
    for (int i = 0; i < n; i++) {
        int remaining = n - i;
        
        // Calculate index of the person to remove
        // Based on image_d36f59.png logic: (current + k)
        current_pos = (current_pos + k) % remaining;
        if (current_pos == 0) current_pos = remaining;

        // Find their actual value in the original array
        int actual_val = find_kth(current_pos);
        
        // Print and remove
        cout << actual_val << (i == n - 1 ? "" : " ");
        update(actual_val, -1);
    }

    return 0;
}