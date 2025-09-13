/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeTwolsts(Node* l1, Node* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->data < l2->data) {
            l1->next = mergeTwolsts(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwolsts(l1, l2->next);
            return l2;
        }
    }
    Node* mergeKlsts(vector<Node*> arr, int i, int n) {
        if(i > n) return nullptr;
        if(i == n) return arr[i];
        int mid = (i + n) / 2;
        Node* l1 = mergeKlsts(arr, i, mid);
        Node* l2 = mergeKlsts(arr, mid + 1, n);
        return mergeTwolsts(l1, l2);
    } 
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if(arr.empty()) return nullptr;
        return mergeKlsts(arr, 0, arr.size() - 1);
    }
};