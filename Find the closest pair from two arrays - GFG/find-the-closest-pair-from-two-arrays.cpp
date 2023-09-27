//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int diff=INT_MAX;
        int minii=0,maxx=0;
        int l=0,r=m-1;
        while(l<n&&r>=0)
        {
            if(abs(arr[l]+brr[r]-x)<diff)
            {
                minii=arr[l];
                maxx=brr[r];
                diff=abs(arr[l]+brr[r]-x);
                
            }
            
            if(arr[l]+brr[r]>x)
            r--;
            else
            l++;
            
        }
        vector<int> a;
        a.push_back(minii);
        a.push_back(maxx);
        return a;
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends