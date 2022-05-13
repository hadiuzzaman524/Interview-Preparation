#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *next;
} ListNode;

void insertIntoList(ListNode *head, int val)
{

    ListNode *temp= new ListNode();
    temp->val=val;
    temp->next=NULL;

    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
}

void deleteNodeFromList(ListNode *head, int val)
{
    while(head->next!=NULL)
    {

        if(head->next->val== val)
        {
            head->next= head->next->next;
        }
        head= head->next;
    }

}
void deleteNodeUsingPosition(ListNode *head, int position)
{
    int i=0;
    while(head->next!=NULL)
    {

        i++;

        if(i==position)
        {
            head->next= head->next->next;
        }

        head=head->next;
    }
}
void displayList(ListNode *head)
{

    while(head->next!=NULL)
    {
        cout<< head->next->val<< " ";
        head=head->next;
    }
}
int main()
{
    ListNode *head=  new ListNode();
    head->next= NULL;
    insertIntoList(head, 44);
    insertIntoList(head,42);
    insertIntoList(head,455) ;
    insertIntoList(head,84);
    deleteNodeUsingPosition(head, 3);
    deleteNodeFromList(head,42);
    displayList(head);


    return 0;
}
