#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int value)
        {
            this->data = value;
            this->next = NULL;
        }
    } *head;

public:
    SinglyLinkedList()
    {
        head = NULL;
    }
    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void push_front(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtPos(int value, int index)
    {
        if (index <= 0 || index > size() + 1)
        {
            cout << "Invalid position." << endl;
            return;
        }
        if (index == 1)
            push_front(value);
        else
        {
            index--;
            Node *temp = head;
            while (--index)
            {
                temp = temp->next;
            }
            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void insertAfter(int value, int target)
    {
        Node *temp = head;
        while (temp && temp->data != target)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << target << " is not found.\n";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertBefore(int value, int target)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Empty List.\n";
            return;
        }
        Node *newNode = new Node(value);
        if (head->data == target)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        while (temp->next && temp->next->data != target)
            temp = temp->next;
        if (temp->next == NULL)
        {
            cout << target << " is not present.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void pop_back()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->next)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            Node *del = temp->next;
            temp->next = NULL;
            delete del;
        }
    }

    void pop_front()
    {
        if (!head)
        {
            cout << "Enpty Linked Lis.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void eraseNode(int value)
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        if (head->data == value)
        {
            head = head->next;
            delete temp;
            return;
        }
        while (temp->next && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << value << " is not present.\n";
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void eraseAtPos(int idx)
    {
        if (idx < 0 || idx > size())
        {
            cout << "Position is not valid.\n";
            return;
        }
        if (idx == 1)
        {
            pop_front();
        }
        else
        {
            idx--;
            Node *temp = head;
            while (--idx)
            {
                temp = temp->next;
            }
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
    void eraseAfter(int value)
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp->next && temp->data != value)
            temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "Nothing to delete.\n";
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void eraseBefore(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == value)
        {
            cout << "Nothing to delete." << endl;
            return;
        }
        if (head->next && head->next->data == value)
        {
            Node *del = head;
            head = head->next;
            delete del;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->next && temp->next->next->data != value)
        {
            temp = temp->next;
        }
        if (temp->next->next == NULL)
        {
            cout << value << " is not found.\n";
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    bool searchNode(int value)
    {
        Node *temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        return temp != NULL;
    }
    int searchPos(int value)
    {
        if (head == NULL)
            return -1;
        Node *temp = head;
        int pos = 1;
        while (temp && temp->data != value)
        {
            ++pos;
            temp = temp->next;
        }
        return temp ? pos : -1;
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Nothing to reverse.\n";
            return;
        }
        Node *prev2 = NULL, *prev = head, *curr = head;
        while (curr)
        {
            curr = curr->next;
            prev->next = prev2;
            prev2 = prev;
            prev = curr;
        }
        head = prev2;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    int size()
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    SinglyLinkedList li;
    li.insertAtPos(500, 1);
    li.insertAtPos(12, 1);
    li.insertAtPos(50, 3);
    li.reverse();
    li.push_back(10);
    li.reverse();
    li.display();
    return 0;
}