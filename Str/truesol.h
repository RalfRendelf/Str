#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string g = strs[0];
        for (auto a : strs)
        {
            if (g.size() > a.size())
            {
                g = a;
            }
}
    }
    
};