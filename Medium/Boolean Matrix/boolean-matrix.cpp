//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        int R = matrix.size();
        int C = matrix[0].size();
        bool *row = new bool[R];
        bool *col = new bool[C];
        
        for(int i=0; i<R; i++){
            row[i] = 0;
        }
        for(int i=0; i<C; i++){
            col[i] = 0;
        }
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(matrix[i][j] == 1){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i=0; i<R; i++){
            if(row[i]){
                for(int j=0; j<C; j++){
                    matrix[i][j] = 1;
                }
            }
        }
        
        for(int i=0; i<C; i++){
            if(col[i]){
                for(int j=0; j<R; j++){
                    matrix[j][i] = 1;
                }
            }
        }
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