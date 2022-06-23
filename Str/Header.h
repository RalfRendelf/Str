#pragma once
//#include "123.h"
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int cnt1 = 0, cnt2 = 0, rez = 0;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return a[1] < b[1];
            });
        for (int i = 0; i < courses.size(); i++)
        {
            if ((courses[i][0] + rez) <= courses[i][1])
            {
                rez +=/* courses[i][1] - */courses[i][0];
                cnt1++;

            }
            //else


        }
        rez = 0;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return a[0] < b[0];
            });
        for (int i = 0; i < courses.size(); i++)
        {
            if ((courses[i][0] + rez) <= courses[i][1])
            {
                rez += /*courses[i][1] - */courses[i][0];
                cnt2++;

            }
        }
        (cnt1 < cnt2) ? cnt1 = cnt2 : 1;
        cnt2 = 0;
        rez = 0;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return a[0] > b[0];
            });
        for (int i = 0; i < courses.size(); i++)
        {
            if ((courses[i][0] + rez) <= courses[i][1])
            {
                rez += /*courses[i][1] - */courses[i][0];
                cnt2++;

            }
        }
        (cnt1 < cnt2) ? cnt1 = cnt2 : 1;
        rez = 0;
        cnt2 = 0;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return a[1] > b[1];
            });
        for (int i = 0; i < courses.size(); i++)
        {
            if ((courses[i][0] + rez) <= courses[i][1])
            {
                rez += /*courses[i][1] - */courses[i][0];
                cnt2++;

            }
        }

           
        return (cnt1 > cnt2) ? cnt1 : cnt2;
        
    }
};