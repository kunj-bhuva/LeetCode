//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
public:
    // Function to find the trapped water between the blocks.
    long long trappingWater(int arr[], int n) {
        // If there are fewer than 3 blocks, trapped water is 0.
        if (n < 3)
            return 0;

        long long vol = 0;
        stack<int> stack;

        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && arr[i] > arr[stack.top()]) {
                int topBlock = stack.top();
                stack.pop();
                if (stack.empty())
                    break;
                int distance = i - stack.top() - 1;
                int boundedHeight =min(arr[i], arr[stack.top()]) - arr[topBlock];
                vol += static_cast<long long>(distance) * boundedHeight;
            }
            stack.push(i);
        }

        return vol;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends