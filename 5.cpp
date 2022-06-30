#include<bits/stdc++.h>
using namespace std;

bool isOther(string str)
{
    int sz = str.size();
    for(int i = 0;i<sz;i++)
    {
        if(isdigit(str[i]) || isCharacter(str[i]))
        {
            continue;
        }else{
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string str;
    getline(cin,str);

    

}