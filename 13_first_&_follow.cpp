#include<bits/stdc++.h>
using namespace std;

vector<string> inp[200];
bool dpFirst[200],dpSecond[200];
vector<set<string> >first(200),fol(200);

bool isCapital(char c)
{
    if(c>='A' && c<='Z') return true;
    return false;
}

set<string> calculateFirst(char f)
{
    if(dpFirst[f]) return first[f];
    if(!isCapital(f))
    {
        set<string> temp ;
        string tempString;
        tempString+=f;
        temp.insert(tempString);
        return temp;
    }
    set<string>ans,temp;
    string store;
    for(int i = 0;i<inp[f].size();i++)
    {
        store = inp[f][i];
        if(isCapital(store[0]))
        {
            temp = calculateFirst(store[0]);
            for(auto j : temp)
            {
                ans.insert(j);
            }
        }
        else{
            string temp1;
            temp1 += store[0];
            ans.insert(temp1);
        }
    }
    dpFirst[f] = true;
    for(auto x : ans)
    {
        first[f].insert(x);
    }
    return ans;
}
set<string> calculateFollow(char f)
{
    if(dpSecond[f]) return fol[f];
    // cout<<"called follow for -> "<<f<<endl;
    set<string>tempSet;
    for(int j = 'A';j<='Z';j++)    
    {
        if(inp[j].size())
        {
            for(int k = 0;k<inp[j].size();k++)
            {
                string temp = inp[j][k];
                for(int l = 0;l<temp.size();l++)
                {
                    if(temp[l]==f)
                    {
                        bool getepsilon = false;
                        do
                        {
                            l++;
                            getepsilon = false;
                            // for(auto x : first[temp[l]])
                            set<string> tempSet1;
                            if(l == temp.size() && temp[l-1]!=j)
                            {
                                tempSet1 = calculateFollow(j);
                            }else{
                                tempSet1 = calculateFirst(temp[l]);
                            }
                            for(auto x : tempSet1)
                            {
                                if(x=="#")
                                    getepsilon = true;
                                else
                                    tempSet.insert(x);
                            }
                        } while (getepsilon && l<= temp.size());
                        break;
                    }

                }
            }
        }
    }
    for(auto x : tempSet)
    {
        fol[f].insert(x);
    }
    dpSecond[f] = true;
    return tempSet;
}

int main()
{
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    memset(dpFirst,false,sizeof(dpFirst));
    memset(dpSecond,false,sizeof(dpSecond));
    
    string str,temp1,temp2;
    char start = '0';
    while(getline(cin,str))
    {
        temp1 = str.substr(0,1);
        temp2 = str.substr(5);
        if(start=='0') start = temp1[0];
        inp[temp1[0]].push_back(temp2);
    }
    // for(int i = 'A';i<='Z';i++)
    // {
    //     if(inp[i].size())
    //     {
    //         for(int j = 0;j<inp[i].size();j++)
    //         {
    //             cout<<i<<" -> "<<inp[i][j]<<endl;
    //         }
    //     }
    // }


    for(int i = 'A';i<='Z';i++)
    {
        if(inp[i].size())
        {
            set<string> temp = calculateFirst(i);
            printf("First(%c) => {",i);
            for(auto j: temp){
                cout<<j<<", ";
                first[i].insert(j);
            }
            cout<<"}"<<endl;
        }
    }
    // jar follow ber korbo tar por jodi kichu na thake tahole follow hobe index er follow.
    // jar follow ber korbo tar por jodi non terminal thake tahole follow hobe oi non terminal er first.
    // follow set e kokhono epsilon hobe na && start symbol er follow set suru tei $ sign hobe.
    // cout<<"no"<<endl;
    cout<<"start = "<<start<<endl;
    fol[start].insert("$");
    for(int i = 'A';i<='Z';i++)
    {
        if(inp[i].size())
        {
            set<string> temp =  calculateFollow(i);
            printf("Follow(%c) => {",i);
            for(auto x : temp)
            {
                fol[i].insert(x);
            }
            for(auto x: fol[i])
                cout<<x<<", ";
            cout<<"}"<<endl;
        }
    }
}
