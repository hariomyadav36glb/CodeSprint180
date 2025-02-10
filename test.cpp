//   Merge Sort

#include <bits/stdc++.h>
using namespace std;

vector<int> sort_it(vector<int> left, vector<int> right) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            ans.push_back(left[i]);
            i++;
        } else {
            ans.push_back(right[j]);  // Fixed right[i] -> right[j]
            j++;  // Fixed missing increment
        }
    }

    while (i < left.size()) {
        ans.push_back(left[i]);
        i++;  // Fixed missing increment
    }
    
    while (j < right.size()) {
        ans.push_back(right[j]);
        j++;  // Fixed missing increment
    }
    
    return ans;
}

vector<int> merge(vector<int> arr, int lo, int hi) {
    if (lo >= hi) {
        return {arr[lo]};  // Fixed incorrect vector initialization
    }

    int mid = (lo + hi) / 2;
    vector<int> left = merge(arr, lo, mid);
    vector<int> right = merge(arr, mid + 1, hi);
    
    return sort_it(left, right);
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> ans = merge(arr, 0, n - 1);
    cout<<"Sorted elements :";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
