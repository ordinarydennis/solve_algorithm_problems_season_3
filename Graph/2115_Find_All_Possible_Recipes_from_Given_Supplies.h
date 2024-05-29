class Solution {


	bool findRecipes(vector<string>& ingredients, unordered_set<string>& ss, unordered_map<string, vector<string>>& rs, unordered_map<string, bool>& rb)
	{

		int count = 0;

		for (int i = 0; i < ingredients.size(); i++)
		{
			if (ss.count(ingredients[i]))
			{
				count++;
			}
			else
			{
				if (rs.count(ingredients[i]))
				{

					auto it = rb.find(ingredients[i]);

					if (it == rb.end())
					{
						if (findRecipes(rs[ingredients[i]], ss, rs, rb))
						{
							rb[ingredients[i]] = true;
							count++;
						}
					}
					else if(it->second)
					{
						count++;
					}
				}
			}
		}

		return count == ingredients.size();
	}

public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

		unordered_set<string> ss;
		
		for (const auto& s : supplies)
		{
			ss.insert(s);
		}

		unordered_map<string, vector<string>> rs;

		for (int i = 0; i < ingredients.size(); i++)
		{
			rs[recipes[i]] = ingredients[i];
		}

		vector<string> ret;


		unordered_map<string, bool> rb;


		for (int r = 0; r < recipes.size(); r++)
		{
			int count = 0; 

			for (int i = 0 ; i < ingredients[r].size(); i++)
			{
				if (ss.count(ingredients[r][i]))
				{
					count++;
				}
				else
				{
					if (rs.count(ingredients[r][i]))
					{
						auto it = rb.find(ingredients[r][i]);

						if (it == rb.end())
						{
							if (findRecipes(rs[ingredients[r][i]], ss, rs, rb))
							{
								rb[ingredients[r][i]] = true;
								count++;
							}
						}
						else if (it->second)
						{
							count++;
						}
					}
				}
			}

			if (count == ingredients[r].size())
			{
				ret.push_back(recipes[r]);
				
			}		
		}

		return ret;
	}
};