#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    vector<vector<int>> temp=mat;
    int up=0, down=n-1, left=0, right=m-1;
    while((up<down)&&(left<right))
    {
        for(int i=left+1;i<right+1;i++)
            mat[up][i]=temp[up][i-1];
        for(int i=right;i>left;i--)
        {
            // cout << down << ' ' << (i-1) << endl;
            mat[down][i-1]=temp[down][i];
        }
        for(int i=up+1;i<down+1;i++){
            // cout << i << ' ' << right << endl;
            mat[i][right]=temp[i-1][right];
        }
        for(int i=down;i>up;i--){
            mat[i-1][left]=temp[i][left];
            // cout << i << ' ' << left << ' ' << temp[i][left] << endl;
        }
        up++;
        down--;
        left++;
        right--;
    }
    // cout << "hello\n";
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cout << mat[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << endl;

}