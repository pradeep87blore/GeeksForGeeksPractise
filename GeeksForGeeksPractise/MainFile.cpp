#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;


/* https://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/ */
char MaxOccuringChar(const string &str)
{
    vector<int> letters; // a-z

    letters.assign(26, 0);

    for (auto &i : str)
    {
        if (i < 'a' || i > 'z')
            continue;

        letters[i - 'a']++;
    }

    auto maxVal = max_element(begin(letters), end(letters));
    char cLetter = maxVal - begin(letters);
    cLetter += 'a';
    return cLetter;
}

/* https://www.geeksforgeeks.org/remove-all-duplicates-from-the-input-string/ */
auto RemoveDuplicates(const string &str)
{
    vector<bool> chars; // Stores all ascii characters

    chars.assign(256, false);

    string sNew = "";

    for (const auto &c : str)
    {
        if (chars[c] == true)
            continue;

        chars[c] = true;
        sNew += c;
    }

    return sNew;
}

/* https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/ */
void PrintAllDuplicates(const string &str)
{
    vector<int> chars;
    chars.assign(256, 0); // Initialize to 0 for all ascii symbols

    for (const auto &c : str)
    {
        chars[c] += 1;
    }

    for (int iIndex = 0; iIndex < 256; iIndex++)
    {
        if (chars[iIndex] > 1)
        {
            char c = static_cast<char> (iIndex);
            cout << c << " " << chars[iIndex] << endl;
        }
    }
}

/* https://www.geeksforgeeks.org/remove-characters-from-the-first-string-which-are-present-in-the-second-string/ */
auto RemoveCharsFromFirstStringPresentInSecond(const string & str1, const string & str2)
{
    string newStr = str1;
    for (const auto &c : str2)
    {
        size_t pos = string::npos;
        do // Remove all occurences of this letter in the str1
        {
            pos = newStr.find(c);
            if (pos != string::npos)
                newStr.erase(pos, 1);
        } while (pos != string::npos);
    }

    return newStr;
}

/* https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/ */
auto CheckIfStringIsARotation(const string& str1, const string& str2)
{
    string str1Copy = str1 + str1;
    string str2Copy = str2 + str2;
    if (str1Copy.find(str2) != string::npos)
    {
        cout << str1 << " is a rotation of " << str2 << endl;
    }
    else if (str2Copy.find(str1) != string::npos)
    {
        cout << str1 << " is a rotation of " << str2 << endl;
    }
    else
    {
        cout << str1 << " is NOT a rotation of " << str2 << endl;
    }
}

/* https://www.geeksforgeeks.org/reverse-a-string-using-recursion/ */
void ReverseStringUsingRecursion(string str, int iIndex)
{
    if (str.length() > static_cast<unsigned int> (iIndex))
    {
        ReverseStringUsingRecursion(str, iIndex + 1);
        cout << str[iIndex];
    }

}

/* https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/*/
void Swap(string& str1, int iPos1, string& str2, int iPos2)
{
    auto c1 = str1.at(iPos1);
    auto c2 = str2.at(iPos2);

    str1.erase(iPos1, 1);
    str1.insert(iPos1, { c2 });
    str2.erase(iPos2, 1);
    str2.insert(iPos2, { c1 });
}

void PrintPermutations(string str, int begIndex, int endIndex)
{
    if (begIndex == endIndex)
    {
        cout << str << endl;
    }
    else
    {
        for (int iIndex = begIndex; iIndex < endIndex; iIndex++)
        {
            Swap(str, begIndex, str, iIndex);
            PrintPermutations(str, begIndex + 1, endIndex);
            Swap(str, begIndex, str, iIndex);
        }
    }
}
// End of https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

/* https://www.geeksforgeeks.org/divide-a-string-in-n-equal-parts/ */
void SplitStringIntoEqualSubparts(string str, int iSplitCount)
{
    auto len = str.length();

    int iIndex = 0;
    for (const auto &c : str)
    {
        if (iIndex == (len / iSplitCount))
        {
            cout << endl;
            iIndex = 0;
        }
        cout << c;
        iIndex++;
    }
}

/* https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/ */
void PrintFirstNonRepeatingCharacter(const string &str)
{
    // Loop through the string
    // Use the find option to see if the same character appears anywhere else further down
    // If it doesnt, this is the ouput expected.

    int iIndex = 0;
    for (const auto &c : str)
    {
        if (string::npos == str.find(c, iIndex + 1))
        {
            // Check the count to see if we actually dont have any repeats or
            // if we just reached the end of the string, even though there are repititions
            auto countOfRepeat = count(begin(str), end(str), c);
            if (countOfRepeat > 1)
            {
                cout << "No non repetitive characters found";
            }
            else
            {
                cout << c;
            }
            
            return;
        }
        iIndex++;
    }
}

int main() {
    string str1;
    //string str2; // Separating this into a new line so that its easier to comment out when only one param is needed
    cin >> str1;
    //cin >> str2;

    // cout << MaxOccuringChar(str);

    // cout << RemoveDuplicates(str);

    // PrintAllDuplicates(str);

    // cout << RemoveCharsFromFirstStringPresentInSecond(str1, str2);

    // CheckIfStringIsARotation(str1, str2);

    // ReverseStringUsingRecursion(str1, 0);

    /*cout << endl << "Permutations are : " << endl;
    PrintPermutations(str1, 0, str1.length());*/

    /*int iSplitCount = 0;
    cin >> iSplitCount;
    SplitStringIntoEqualSubparts(str1, iSplitCount);*/

    PrintFirstNonRepeatingCharacter(str1);

    getchar();
    return 0;
}