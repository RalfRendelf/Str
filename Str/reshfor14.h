#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class Solution {
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int  cnt = 0,a = 0;
        string str = "";
       
           
            for (int h =1; ((h < strs.size())); h++)
            {
                if((strs[0][a] != strs[h][a++])&& (cnt < str.size()))
                {
                    return "";
                }
                else if ((strs[0][a] != strs[h][a]) && (cnt >= strs.size()))
                {
                    return str;
                }
                else
                {
                    cnt++;
                   str += strs[h][a];
                    
                }
        }
           // cout << a << '\t';
         
        return "";
    }

};