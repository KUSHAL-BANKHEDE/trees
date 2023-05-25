#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, ec;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> ec;
    
    // Binary search for the minimum time
    int left = 1, right = 1e9;
    while (left < right) {
        int mid = (left + right) / 2;
        
        // Check if it's possible to divide the v among the editors in mid time
        int eneed = 1;
        int timeU = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] > mid) {  // A single reel is longer than mid, so it's impossible
                eneed = ec + 1;
                break;
            }
            if (timeU + v[i] > mid) {  // Need a new editor
                eneed++;
                timeU = v[i];
            } else {
                timeU += v[i];
            }
        }
        
        if (eneed <= ec) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    return 0;
}
