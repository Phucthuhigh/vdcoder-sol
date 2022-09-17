// SORTSTRNUM

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    vector<string> words;
    vector<string> numbers;
    bool alpha = true;
    while (cin)
    {
        if (cin.peek() == '\n') break;
        string tmp;
        if (alpha)
        {
            while (isalpha(static_cast<unsigned char>(cin.peek())))
                tmp += cin.get();
            words.push_back(move(tmp));
            alpha = false;
        }
        else
        {
            while (isdigit(static_cast<unsigned char>(cin.peek())))
                tmp += cin.get();
            numbers.push_back(move(tmp));
            alpha = true;
        }
    }
    std::sort(numbers.begin(), numbers.end(), [](const string& lhs, const string& rhs)
    {
        if (lhs.size() != rhs.size()) return lhs.size() < rhs.size();
        else return lhs < rhs;
    });
    for (size_t i = 0; i < max(words.size(), numbers.size()); ++i)
    {
        if (i < words.size()) cout << words[i];
        if (i < numbers.size()) cout << numbers[i];
    }
    return 0;
}
    