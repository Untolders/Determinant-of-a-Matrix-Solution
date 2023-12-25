********************************************************************************************************************  Question  ****************************************************************************************************
Given a square matrix of size n*n. The task is to find the determinant of this matrix.

Example 1:

Input:
n = 4
matrix[][] = {{1, 0, 2, -1},
              {3, 0, 0, 5},
              {2, 1, 4, -3},
              {1, 0, 5, 0}}
Output: 30
Explanation:
Determinant of the given matrix is 30.
Example 2:

Input:
n = 3
matrix[][] = {{1, 2, 3},
              {4, 5, 6},
              {7, 10, 9}}
Output: 12
Explanation:
Determinant of the given matrix is 12.
Your Task:
You don't need to read input or print anything. Complete the function determinantOfMatrix() that takes matrix and its size n as input parameters and returns the determinant of the matrix.

Expected Time Complexity: O(N4)
Expected Auxiliary Space: O(N2)

Constraints:
1 <= N <= 10
-10 <= mat[i][j] <= 10



********************************************************************************************************************  Solution  ****************************************************************************************************
  //{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > mat, int n)
    {
          if(n == 1) return mat[0][0];
        
        int res = 0;
        for(int i=0; i<n; i++){
            vector<vector<int>>v(n-1, vector<int>(n-1));
            
            for(int j=1; j<n; j++){ 
                int curr = 0;
                for(int k=0; k<n; k++){
                    if(k == i) continue;
                    v[j-1][curr] = mat[j][k];
                    curr++;
                }
            }

            if(i%2 == 0) res += mat[0][i] * determinantOfMatrix(v, n-1);
            else res -= mat[0][i] * determinantOfMatrix(v, n-1);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends
