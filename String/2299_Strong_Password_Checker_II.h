class Solution {
public:
	bool strongPasswordCheckerII(string password) {

		if (password.size() < 8) return false;

		bool isLower = false, isUpper = false, isDigit = false, isSpecial = false;

		for (int i = 0; i < password.size(); i++)
		{
			if (0 < i && password[i] == password[i - 1]) return false;
			else if (islower(password[i])) isLower = true;
			else if (isupper(password[i])) isUpper = true;
			else if (isdigit(password[i])) isDigit = true;
			else isSpecial = true;
		}

		return isLower && isUpper && isDigit && isSpecial;
	}
};


class Solution {
public:
	bool strongPasswordCheckerII(string password) {

		if (password.size() < 8)
			return false;

		bool checkLc = false;
		bool checkUc = false;
		bool checkSc = false;
		bool checkDc = false;

		string scstr = "!@#$%^&*()-+";

		char preC = ' ';
		for (int i =0; i < password.size(); i++)
		{
			char cc = password[i];

			if (preC == cc)
			{
				return false;
			}

			if (!checkLc && 'a' <= cc && cc <= 'z')
			{
				checkLc = true;
			}
			else if (!checkUc  && 'A' <= cc && cc <= 'Z')
			{
				checkUc = true;
			}
			else if (!checkDc && '0' <= cc && cc <= '9')
			{
				checkDc = true;
			}
			else if(!checkSc && scstr.find(cc) != string::npos)
			{
				checkSc = true;
			}

			preC = cc;
		}

		return checkLc && checkUc && checkDc && checkSc;
	}
};

class Solution {
public:
	bool strongPasswordCheckerII(string pwd)
	{
		if (pwd.length() < 8)
			return false;
		
		bool lower = false, upper = false, digit = false, special = false;

		for (int i = 0; i < pwd.length(); i++)
		{
			if (i > 0 && pwd[i] == pwd[i - 1])  
				return false;
			if (islower(pwd[i]))
				lower = true;
			else if (isupper(pwd[i]))
				upper = true;
			else if (isdigit(pwd[i]))
				digit = true;
			else 
				special = true;
		}

		return lower && upper && digit && special;

	}
};