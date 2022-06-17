#pragma once

#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void print(string s)
{
    cout << s << "\n";
    system("pause");
}
void print(vector<list<string>> str)
{
    for (auto a : str) {
        cout << '\t';
        for (auto b : a)
            cout << b;
    }

}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs);
private:
    bool Proverka(string& word, string g);
    string commonPart(vector<list<string>>& a);
    
};
string Solution::longestCommonPrefix(vector<string>& strs) {
    string str;
    vector<list<string>> strH;
    list<string> ah;
    // strH.push_back(strH[0]);
    
    list<string>::iterator b;

    int cnt = 0, cnt2 = 0;
    for (auto k = 1; k < strs.size(); k++)
    {

        for (int h = 0; (h < strs[k].size()) && (h < strs[0].size()); h++)
        {
            if ((k > 1))
            {
               // print(strH);
                cnt = 0;
                cnt2 = 0;
                if (strH.size() > 0)
                {
                    for (auto i = 0; i != strH.size(); i++) {
                        b = strH[i].begin();
                        
                        for (/*int  j = 0;j<strH[i].size(); j++*/auto& c : strH[i])
                        {

                            if (!Proverka(strs[k], c))
                            {
                                if (cnt == 0)
                                {
                                   // print(c);
                                    //print(strH);
                                strH.erase(strH.begin()+i);
                                
                              //  print(strH);
                                if (strH.empty())
                                {
                                    str = "";
                                        return str;
                                }
                                    break;
                                }
                                else
                                {
                                  //  print(strH);
                                   // print(c);
                                    strH[i].erase(b, strH[i].end());
                                  //  print(strH);
                                    break;
                                }
                                

                            }
                            if ((cnt2 == 0) && (strH.size() == 1))
                            {
                                
                            }
                            cnt++;
                            b++;

                        }
                    }

                }
                else
                {
                    str = "";
                    return str;
                }


            }
            else {


                if (!Proverka(strs[k], str + strs[0][h]))
                {
                    if (cnt > 0)
                    {
                       // print(str);
                        strH[cnt2++].push_back(str);
                        str = "";
                        cnt = 0;
                        strH.push_back(ah);
                    }


                }
                else
                {
                    
                    if (cnt > 0)
                    {
                      //  print(str);
                        str += strs[0][h];
                        strH[cnt2].push_back(str);
                        cnt++;
                    }
                    else
                    { 
                       // print(str);
                        strH.push_back(ah);
                        str = strs[0][h];
                        strH[cnt2].push_back(str);
                        cnt++;
                    }

                }

            }
        }

    }
    if (!strH.empty())
    {
        cout << commonPart(strH);
        return commonPart(strH);
    }
    else
        return str = "";


}
bool Solution::Proverka(string& word, string g)
{
    int sh = 0;
    for (int h = 0; (h /*+ g.size()*/) < word.size(); ++h)
    {
        for (int k = 0; (k < g.size())&&(h+g.size()<=word.size()); k++)
        {
            if (word[h+k] != g[k]) {
                sh= 0;
                break;
            }
            else {
                ++sh;
                if (g.size() == (k+1))
                {
                    return true;
                }
            }
        }
    }
    return sh;
}
string Solution::commonPart(vector<list<string>>& a)
{
    string str = "";
    for (auto c : a)
    {
        for (auto v = c.begin(); v != c.end(); v++)
        {
            if (str < *v)
            {
                str = *v;
            }
        }
    }
    return str;
}
