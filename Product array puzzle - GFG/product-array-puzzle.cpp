//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) 
    {
        long long nonzero=1;
        int zero=0;
       long long int sum=1;
       for(int i=0;i<n;i++)
       {
           if(nums[i]==0)zero++;
           else nonzero*=nums[i];
           sum*=nums[i];
           
       }
       vector<long long int> Q(n,0);
       if(zero>1)
            return Q;
       vector<long long int> P(n);
       if(zero==0)
       {
            for(int i=0;i<n;i++)
            {
                
                 P[i]=sum/nums[i];
                
                
            }
           
       }
       if(zero==1)
       {
           for(int i=0;i<n;i++)
            {
                if(nums[i]!=0)
                    P[i]=0;
                else 
                    P[i]=nonzero;
                
            }
       }
       return P;
        //code here        
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends