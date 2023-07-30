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
#include <map>
#include <algorithm>
Node *firstNode(Node *head)
{
    //    Write your code here.
    map<int, int> vis;
    while(head!=NULL)
    {
        if(vis.find(head->data)!=vis.end())
            return head;
        vis[head->data]=1;
        head=head->next;
    }
    return NULL;
}