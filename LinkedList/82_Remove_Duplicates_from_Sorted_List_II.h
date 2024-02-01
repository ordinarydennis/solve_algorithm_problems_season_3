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

	ListNode* deleteDuplicates(ListNode* head) {

		ListNode dummy(0, head);

		ListNode* previous = &dummy, * current = head;

		while (current) {
			ListNode* next_node = current->next;
			while (next_node && current->val == next_node->val) {
				ListNode* temp = next_node->next;
				delete next_node;
				next_node = temp;
			}

			if (current->next == next_node) {
				previous = current;
			}
			else {
				previous->next = next_node;
				delete current;
			}
			current = next_node;
		}

		return dummy.next;
	}
};
//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solutions/1395724/8-lines-c-solution-faster-than-100-submissions-for-beginners-explanation-of-approach/
class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head)
			return head;

		ListNode* prev = NULL, * curr = head, * next = curr->next;
		while (next)
		{
			if (curr->val == next->val)
			{
				while (next && next->val == curr->val)
					next = next->next;
				if (!prev) // This condition means element at the head is repeating. So, head pointer needs to be shifted.
					head = next;
				else
					prev->next = next;
			}
			else
			{
				prev = curr;
			}

			curr = next;
			if (next)
				next = curr->next;
		}
		return head;
	}
};
//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solutions/816387/simple-3-pointer-solution-8ms-c/