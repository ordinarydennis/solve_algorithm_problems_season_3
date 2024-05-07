class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

		std::sort(products.begin(), products.end());

		vector<vector<string>> ret;

		for (int l = 1 ; l <= searchWord.size(); l++)
		{
			const auto& str = searchWord.substr(0, l);

			vector<string> list;

			for (const auto& pro : products)
			{
				const auto& subStr = pro.substr(0, l);

				if (str == subStr)
				{
					list.emplace_back(pro);

					if (3 <= list.size())
					{
						break;
					}
				}
			}

			if (list.size())
			{
				ret.emplace_back(std::move(list));
			}
			else
			{
				ret.emplace_back(std::move(vector<string> {}));
			}
		}

		return ret;
	}
};