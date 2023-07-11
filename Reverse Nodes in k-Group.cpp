#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head==NULL)
		return head;
	Node* last=NULL;
	Node* res=head;
	Node* last_first=NULL;
	Node* first;
	for(int i=0;i<n;i++)
	{
		last=NULL;
		first=NULL;
		if(b[i]>0){
		while(b[i]>0)
		{
			Node* cur=head;
			if(cur==NULL){
				// cout << "exe\n";
				break;
			}
			if(first==NULL)
				first=cur;
			Node* cur_next=cur->next;
			cur->next=last;
			last=cur;
			cur=cur_next;
			head=cur;
			b[i]--;
		}
		if(first==NULL)
			break;
		// Node* temp=last;
		// while(temp!=NULL)
		// {
		// 	cout << temp->data << ' ';
		// 	temp=temp->next;
		// }
		// cout << endl;
		if(last_first!=NULL){
			last_first->next=last;
			// cout << "i=" << i << " linking " << last_first->data << " to " << last->data << endl;
		}
		else{
			res=last;
			// cout << "exe\n";
		}
		last_first=first;
		}
	}
	// return res;
	// Node* temp=head;
	if(head!=NULL&&last_first!=NULL)
	{
		// cout << temp->data << ' ';
		last_first->next=head;
		// temp=temp->next;
	}
	// cout << endl;
	return res;
}