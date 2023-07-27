//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long sum)
    {
        vector<int> result;
        int start=0;
        long long s=0;
        if(sum==0)
        {
            result.push_back(-1);
        return result;
        }
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            while(s>sum&&start<=i)
            {
                s-=arr[start];
                start++;
            }
            if (sum == s) {
            result.push_back(start+1);
            result.push_back(i+1);
            return result;
        }
        }
        result.push_back(-1);
        return result;
        // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends