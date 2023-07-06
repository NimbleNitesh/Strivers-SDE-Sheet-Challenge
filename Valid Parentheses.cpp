bool isValidParenthesis(string expression)
{
    // Write your code here.
    int arr[3];
    arr[0]=arr[1]=arr[2]=0;
    int n=expression.size();
    for(int i=0;i<n;i++)
    {
        if(expression[i]=='('||expression[i]==')')
            arr[0]+=(expression[i]=='('?1:-1);
        if(expression[i]=='{'||expression[i]=='}')
            arr[1]+=(expression[i]=='{'?1:-1);
        if(expression[i]=='['||expression[i]==']')
            arr[2]+=(expression[i]=='['?1:-1);
        for(int j=0;j<3;j++)
            if(arr[j]<0)
                return false;
    }
    for(int j=0;j<3;j++)
        if(arr[j]!=0)
            return false;
    return true;
}