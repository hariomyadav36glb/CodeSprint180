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


class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int n1 = s.size();
            int n2 = part.size();
            while(s.find(part)!=string::npos)
            {
                auto x = s.find(part);
                s.erase(x,n2);
            }
            return s;
        }
    };


    

    
    // 13 feb 
    #include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertex,edges;
    cin>>vertex>>edges;
    vector<int>adjList[vertex];
    int u,v;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0;i<vertex;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
}

//  17 february


class Solution {
  public:
 
  void DFS(int node,vector<bool>&visit,vector<vector<int>>&adjls,
vector<int>&t)
  {
      visit[node]=1;
      t.push_back(node);
      
      for(int ngbr:adjls[node])
      {
          if(!visit[ngbr])
          {
              DFS(ngbr,visit,adjls,t);
          }
      }
 
      
  }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
     vector<vector<int>>ans;
      vector<int>t;
       vector<bool>visit(v,0);
       vector<vector<int>>adjls(v);
       for(auto edge :edges)
       {
           int u = edge[0];
           int v = edge[1];
           adjls[u].push_back(v);
           adjls[v].push_back(u);
       }
      for(int i=0;i<v;i++)
       {
           if(!visit[i])
           {
               vector<int>t;
               DFS(i,visit,adjls,t);
               ans.push_back(t);
           }
       }
        
         for (int i = 0; i < ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        
       return ans;
       
    }
};

// 18 feburary
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.


// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//       stack<char>st;
//       int n = num.size();
//       for(int i=0;i<n;i++)
//       {
//         while(!st.empty() && k>0 && num[i]-'0' < st.top() - '0')
//         {
//             st.pop();
//             k--;
//         }
//         st.push(num[i]);
//       } 
//       while(k-- && !st.empty())
//       {
//         st.pop();
//       } 
//       if(st.empty()) return "0";
//       string res="";
//       while(!st.empty())
//       {
//         res+=st.top();
//         st.pop();
//       }
//       while(res.size() && res.back()=='0')
//       {
//         res.pop_back();
//       }
//       reverse(res.begin(),res.end());
//       if(res.empty()) return "0";
//       return res;
//     }
// };





20 february 

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.




    
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y, char val) {
      
        for (int j = 0; j < 9; j++) {
            if (board[x][j] == val) return false;
        }
 
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == val) return false;
        }
       
        int smi = 3 * (x / 3);
        int smj = 3 * (y / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[smi + i][smj + j] == val) return false;
            }
        }
        return true;
    }

    bool fun(vector<vector<char>>& board, int i, int j) {
        // Base case: If we reach the end of the board, return true
        if (i == 9) return true;

        // Compute next cell
        int ni = (j == 8) ? i + 1 : i;
        int nj = (j == 8) ? 0 : j + 1;

        // If cell is already filled, move to next cell
        if (board[i][j] != '.') {
            return fun(board, ni, nj);
        }

        // Try placing numbers 1-9
        for (char ch = '1'; ch <= '9'; ch++) {
            if (isValid(board, i, j, ch)) {
                board[i][j] = ch; // Place number
                if (fun(board, ni, nj)) return true; // If solved, return true
                board[i][j] = '.'; // Backtrack
            }
        }
        return false; // No valid number found
    }

    void solveSudoku(vector<vector<char>>& board) {
        fun(board, 0, 0);
    }
};
