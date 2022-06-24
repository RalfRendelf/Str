#pragma once
//#include "123.h"
#include <algorithm>
#include <vector>
#include "reshfor14.h"
using namespace std;

class Solution {
    inline int Sortirov(vector<vector<int>>& courses);
    int Perezap(vector<vector<int>> courses);
    int srch(vector<vector<int>> courses);
    int sol(vector<vector<int>> courses);
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int cnt = 0;


        if (courses.size() <= 1)
        {
            if (courses.empty())
                return 0;
            if (courses[0][0] <= courses[0][1])
                return 1;
            else
                return 0;
        }
        sort(courses.begin(), courses.end());
            (cnt < Sortirov(courses)) ? cnt = Sortirov(courses) : 1;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return a[0] < b[0];
            });
        (cnt < Sortirov(courses)) ? cnt = Sortirov(courses) : 1;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return a[1] < b[1];
            });

        (cnt < Sortirov(courses)) ? cnt = Sortirov(courses) : 1;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return  (a[1] - a[0] > b[1] - b[0]) && (a[0] < b[0]);
            });

        (cnt < Sortirov(courses)) ? cnt = Sortirov(courses) : 1;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return  (a[1] - a[0] > b[1] - b[0]) /*&& (a[0] < b[0])*/;
            });

        (cnt < Sortirov(courses)) ? cnt = Sortirov(courses) : 1;

      
       
        (cnt < Perezap(courses)) ? cnt = Perezap(courses) : 1;
        (cnt < srch(courses)) ? cnt = srch(courses) : 1;

        return cnt;
    }
};
inline int Solution::Sortirov(vector<vector<int>>& courses)
{
    int  cnt = 0, rez = 0;
    for (int i = 0; i < courses.size(); i++)
    {
        if ((courses[i][0] + rez) <= courses[i][1])
        {
            rez += courses[i][0];
            cnt++;

        }


    }

    return cnt;
}
int Solution::Perezap(vector<vector<int>> courses)
{
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
        {
            return a[1] > b[1];
        }
    );
    int rez = courses[0][1], cnt = 0;
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
        {
            return a[0] < b[0];
        }
    );
    while ((rez >= courses[cnt][0]) && (cnt < courses.size() - 1))
    {
        rez -= courses[cnt++][0];

    }
    if (cnt < courses.size())
        courses.erase(courses.begin() + cnt, courses.end());
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
        {
            return  a[1] - a[0] < b[1] - b[0];
        }
    );
   
    rez = 0;


    (rez < Sortirov(courses)) ? rez = Sortirov(courses) : 1;
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
        {
            return  (a[1]< b[1])&&(a[0]<b[0]);
        }
    );
    
    (rez < Sortirov(courses)) ? rez = Sortirov(courses) : 1;
    
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
        {
            return  (a[1] > b[1]) && (a[0] > b[0]);
        }
    );
    
    (rez < Sortirov(courses)) ? rez = Sortirov(courses) : 1;
    sort(courses.begin(), courses.end());
    (rez < Sortirov(courses)) ? rez = Sortirov(courses) : 1;
    return rez;
}
int Solution::srch(vector<vector<int>> courses)
{
    int midle = 0;
    int tt = courses.size(), cnt = 0;
   
        for (int h = 0; h < courses.size(); h++) {
            midle += courses[h][0];
           
        }
    midle = midle/tt;
    midle *= 1.7;
   // print(courses);
    for (int i = 0; i < courses.size();)
    {
        if (courses[i][0] > midle)
        {
            courses.erase(courses.begin() + i);

        }
       else
            i++;
    }
  //  print(courses);
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
        {
            return (a[1]-a[0] < b[1]-b[0]);
        }
    );
    (cnt < Sortirov(courses)) ? cnt = Sortirov(courses) : 1;
   // print(courses);
    return cnt;

}
int Solution::sol(vector<vector<int>> courses)
{
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
        {
            return  a[1] - a[0] < b[1] - b[0];
        }
    );
    int midle = 0;
    int tt = courses.size(), cnt = 0;

    for (int h = 0; h < courses.size(); h++) {
        midle += courses[h][0];

    }
    midle = midle / tt;
    midle *= 1.7;
    // print(courses);
    for (int i = 0; i < courses.size();)
    {
        if (courses[i][0] > midle)
        {
            courses.erase(courses.begin() + i);

        }
        else
            i++;
    }

}