//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<stack>
class Solution{
    //Function tofind the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code her
        stack<int> ans;
        vector<int> an;
        int m=a[n-1];
        ans.push(a[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(m<=a[i])
            {
                m=a[i];
                ans.push(m);
            }
        }
        
        while(!ans.empty())
        {
            an.push_back(ans.top());
            ans.pop();
        }
        return an;
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends