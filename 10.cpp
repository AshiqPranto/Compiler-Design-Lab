#include<bits/stdc++.h>
using namespace std;

map<char,vector<string> >gramer;
string st,input;



void eff()
{

}
void test()
{
    string s = "amra";
    s.erase(2,1);
    cout<<s<<endl;
}




int main()
{
    // eff();
    // test();
    // Given Grammer
    // E -> 2E2
    // E -> 3E3
    // E -> 4
    gramer['E'].push_back("2E2");
    gramer['E'].push_back("3E3");
    gramer['E'].push_back("4");
    st = "$";
    input = "32423$";


    
}