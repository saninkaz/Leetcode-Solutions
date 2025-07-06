#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{

public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;

        while (temp)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        temp = head;

        while (temp)
        {
            Node *copyNode = temp->next;
            if (temp->random)
            {
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random= nullptr;
            }
            temp = temp->next->next;
        }

        Node* dn = new Node(-1);
        Node* res = dn;
        temp= head;

        while (temp)
        {
            res->next= temp->next;
            temp->next= temp->next->next;
            res = res->next;
            temp=temp->next;
        }

        return dn->next;
    }
};

// Utility function to print the list
void printList(Node *head)
{
    unordered_map<Node *, int> nodeIndex;
    Node *curr = head;
    int index = 0;

    while (curr)
    {
        nodeIndex[curr] = index++;
        curr = curr->next;
    }

    curr = head;
    cout << "[";
    while (curr)
    {
        cout << "[" << curr->val << ",";
        if (curr->random)
            cout << nodeIndex[curr->random];
        else
            cout << "null";
        cout << "]";
        if (curr->next)
            cout << ",";
        curr = curr->next;
    }
    cout << "]" << endl;
}

// Example test case setup (manually built)
int main()
{
    // Example: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution sol;
    Node *copiedHead = sol.copyRandomList(n1);

    cout << "Original: ";
    printList(n1);
    cout << "Copied: ";
    printList(copiedHead);

    return 0;
}
