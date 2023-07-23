bool isValid(int i, int j, int ele, int matrix[9][9])
{
    if(i<0||i>=9)
        return false;
    if(j<0||j>=9)
        return false;
    for(int x=0;x<9;x++)
        if(matrix[x][j]==ele)
            return false;
    for(int x=0;x<9;x++)
        if(matrix[i][x]==ele)
            return false;
    i=(i/3)*3;
    j=(j/3)*3;
    for(int x=i;x<i+3;x++)
    {
        for(int y=j;y<j+3;y++)
            if(matrix[x][y]==ele)
                return false;
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    int ctr=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(matrix[i][j]==0)
                ctr++;
    if(ctr==0)
        return true;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matrix[i][j]==0)
            {
                bool ch=0;
                for(int k=1;k<=9;k++)
                {
                    if(isValid(i, j, k, matrix))
                    {
                        matrix[i][j]=k;
                        bool res=isItSudoku(matrix);
                        if(res)
                            return res;
                        ch|=res;
                        matrix[i][j]=0;
                    }
                }
                if(!ch)
                    return false;
            }
        }
    }
    return false;
}
