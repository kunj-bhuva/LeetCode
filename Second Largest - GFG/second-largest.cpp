//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    set<int> uniqueValues;
    
    // Insert all unique values from the array into the set
    for (int i = 0; i < n; i++) {
        uniqueValues.insert(arr[i]);
    }
    
    if (uniqueValues.size() < 2) {
        // cout << "The array does not have a second maximum value.\n";
        return -1; // Or any appropriate value to indicate no second maximum
    }

    set<int>::iterator it = uniqueValues.end();
    it--; // Move to the last element
    it--; // Move to the second-last element

    return *it;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends