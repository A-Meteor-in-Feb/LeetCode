#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
  
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool first_cycle = true;

        while(fast != slow || first_cycle){
            if(fast == nullptr || fast->next == nullptr){
                // cycle does not exist.
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            first_cycle = false;
        }
        
        // cycle exists.
        fast = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main(){
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    
    n4->next = n2;

    ListNode *head = n1;

    Solution sol;
    ListNode *entry = sol.detectCycle(head);

    if (entry != nullptr) {
        cout << "cycle exists: " << entry->val << endl;
    } else {
        cout << "do not has cycle" << endl;
    }

    return 0;
}

/*
* Time complexity: O(n)
* Space complexity: O(1)
*/