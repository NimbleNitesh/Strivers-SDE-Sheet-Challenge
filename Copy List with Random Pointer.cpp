#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *res=NULL;
    LinkedListNode<int> *ans=NULL;
    while(head!=NULL)
    {
        LinkedListNode<int> *cur=new LinkedListNode<int>(head->data);
        cur->next=head->next;
        cur->random=head->random;
        if(res==NULL){
            ans=cur;
            res=cur;
        }
        else{
            res->next=cur;
            res=res->next;
        }
        head=head->next;
    }
    return ans;
}
