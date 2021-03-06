#include <bits/stdc++.h>
using namespace std;
// There are two ways :
// Either create a LinkedList class (Object ornexted Approach)
// or do separately in functions (Procedure oriented Approach)

// We'll prefer the latter one since its the one asked in interviews.
class node
{
public:
    int data;
    node *link;
    node(int d) // constructor to initialise the values
    {
        data = d;
        link = NULL;
    }
};
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->link;
    }
}
int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->link;
    }
    return count;
}

void insertAtHead(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    { //we will always check the base case
        head = n;
        return;
    }
    n->link = head;
    head = n;
}

void insertAtTail(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *current = head;
    while (current->link != NULL)
        current = current->link;
    current->link = n;
}
void insertInMiddle(node *&head, int d, int p) //insert at pos
{
    node *n = new node(d);
    if (p == 0 or p == 1)
    {
        insertAtHead(head, d);
        return;
    }
    else if (p > length(head))
    {
        insertAtTail(head, d);
        return;
    }
    else
    {
        node *current = head;
        int jump = 1;
        while (jump < p - 1)
        {
            current = current->link;
            jump++;
        }
        n->link = current->link;
        current->link = n;
    }
}
void deleteAthead(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head->link;
    delete head;
    head = temp;
}
void deleteAttail(node *&head)
{
    if (head == NULL)
        return;
    else if (head->link == NULL)
        deleteAthead(head);
    else
    {
        node *p = head;
        while (p->link->link != NULL)
            p = p->link;
        node *target = p->link;
        delete target;
        p->link = NULL;
    }
}
void deleteAtmiddle(node *&head, int p)
{
    if (p == 1 or p == 0) //
        deleteAthead(head);
    else if (p == length(head))
        deleteAttail(head);
    else
    {
        int jump = 1;
        node *current = head;
        while (jump < p - 1)
        {
            current = current->link;
            jump++;
        }
        node *target = current->link;
        current->link = current->link->link;
        delete target;
    }
}
void take_input(node*&head)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    
}
//------------OPERATOR-OVERLOADING---------------------------------------------------------------------------------
/* To overload the cout<<head -We will have to pass both the cout object which is a part of ostream class and head object which is of the type Node * 
similarly with cin>>head
*/

// CIN >> OPERATOR OVERLOADED 
istream &operator>>(istream &is, node*&head) /* take a node that we return the cin object else it returns void and we wont 
                                             able to take cin>>head2>>head2. THIS IS Known as Cascading of operators*/
{ // (is) is cin basically just given another name
    take_input(head);
    return is;
}

//COUT <<OPERATOR OVERLOADED 
ostream &operator<<(ostream &os, node *head) /*we return the cout object to be able to use cout<<head1<<head 2 */
{ //NOTE os is cout only just given another name to it 
    print(head);
    return os;
}
//---------------END OF OPERATOR OVERLOADING FUNCTIONS-------------------------------------------------------------
int main()
{
    node *head = NULL;

    
    /*head = take_input();*/

    cin >> head; // cin operator overloaded 

    //cout operator overloaded 
    cout << head << endl; 

    insertInMiddle(head, 4, 3); //insert at position 3
    insertAtTail(head, 7);

//cout operator overloaded 
    cout << head << endl;

    deleteAthead(head);
    deleteAttail(head);

//cout opeartor overloaded
    cout << head << endl;

    deleteAtmiddle(head, 3); //deletes from position 3
    
    // cout operator overloaded
    cout << head << endl;
}
