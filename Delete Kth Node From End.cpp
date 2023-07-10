/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int n=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    K=n-K+1;
    if(K==1)
    {
        temp=head->next;
        delete(head);
        return temp;
    }
    temp=head;
    K--;
    while(K>1)
    {
        K--;
        temp=temp->next;
    }
    Node* one_next=temp->next;
    Node* two_next=one_next->next;
    temp->next=two_next;
    delete(one_next);
    return head;
}
