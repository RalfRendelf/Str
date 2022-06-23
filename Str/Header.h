#pragma once
//#include "123.h"
#include <algorithm>
#include <vector>
#include "reshfor14.h"
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
         int cnt1 = 0, cnt2 = 0, rez = 0;
         sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
             {
                 return a[0] < b[0];
             });
    
         for (int i = 0; i < courses.size(); i++)
         {
             if ((courses[i][0] + rez) <= courses[i][1])
             {
                 rez +=courses[i][0];
                 cnt2++;

             }
             

         }
       


         (cnt1 < cnt2) ? cnt1 = cnt2 : 1;
         cnt2 = 0;
         rez = 0;
         sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
             {
                 return a[1] < b[1];
             });

         for (int i = 0; i < courses.size(); i++)
         {
             if ((courses[i][0] + rez) <= courses[i][1])
             {
                 rez += courses[i][0];
                 cnt2++;

             }


         }



         (cnt1 < cnt2) ? cnt1 = cnt2 : 1;

       
         
        if (courses.size() <= 1)
        {
            if (courses.empty())
                return 0;
            if (courses[0][0] <= courses[0][1])
                return 1;
            else
                return 0;
        }
        
        cnt2 = 0;
        rez = 0;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return  (a[1] - a[0] > b[1] - b[0])&&(a[0]<b[0]);
            });
      
        for (int i = 0; i < courses.size(); i++)
        {
            if ((courses[i][0] + rez) <= courses[i][1])
            {
                rez += courses[i][0];
                cnt2++;

            }


        }
        (cnt1 < cnt2) ? cnt1 = cnt2 : 1;
        cnt2 = 0;
        rez = 0;
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int> b)
            {
                return  (a[1] - a[0] > b[1] - b[0]) /*&& (a[0] < b[0])*/;
            });

        for (int i = 0; i < courses.size(); i++)
        {
            if ((courses[i][0] + rez) <= courses[i][1])
            {
                rez += courses[i][0];
                cnt2++;

            }


        }
        print(courses);
        (cnt1 < cnt2) ? cnt1 = cnt2 : 1;
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
            {
                return a[1] > b[1];
            }
        );
       
       rez  = courses[0][1];
         cnt2 = 0; 
        
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
            {
                return a[0] < b[0];
            }
        );
       
        while ((rez > courses[cnt2][0])&&(cnt2 < courses.size()-1))
        {
            rez -= courses[cnt2++][0];
           
        }
        if (cnt2 < courses.size())
        courses.erase(courses.begin() + cnt2, courses.end());
        cnt2 = 0;
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
            {
                return  a[1] - a[0] < b[1] - b[0];
            }
        );
        (cnt1 < cnt2) ? cnt1 = cnt2 : 1;
        rez = 0; 
        cnt2 = 0;
      
        for (int i = 0; i < courses.size(); i++)
        {
            if ((courses[i][0] + rez) <= courses[i][1])
            {
                rez += courses[i][0];
                cnt2++;

               
            }
        } return (cnt2 > cnt1) ? cnt2:cnt1;
    }
}; 