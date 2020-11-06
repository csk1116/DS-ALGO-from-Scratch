/*
date: 2020-11-06
author: csk
singly linked list implementation (insert & delete)
inspired by codememtorr team:
https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
*/

#include <iostream>

using namespace std;

struct node
{
    /* data */
    int data;
    node *next;
};

// linked list node
class list
{
private:
    node *head;
    node *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    void printList()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    //new node at the end
    void add_node(int val)
    {
        node *temp = new node();
        temp->data = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    //pop node at the end
    void pop_node()
    {
        node *previous;
        node *current = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        tail = previous;
        delete current;
    }

    //insert node at any position
    void insert_node(int pos, int val)
    {
        node *temp = new node();
        node *previous;
        node *current;
        temp->data = val;

        if (pos == 1)
        {
            //at the beginning pos =1
            temp->next = head;
            head = temp;
            return;
        }

        //at the nth position
        current = head;
        for (int i = 1; i < pos; i++)
        {
            if (current->next == NULL) // = add_node
            {
                add_node(val);
                return;
            }
            previous = current;
            current = current->next;
        }
        previous->next = temp;
        temp->next = current;
    }

    //delete node at any position
    void delete_node(int pos)
    {
        node *temp;
        node *previous;
        node *current;
        //at the beginning
        if (pos == 1)
        {
            temp = head;
            head = temp->next;
            delete temp;
            return;
        }

        //at the nth position
        current = head;
        for (int i = 1; i < pos; i++)
        {
            if (current->next == NULL)
            {
                pop_node();
                return;
            }
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
};

int main()
{
    list myList;

    //add node
    int num;
    int val;
    cout << "how many number?" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "enter: " << endl;
        cin >> val;
        myList.add_node(val);

        //display node
        myList.printList();
    }

    // insert node
    int i_pos;
    int i_val;
    int i_num;
    cout << "insert how many number?" << endl;
    cin >> i_num;

    for (int i = 0; i < i_num; i++)
    {
        cout << "pos?" << endl;
        cin >> i_pos;
        cout << "enter value:" << endl;
        cin >> i_val;
        myList.insert_node(i_pos, i_val);

        //display node
        myList.printList();
    }

    //delete node
    int d_pos;
    int d_num;
    cout << "delete how many number?" << endl;
    cin >> d_num;

    for (int i = 0; i < d_num; i++)
    {
        cout << "pos?" << endl;
        cin >> d_pos;
        myList.delete_node(d_pos);

        //display node
        myList.printList();
    }

    return 0;
}