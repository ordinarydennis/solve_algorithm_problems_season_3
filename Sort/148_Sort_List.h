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