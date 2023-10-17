//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
        // code here
        int wrong=0;
        for(int i=0;i<n;i++)
        {
            int dd;
            int num=a[i];
            int new_num=0;
            while(num!=0)
            {
                int rem=num%10;
                num/=10;
                new_num=new_num*10+rem;
            }
            if(new_num!=a[i])
            return 0;
            
        }
        return 1;
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
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends