#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

/* I am implementing the solution to the excellent set of string related programming problems 
   mentioned in the link: https://www.geeksforgeeks.org/c-programs-gq/string-programs-gq/  */

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

/* https://www.geeksforgeeks.org/print-list-items-containing-all-characters-of-a-given-word/ */
void PrintListItemsContainingString(string str)
{
    int iNumOfItemsInList = 0;
    cout << "Enter the number of items to be added into the list : " << endl;
    cin >> iNumOfItemsInList;

    vector<string> listOfString(iNumOfItemsInList);
    for (auto & strings : listOfString)
    {
        cin >> strings;
    }

    bool bCharNotFound = false;
    for (auto & strings : listOfString)
    {
        for (auto & c : str)
        {
            if (strings.find(c) == string::npos)
            {
                bCharNotFound = true;
                break;
            }
            bCharNotFound = false;
        }

        if (bCharNotFound == false)
            cout << strings << endl;
    }
    
}

/* https://www.geeksforgeeks.org/reverse-words-in-a-given-string/ */
void ReverseWordsInAString(string str)
{
    vector<string> words;
    
    string sWord = "";
    for (const auto &c : str)
    {
        if (c == ' ')
        {
            if (sWord.length() > 0)
                words.push_back(sWord);

            sWord = "";
            continue;
        }
        sWord += c;
    }

    if (sWord.length() > 0)
        words.push_back(sWord);

    for (auto iIterate = rbegin(words); iIterate != rend(words); iIterate++)
    {
        cout << *iIterate << " ";
    }

}

/* https://www.geeksforgeeks.org/run-length-encoding/ */
void PrintRunLengthEncodedString(string str)
{
    string sEncodedString = "";
    vector<pair<char, int>> counter;
    for (const auto & c : str)
    {
        // For the first iteration
        if (counter.empty())
        {
            pair<char, int> element(c, 1);
            counter.push_back(element);            
            continue;
        }
        if (counter.back().first == c) // To handle repeats
        {
            counter.back().second++;
            continue;
        }
        pair<char, int> element(c, 1);
        counter.push_back(element);
        
    } // End of for loop

    for (const auto &p : counter)
    {
        sEncodedString += p.first;
        sEncodedString += to_string(p.second);
    }

    cout << endl << "Encoded string is " << sEncodedString << endl;
}

/* https://www.geeksforgeeks.org/c-program-find-second-frequent-character/ */
struct KVP_Comparer
{
    inline bool operator() (const pair<char, int>& kvp1, const pair<char, int>& kvp2)
    {
        return (kvp1.second < kvp2.second);
    }
};

void PrintSecondMostFrequentCharacter(string str)
{
    vector<pair<char,int>> counter;
    
    // Push how many times each of the characters appear into a vector
    for (int iIndex = 0; iIndex < 256; iIndex++)
    {
        pair<char, int> kvp(iIndex, 0);
        counter.push_back(kvp);
    }

    for (const auto &c : str)
    {
        // Each time the character appears, increment its count
        counter[c].second++;
    }

    // Sort based on the counter value
    sort(begin(counter), end(counter), KVP_Comparer());

    // Last but one value is the second most frequent element. Last will be the most frequent
    cout << "Second most frequent character is : " << counter[254].first << endl;

}

/* End of https://www.geeksforgeeks.org/c-program-find-second-frequent-character/ */

int main() {
    string str1;
    //string str2; // Separating this into a new line so that its easier to comment out when only one param is needed
    //cin >> str1;
    getline(cin, str1);

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

    // PrintFirstNonRepeatingCharacter(str1);

    // PrintListItemsContainingString(str1);

    // ReverseWordsInAString(str1);

    // PrintRunLengthEncodedString(str1);

     PrintSecondMostFrequentCharacter(str1);

    getchar();
    return 0;
}