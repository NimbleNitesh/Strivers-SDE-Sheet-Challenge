#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    vector<int> a;
    int n=0;
    while(head!=NULL)
    {
        n++;
        a.push_back(head->data);
        head=head->next;
    }
    for(int i=0;i<(n/2);i++)
        if(a[i]!=a[n-1-i])
            return false;

    return true;
}