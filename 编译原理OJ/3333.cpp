#include <iostream>
#include<vector>
using namespace std;
#include<string>
#define  ROW 9
#define  COLUMN 9
#define  PRODUCTS 8
int TokenIndex = 0;
string OperatorPrecedenceTable[ROW][COLUMN] = {
    { " ", "a", "o","n","(",")","t","f", "#" },
    { "a", ">", ">", "<", "<",">","<","<",">"},
    { "o", "<", ">", "<", "<",">","<","<",">" },
    { "n", ">", ">", "<", "<",">","<","<",">"},
    { "(", "<", "<", "<", "<","=","<","<",""},
    { ")", ">", ">", "", "",">","","",">"},
    { "t", ">", ">", "", "",">","","",">"},
    { "f", ">", ">", "", "",">","","",">"},
    { "#", "<", "<", "<", "<","","<","<","="}
};
string Grammar[PRODUCTS][2] = {
     {"N","NoN"},
     {"N","N"},
     {"N","NaN"},
     {"N","N"},
     {"N","nN"},
     {"N","(N)"},
     {"N","t"},
     {"N","f"}
};
string GetPrecedence(string ai,string aj)
{
    string cell = "";
    for (int i = 0; i < ROW; i++)  {
            for (int j = 0; j < COLUMN; j++)   {
                if (ai == OperatorPrecedenceTable[i][0] && aj == OperatorPrecedenceTable[0][j])    {
                    cell = OperatorPrecedenceTable[i][j];
                    break;
                }
            }
    }
    return cell;
}

string GetLHS(string RHS)
{
    string LHS = "";
    for (int i = 0; i<PRODUCTS; i++)
    {
        if (RHS == Grammar[i][1])
        {
            LHS = Grammar[i][0];
            break;
        }
    }
    return LHS;
}

int GetTopVtPos(vector<string> s) {
    int i = s.size() - 1;
    if (s[i] == "N")
        i--;
    return i;
}

string GetLpp(vector<string> s) {
    int i = GetTopVtPos(s);
    int k, k1;
    k = k1 = i;
    do
    {
        k = k1;
        if (s[k - 1] == "N")
            k1 = k - 2;
        else
            k1 = k - 1;
    } while (GetPrecedence(s[k1], s[k]) == "=");
    string lpp = "";
    if (i<s.size() - 1 && s[i + 1] == "N")
        i = i + 1;
    if (k >= 1 && s[k - 1] == "N")
        k = k - 1;
    for (int j = k; j <= i; j++)  {
            lpp.append(s[j]);
    }
    return lpp;
}

bool OPA(string inputstring)
{
    int i, k;
    bool flag = false;
    TokenIndex = 0;
    string lpp, lhs;
    string X, a, Precedence;
    vector<string> stacks;
    stacks.push_back("#");
    a = inputstring[TokenIndex++];
    while (true)  {
        i = GetTopVtPos(stacks);
        X = stacks[i];   Precedence = GetPrecedence(X, a);
        if ((Precedence == "<" || Precedence == "=") && a != "#")
        {
            stacks.push_back(a);
            a = inputstring[TokenIndex++];
        } else if (X == a&&a == "#")
        {
            flag = true;
            break;
        }   else if (Precedence == ">")   {
                lpp = GetLpp(stacks);
                lhs = GetLHS(lpp);
                if (lhs != "")
                {
                    for (int j = 0; j<lpp.size(); j++)
                        stacks.pop_back();
                    stacks.push_back("N");
                }    else    {
                    flag = false;
                    break;
                }
        }   else   {
                 flag = false;
                 break;
        }
    }
    return flag;
}
int main()
{
    string symbolstring;
    while (cin >> symbolstring)  {
        bool flag = OPA(symbolstring);
        if (flag)
            cout << "syntax correct" << endl;
        else
            cout << "syntax error" << endl;
    }
    return 0;
}
