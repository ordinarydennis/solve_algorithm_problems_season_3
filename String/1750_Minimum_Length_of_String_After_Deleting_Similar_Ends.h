class Solution {
public:
	int minimumLength(string s) {

		int begin = 0;
		int end = s.size() - 1;

		while (begin < end && s[begin] == s[end])
		{
			char c = s[begin];

			while (begin <= end && c == s[begin])
			{
				begin++;
			}

			while (begin < end && c == s[end])
			{
				end--;
			}
		}

		return end - begin + 1;
	}
};



class Solution {
public:
	int minimumLength(string s) {

		int si = 0;
		int ei = s.size() - 1;

		while (si < ei)
		{
			int osi = si;
			int oei = ei;

			char sc = s[si];

			while (si + 1 < s.size() && s[si + 1] == sc)
			{
				si++;
			}

			char ec = s[ei];

			while (0 < ei - 1 && s[ei - 1] == ec)
			{
				ei--;
			}

			if (s[si] == s[ei] && ei <= si)
			{
				return 0;
			}

			if (s[si] != s[ei])
			{
				return oei - osi + 1;
			}

			si++;
			ei--;
		}

		return (ei < si) ? 0 : (ei - si) + 1;
	}
};