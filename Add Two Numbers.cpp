/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* head=NULL;
    Node* temp;
    int carry=0;
    while(true)
    {
        if(num1==NULL&&num2==NULL)
            break;
        int cur=carry;
        if(num1!=NULL)
        {
            cur+=num1->data;
            num1=num1->next;
        }
        if(num2!=NULL)
        {
            cur+=num2->data;
            num2=num2->next;
        }
        if(cur>9)
        {
            cur-=10;
            carry=1;
        }
        else
            carry=0;
        Node* sum=new Node(cur);
        if(head==NULL)
        {
            head=sum;
            temp=sum;
        }
        else
        {
            temp->next=sum;
            temp=temp->next;
        }
    }
    if(carry)
    {
        Node* sum=new Node(carry);
        temp->next=sum;
    }
    return head;
}
