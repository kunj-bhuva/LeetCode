//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    // Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        // Reverse the first linked list
        struct Node* current = first;
        struct Node* prev = NULL;
        struct Node* nex = NULL;

        while (current != NULL) {
            nex = current->next;  // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current;       // Move prev to the current node
            current = nex;        // Move current to the next node
        }
        struct Node* h1 = prev;

        // Reverse the second linked list
        current = second;
        prev = NULL;
        nex = NULL;

        while (current != NULL) {
            nex = current->next;  // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current;       // Move prev to the current node
            current = nex;        // Move current to the next node
        }
        struct Node* h2 = prev;

        struct Node* f = NULL; // Initialize the result linked list as empty
        int c = 0;

        while (h1 != NULL && h2 != NULL) {
            int d = c + h1->data + h2->data;
            c = 0;
            if (d >= 10) {
                c = 1;
                d -= 10;
            }

            struct Node* temp = new Node(d); // Allocate memory for the new node

            if (f == NULL) {
                f = temp;
            } else {
                temp->next = f;
                f = temp;
            }

            h1 = h1->next;
            h2 = h2->next;
        }

        // Process any remaining nodes in the first or second linked list
        while (h1 != NULL) {
            int d = c + h1->data;
            c = 0;
            if (d >= 10) {
                c = 1;
                d -= 10;
            }

            struct Node* temp = new Node(d);

            if (f == NULL) {
                f = temp;
            } else {
                temp->next = f;
                f = temp;
            }

            h1 = h1->next;
        }

        while (h2 != NULL) {
            int d = c + h2->data;
            c = 0;
            if (d >= 10) {
                c = 1;
                d -= 10;
            }

            struct Node* temp = new Node(d);

            if (f == NULL) {
                f = temp;
            } else {
                temp->next = f;
                f = temp;
            }

            h2 = h2->next;
        }

        // If there's a carry left
        if (c > 0) {
            struct Node* temp = new Node(c);
            temp->next = f;
            f = temp;
        }

        return f; // Return the result linked list
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends