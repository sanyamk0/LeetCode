//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
      Node* list1 = nullptr, *list2 = nullptr, *tail1 = nullptr, *tail2 = nullptr, *current = head;
        bool addToList1 = true;
        while (current != nullptr) {
            Node* nextNode = current->next;
            if (addToList1) {
                if (list1 == nullptr) {
                    list1 = current;
                    tail1 = current;
                } else {
                    tail1->next = current;
                    tail1 = tail1->next;
                }
            } else {
                if (list2 == nullptr) {
                    list2 = current;
                    tail2 = current;
                } else {
                    tail2->next = current;
                    tail2 = tail2->next;
                }
            }
            current->next = nullptr;
            current = nextNode;
            addToList1 = !addToList1;
        }
        return {list1, list2};   
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends