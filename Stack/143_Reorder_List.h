/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        stack<ListNode*> st;

        auto temp = head;

        while (temp)
        {
            st.push(temp);
            temp = temp->next;
        }

        auto it->next = head;

        int stSize = static_cast<int>(st.size());

        int loopCount = 0;

        while(it)
        {
            auto t = st.top();
            st.pop();
            auto tempNode = it->next;
            it->next = t;
            t->next = tempNode->next;

            loopCount++;

            if(stSize/2 <= loopCount)
            {
                break;
            }

            it = it->next->next;           
        }
    }
};