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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy, * cur = head;
		while (cur) {
			if ((cur->next) && (cur->next->val < cur->val)) {
				while ((pre->next) && (pre->next->val < cur->next->val)) {
					pre = pre->next;
				}
				ListNode* temp = pre->next;
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = temp;
				pre = dummy;
			}
			else {
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};

Input: head = [4, 2, 1, 3]
Output : [1, 2, 3, 4]