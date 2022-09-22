#include<bits/stdc++.h>
using namespace std;

vector<string> inp[200];
vector<string> first[200];

bool isCapital(char c)
{
    if(c>='A' && c<='Z') return true;
    return false;

}

vector<string> calculateFirst(char f)
{
    vector<string>ans,temp;
    string store;
    for(int i = 0;i<inp[f].size();i++)
    {
        store = inp[f][i];
        if(isCapital(store[0]))
        {
            temp = calculateFirst(store[0]);
            for(int j = 0;j<temp.size();j++)
            {
                ans.push_back(temp[j]);
            }
        }
        else{
            string temp1;
            temp1 += store[0];
            ans.push_back(temp1);
        }
    }
    return ans;
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // string str;

    // getline(cin,str);

    inp['E'].push_back("TR");
    inp['R'].push_back("+TR");
    inp['R'].push_back("#");
    inp['T'].push_back("FY");
    inp['Y'].push_back("*FY");
    inp['Y'].push_back("#");
    inp['F'].push_back("(E)");
    inp['F'].push_back("i");

    for(int i = 'A';i<='Z';i++)
    {
        if(inp[i].size())
        {
            vector<string> temp = calculateFirst(i);
            printf("First(%c) => {",i);
            cout<<temp[0];
            for(int i= 1;i<temp.size();i++) cout<<", "<<temp[i];
            cout<<"}"<<endl;
        }
    }
    // jar follow ber korbo tar por jodi kichu na thake tahole follow hobe index er follow.
    // jar follow ber korbo tar por jodi non terminal thake tahole follow hobe oi non terminal er first.
    // follow set e kokhono epsilon hobe na && start symbol er follow set suru tei $ sign hobe.
    


}
