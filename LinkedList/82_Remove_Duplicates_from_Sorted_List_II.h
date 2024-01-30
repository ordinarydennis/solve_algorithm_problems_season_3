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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* ret = head;

        ListNode* temp = head;
        ListNode* h = nullptr;

        while (temp)
        {            
            if(nullptr == temp->next)
            {
                break;
            }

            if (temp && temp->next)
            {
                if (temp->val != temp->next->val)
                {
                    h = temp;
                    temp = temp->next;
                    
                    continue;
                }
            }
            
            while(temp)
            {
                if(nullptr == temp->next)
                {
                    h->next = nullptr;
                    break;
                }

                if(temp->val == temp->next->val)
                {
                    temp = temp->next;
                }
                else
                {
                    if(nullptr == h)
                    {
                        h = temp->next;
                    }
                    else
                    {
                        h->next = temp->next;
                        h = temp;
                        temp = temp->next;
                    }                    
                }
            }
        }
        
        return ret;
    }
};