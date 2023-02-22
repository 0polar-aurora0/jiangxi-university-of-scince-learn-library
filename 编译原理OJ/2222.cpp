#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define ROW 4
#define COL 8
string AnalysisTable[ROW][COL]={
{"","a","b","c","d","p","q","#"},
{"A","a","","cAd","","","",""},
{"B","","b","","dB","","",""},
{"S","","","","","pA","qB",""}
};
string GetAnalysisTable(string x,string a)
{
    string cell = "";
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(x == AnalysisTable[i][0] && a == AnalysisTable[0][j]){
                cell = AnalysisTable[i][j];
                break;
            }
        }
    }
    return cell;
}
bool LL1(string inputstring)
{
    int i = 0;
    string a;
    string X;
    string RHS;
    bool flag = true;
    vector<string> v;
    v.push_back("#");
    v.push_back(AnalysisTable[3][0]);
    a = inputstring[i];
    while(flag)
    {
        X = v[v.size()-1];
        if(X == a && a == "#")
        {
            flag = true;
            break;
        }
        else if(X == a && a != "#"){
            v.pop_back();
            a = inputstring[++i];
        }else if((RHS = GetAnalysisTable(X,a))!="")
        {
            if(RHS != "")
            {
                v.pop_back();
                for(int k=RHS.size()-1;k>=0;k--)
                {
                    string Vn;
                    Vn = RHS.substr(k,1);
                    if(Vn == ""){
                        Vn = RHS.substr(k-1,2);
                        k--;
                    }
                    v.push_back(Vn);
                }
            }else
            {
                v.pop_back();
            }
        }else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    string SymbolString;
    while(cin>>SymbolString)
    {
        bool flag = LL1(SymbolString);
        if(flag)
            cout<<"syntax correct"<<endl;
        else
            cout<<"syntax error"<<endl;
    }
    return 0;
}
