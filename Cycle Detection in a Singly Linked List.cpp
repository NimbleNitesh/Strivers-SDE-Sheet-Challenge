#include <bits/stdc++.h>
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

bool detectCycle(Node *head)
{
	//	Write your code here
    set<int> full;
    if(head==NULL)
        return false;
    while(head!=NULL)
    {
        // cout << head->data << ' ';
        int val=head->data;
        if(full.find(val)!=full.end())
            return true;
        full.insert(val);
        head=head->next;
    }
    // cout << endl;
    return false;
}