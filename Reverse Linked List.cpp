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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head==NULL)
        return head;
    LinkedListNode<int>* last=new LinkedListNode<int>(head->data);
    int ctr=1;
    while(head!=NULL)
    {
        // cout << head->data << ' ';
        if(ctr!=1)
        {
            LinkedListNode<int>* prev=new LinkedListNode<int>( head->data);
            prev->next=last;
            last=prev;
        }
        ctr++;
        head=head->next;
    }
    // cout << '\n';
    return last;
    
}