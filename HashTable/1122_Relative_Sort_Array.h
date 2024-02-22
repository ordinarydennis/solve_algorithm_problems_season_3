class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

		int index = 0;

		for (int t = 0; t < static_cast<int>(arr2.size()); t++)
		{
			for (int i = index; i < static_cast<int>(arr1.size()); i++)
			{
				if (arr1[i] == arr2[t])
				{
					int temp = arr1[i];
					arr1[i] = arr1[index];
					arr1[index] = temp;
					index++;
				}
			}
		}

		std::sort(arr1.begin() + index, arr1.end());

		return arr1;

	}
};
