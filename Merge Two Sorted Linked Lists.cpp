#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
    Node<int>* head;
    Node<int>* cur;
    bool ch=1;
    while(true)
    {
        if(first==NULL&&second==NULL)
            break;
        int l1=first==NULL?1e9:first->data;
        int l2=second==NULL?1e9:second->data;
        // cout << "l1=" << l1 << " l2=" << l2 << endl;
        if(l1<l2)
        {
            Node<int>* temp=new Node<int>(l1);
            if(ch)
            {
                head=temp;
                cur=temp;
            }
            else
            {
                cur->next=temp;
                cur=cur->next;
            }
            first=first->next;
            ch=0;
        }
        else
        {
            Node<int>* temp=new Node<int>(l2);
            if(ch)
            {
                head=temp;
                cur=temp;
            }
            else
            {
                cur->next=temp;
                cur=cur->next;
            }
            second=second->next;
            ch=0;
        }
    }
    return head;
}
