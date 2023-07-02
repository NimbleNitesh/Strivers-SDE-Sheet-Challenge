int solver(int* arr, int l, int r, int key)
{
    int res=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[mid]<key)
            l=mid+1;
        else
            r=mid-1;
    }
    return res;
}
int search(int* arr, int n, int key) {
    // Write your code here.
    int pivot=0;
    //index of smallest element
    int l=0, r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mid>l)
        {
            if(arr[mid-1]>arr[mid])
            {
                pivot=mid;
                break;
            }
        }
        if(mid<r)
        {
            if(arr[mid]>arr[mid+1])
            {
                pivot=mid+1;
                break;
            }
        }
        if(arr[mid]<=arr[l])
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    // return pivot;
    //0 to pivot-1
    //pivot to n-1
    int v1=pivot>0?solver(arr, 0, pivot-1, key):-1;
    if(v1!=-1)
        return v1;
    int v2=solver(arr, pivot, n-1, key);
    return v2;
    
}