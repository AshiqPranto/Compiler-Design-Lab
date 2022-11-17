#include <bits/stdc++.h>
using namespace std;
vector<string> production = {"E+E", "E-E", "E*E", "E/E", "(E)", "a", "b", "c"};
vector<string> deg;

void genDeg() {
  string down = "/|";
  down.push_back(char(92));
  // cout << down << endl;
  deg = {down, down, down, down, down, "|", "|", "|"};
}

string input, space, extra = "";
stack<string> parse_tree;
int n;
void makeSpace() {
  space.clear();
  for (int i = 0; i <= n; i++) {
    space += " ";
  }
}
bool getReduced() {
  int len = input.size();
  bool ok = false;
  for (int i = 0; i < len; i++) {
    int prodIndex = 0;
    for (auto prod : production) {
      int ind = i;
      bool ok = true;
      for (char ch : prod) {
        if (ch != input[ind]) {
          ok = false;
          break;
        }
        ind++;
      }
      if (ok) {
        // production match
        input.erase(i, prod.size());
        input.insert(i, "E");
        makeSpace();
        space.insert(i + extra.size(), deg[prodIndex]);
        parse_tree.push(space);
        if (prod.size() == 3) {
          extra += " ";
        }
        parse_tree.push(extra + input);
        return true;
      }
      prodIndex++;
    }
  }
  return false;
}
int main() {
  genDeg();
  cin >> input;
  input += '$';
  n = input.size();
  parse_tree.push(input);
  while (input.size() > 2 || (input.size() == 2 && input[0] != 'E')) {
    // parse_tree.push(input);
    bool ok = getReduced();
    if (ok)
      continue;
    cout << "Invalid String." << endl;
    return 0;
  }
  // cout << input << " : last situation." << endl;
  // parse_tree.push(input);
  while (!parse_tree.empty()) {
    string str = parse_tree.top();
    str.pop_back();
    cout << str << endl;
    parse_tree.pop();
  }
  return 0;
}