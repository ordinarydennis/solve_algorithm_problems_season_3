class Solution {
public:

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

		sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {

			return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
			
			}
		);

		vector<vector<int>> ans;                  
		
		for (auto man : people)
			ans.insert(ans.begin() + man[1], man);  
	
		return ans;
	}
};


class Solution {
public:
	static bool comp(vector<int>& a, vector<int>& b) { //Comparator function for the logic of sort
		if (a[0] == b[0]) return a[1] < b[1];
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), comp);  //Sorting the array according to comp function.
		vector<vector<int>> ans;                   //to store the final array to be returned
		for (auto man : people) {
			ans.insert(ans.begin() + man[1], man);   //Inserting the element at desired position.
		}
		return ans;
	}
};

//https://leetcode.com/problems/queue-reconstruction-by-height/solutions/2211643/c-easy-solution-full-explanation/

People = [[7, 0], [4, 4], [7, 2], [5, 0], [6, 1], [5, 4], [8, 0]]
Sorted People accordin to comp function : [[8, 0], [7, 0], [7, 2], [6, 1], [5, 0], [5, 4], [4, 4]] ]

Now for each iteration in the loop; (Ki of each man is included in ' ', and each inserted man in " ")

man = [8, '0']->ans.insert(ans.begin() + '0', man)->ans = ["[8,0]"]
man = [7, '0']->ans.insert(ans.begin() + '0', man)->ans = ["[7,0]", [8, 0]]
man = [7, '2']->ans.insert(ans.begin() + '2', man)->ans = [[7, 0], [8, 0], "[7,2]"]
man = [6, '1']->ans.insert(ans.begin() + '1', man)->ans = [[7, 0], "[6,1]", [8, 0], [7, 2]]
man = [5, '0']->ans.insert(ans.begin() + '0', man)->ans = ["[5,0]", [7, 0], [6, 1], [8, 0], [7, 2]]
man = [5, '4']->ans.insert(ans.begin() + '4', man)->ans = [[5, 0], [7, 0], [6, 1], [8, 0], "[5,4]", [7, 2]]
man = [4, '4']->ans.insert(ans.begin() + '4', man)->ans = [[5, 0], [7, 0], [6, 1], [8, 0], "[4,4]", [5, 4], [7, 2]]

See the final ans array fullfills all the conditions.

// # the reason big number is placed in front of array is to process it first.
// Why are big numbers processed first?


