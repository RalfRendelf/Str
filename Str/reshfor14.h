#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class Solution2 {

public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int  cnt = 0, a = 0;
        string str = "";
     
        for (a = 0; a < strs[0].size(); a++) {

            for (int h = 0; ((h < strs.size())); h++)
            {
                if ((strs[0][a] != strs[h][a]))
                {
                    return str;
                }
                cnt = 1;
            }
            if (cnt == 1)
            {
                str += strs[0][a];
            }

        }
        // cout << a << '\t';

        return str;
    }

};
void print(vector<vector<int>>& courses)
{
    for (auto a : courses) {
        cout << '\n';
        for (auto b : a)
            cout << b << '\t';
    }


    cout << '\n' << "===============================================================================" << '\n';
}