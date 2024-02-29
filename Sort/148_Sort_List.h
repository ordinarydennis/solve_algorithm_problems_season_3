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
	ListNode* sortList(ListNode* head) {

		auto target = head;
		auto it = head;


		int min = INT_MAX;
		ListNode* minNode = INT_MAX;
		while ()
		{
			while (it && it->val < minNode->val)
			{
				minNode = it;
			}
		}
	}
};


class Solution {
public:
	ListNode* sortList(ListNode* head, ListNode* tail = nullptr)
	{
		if (head != tail) {
			ListNode* smaller;
			ListNode** smaller_next = &smaller;
			for (ListNode** prev = &head->next; *prev != tail; ) {
				if (head->val > (**prev).val) {
					*smaller_next = *prev;
					smaller_next = &((**smaller_next).next);
					*prev = (**prev).next;
				}
				else {
					prev = &((**prev).next);
				}
			}

			*smaller_next = head;
			head->next = sortList(head->next, tail);
			head = sortList(smaller, head);
		}
		return head;
	}
};

//https://leetcode.com/problems/sort-list/solutions/166324/python-c-c-java-legit-iterative-solutions-o-1-space-no-recursion-with-detailed-explaination/
