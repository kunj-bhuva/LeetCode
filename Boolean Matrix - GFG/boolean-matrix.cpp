//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    
    void makerow(vector<vector<int> > &matrix,int i)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            matrix[i][j]=1;
        }
    }
    void makecol(vector<vector<int> > &matrix,int j)
    {
        for(int i=0;i<matrix.size();i++)
        {
            matrix[i][j]=1;
        }
    }
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        set<int> row;
        set<int> col;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto i:row)
        {
            makerow(matrix,i);
        }
        for(auto j:col)
        {
            makecol(matrix,j);
        }
        // code here 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends