#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    char isAlphabet(char c)
    {

        int charASCII = int(c);

        if (charASCII > 64 && charASCII < 91)
        {
            char a = char(charASCII + 32);
            return a;
        }
        else if (charASCII > 96 && charASCII < 123)
        {
            return c;
        }
        else
            return NULL;
    }

    bool isPalindrome(string s)
    {

        int st = 0;
        int end = s.length() - 1;

        while (st < end)
        {

            char startAlpha = isAlphabet(s[st]);

            char endAlpha = isAlphabet(s[end]);

            if (startAlpha == NULL)
            {
                st++;
                continue;
            }
            if (endAlpha == NULL)
            {
                end--;
                continue;
            }

            if (startAlpha == endAlpha)
            {
                st++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    s.isPalindrome("RU");
}