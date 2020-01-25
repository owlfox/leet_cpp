#ifndef MAIN
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=341
#endif
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


//return maxsize
size_t toSortedFixedWidth(vector<string>& input) {
    sort(input.begin(), input.end());
    auto sizeWord = (*max_element(input.begin(), input.end(), 
        [](string s1, string s2){return s1.length() < s2.length();})).length() + 2;
    for(auto&s : input) {
        s.append(string(sizeWord-s.length(), ' '));
    }
    return sizeWord;
}
void displayNames(vector<string>& input, size_t sizeWord, size_t lineWidth=60) {
    auto words_per_line = lineWidth / sizeWord ;
    auto lines_count = input.size() / words_per_line;
   auto words_last_row = input.size() % words_per_line;

   string separator(60, '-');
    cout << separator << endl;
    cout << setw(sizeWord);
    for(auto i=0; i<input.size(); i++) {
        //convert index
        auto c = i % words_per_line;
        auto r  = i / words_per_line;
        auto position = c < words_last_row ? c*(lines_count+1)+r : c*lines_count+r;
        cout << input[position];
        if(c == words_per_line - 1) cout << endl;
        

    }
    
}

#ifdef MAIN
int main() {
    auto size{0};
    
    while(cin >> size) {
        vector<string> input;
        
        for(auto i=0 ;i<size;i++) {
            auto name = string();
            cin >> name;
            input.push_back(name);

        }
        //for(auto& s: input) cout << s << endl;
        auto wordLength = toSortedFixedWidth(input);
        //for(auto& s: input) cout << s << endl;
        displayNames(input, wordLength);
    }
}
#else

TEST_CASE("A simple test")
{
    SECTION("test case 1")
    {
        vector<string> in{"d", "b", "ccc"};
        toSortedFixedWidth(in);
        REQUIRE(in == vector<string> {"b    ", "ccc  ", "d    "});
    }
}

#endif

