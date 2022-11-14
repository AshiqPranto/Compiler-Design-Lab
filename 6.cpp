#include<bits/stdc++.h>
using namespace std;

bool isBinaryNumber(string str)
{
    int size = str.size();

    if (size < 2)
        return false;

    if (str[0] != '0')
    {
        return false;
    }

    if (str[1] != '0' && str[1] != '1')
    {
        return false;
    }

    // Check
    bool isOK = true;

    for (int i = 2; i < str.size(); i++)
    {
        if (str[i] != '1' && str[i] != '0')
        {
            isOK = false;
            break;
        }
    }
    return isOK;
}

bool isCharacter(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
    {
        return true;
    }
    return false;
}

bool isOther(string str)
{
    int sz = str.size();
    for(int i = 0;i<sz;i++)
    {
        if(isdigit(str[i]) || isCharacter(str[i]) || str[i]=='_')
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

    string subString = str.substr(0,3); 

    // cout<<subString<<endl;
    if(isOther(str))
    {
        cout<<"Invalid Input or Undefined\n";
    }
    else if(subString == "ch_" && (isCharacter(str[3]) || isdigit(str[3])))
    {
        cout<<"Character variable\n";
    }
    else if(subString == "bn_" && (isCharacter(str[3]) || isdigit(str[3])))
    {
        cout<<"Binary variable\n";
    }
    else if(isBinaryNumber(str))
    {
        cout<<"Binary Number\n";
    }
    else{
        cout<<"Invalid Input or Undefined\n";
    }

}
