//   Merge Sort

#include <bits/stdc++.h>
using namespace std;

vector<int> sort_it(vector<int> left, vector<int> right) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            ans.push_back(left[i]);
            i++;
        } else {
            ans.push_back(right[j]);  // Fixed right[i] -> right[j]
            j++;  // Fixed missing increment
        }
    }

    while (i < left.size()) {
        ans.push_back(left[i]);
        i++;  // Fixed missing increment
    }
    
    while (j < right.size()) {
        ans.push_back(right[j]);
        j++;  // Fixed missing increment
    }
    
    return ans;
}

vector<int> merge(vector<int> arr, int lo, int hi) {
    if (lo >= hi) {
        return {arr[lo]};  // Fixed incorrect vector initialization
    }

    int mid = (lo + hi) / 2;
    vector<int> left = merge(arr, lo, mid);
    vector<int> right = merge(arr, mid + 1, hi);
    
    return sort_it(left, right);
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> ans = merge(arr, 0, n - 1);
    cout<<"Sorted elements :";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
// Merge Sort of a linked list

class Solution {
    public:
      // Merging two sorted linked lists
      Node* merge(Node* head1, Node* head2) {
          if (!head1) return head2;
          if (!head2) return head1;
          
          Node* dummy = new Node(-1);
          Node* curr = dummy;
          
          while (head1 && head2) {
              if (head1->data < head2->data) {
                  curr->next = head1;
                  head1 = head1->next;
              } else {
                  curr->next = head2;
                  head2 = head2->next;
              }
              curr = curr->next;
          }
          
          if (head1) curr->next = head1;
          if (head2) curr->next = head2;
  
          return dummy->next;
      }
      
      // Function to find the middle and split the list
      Node* getMid(Node* head) {
          Node* slow = head;
          Node* fast = head;
          Node* prev = NULL;
          while (fast && fast->next) {
              prev = slow;
              slow = slow->next;
              fast = fast->next->next;
          }
          if (prev) prev->next = NULL; // Split the list
          return slow;
      }
      
      // Merge Sort function
      Node* mergeSort(Node* head) {
          if (!head || !head->next) return head;
  
          Node* mid = getMid(head);
          Node* left = mergeSort(head);
          Node* right = mergeSort(mid);
  
          return merge(left, right);
      }
  };

//   12 February

2487. Remove Nodes From Linked List

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.





/**
 * Definition for singly-linked list.
 */

 class Solution {
    public:
        ListNode* reverse(ListNode* head) {
            ListNode* prev = nullptr;
            while (head) {
                ListNode* nextNode = head->next;
                head->next = prev;
                prev = head;
                head = nextNode;
            }
            return prev;
        }
    
        ListNode* removeNodes(ListNode* head) {
            if (!head) return nullptr;
    
            // Step 1: Reverse the linked list
            ListNode* newHead = reverse(head);
            ListNode* temp = newHead;
            
            // Step 2: Use a stack to maintain decreasing order
            stack<ListNode*> st;
            ListNode* newList = temp;
            st.push(temp);
            temp = temp->next;
    
            while (temp) {
                if (temp->val >= st.top()->val) { // Keep only nodes with max values seen so far
                    st.top()->next = temp;
                    st.push(temp);
                }
                temp = temp->next;
            }
    
            st.top()->next = nullptr; // Terminate the new linked list
            
            // Step 3: Reverse back to original order
            return reverse(newList);
        }
    }


    //  problem of the day
    

1910. Remove All Occurrences of a Substring
