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
	ListNode* insertionSortList(ListNode* head) {

		ListNode* target = nullptr;

		target = head;

		while (1)
		{
			ListNode* preIt = target;
			ListNode* it = preIt->next;

			while (1)
			{
				if (it->val < target->val)
				{
					//swap;
					ListNode* temp = target;
					target->next = preIt->next->next;
					preIt->next = target;
					it = temp;
					break;
				}
				preIt = it;
				it = it->next;
			}
		}
	}
};