/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include <bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int n1=0, n2=0;
    Node* temp1=firstHead;
    Node* temp2=secondHead;
    while(temp1!=NULL)
    {
        n1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        n2++;
        temp2=temp2->next;
    }
    // cout << n1 << ' ' << n2 << endl;
    while(n1>n2)
    {
        n1--;
        firstHead=firstHead->next;
    }
    while(n1<n2)
    {
        n2--;
        secondHead=secondHead->next;
    }
    // cout << n1 << ' ' << n2 << endl;
    while(true)
    {
        if(firstHead==NULL){
            // cout << "called\n";
            break;
        }
        // cout << (firstHead->data) << ' ' << (secondHead->data) << '\n';
        if((firstHead)==(secondHead))
        {
            // cout << "nine\n";
            break;
        }
        firstHead=firstHead->next;
        secondHead=secondHead->next;
    }
    // cout << firstHead->data << endl;
    return firstHead;
}
