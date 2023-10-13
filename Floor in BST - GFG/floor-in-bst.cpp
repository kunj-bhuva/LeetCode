//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution {
public:
    void make(Node* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        make(root->left, ans);
        ans.push_back(root->data);
        make(root->right, ans);
    }

    int floor(Node* root, int x) {
        vector<int> ans;
        make(root, ans);

        int mini = INT_MIN; // Initialize mini to the smallest possible integer
        for (int val : ans) {
            if (val <= x) {
                mini = max(mini, val);
            } else {
                break;
            }
        }
        if(mini==INT_MIN)return -1;
        return mini;
    }
};


//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends