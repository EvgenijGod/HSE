#include <iostream>
#include <string>

using namespace std;

int main() {
  string word;
  getline(cin, word);
  string tmpCode;
  string case1 = "aehiouwy";
  string case2 =  "bfpv";
  string case3 = "cgjkqsxz";
  string case4 = "dt";
  string case5 = "mn";
  for (int i = 1; i < word.length(); ++i) {
    if (case1.find(word[i]) != string::npos)
      continue;
    if (case2.find(word[i]) != string::npos)
      tmpCode += '1';
    if (case3.find(word[i]) != string::npos)
      tmpCode += '2';
    if (case4.find(word[i]) != string::npos)
      tmpCode += '3';
    if (word[i] == 'l')
      tmpCode += '4';
    if (case5.find(word[i]) != string::npos)
      tmpCode += '5';
    if (word[i] == 'r')
      tmpCode += '6';
  }
  string code;
  code += word[0];
  int i = 0;
  while (i < tmpCode.length()) {
    char crrntChar = tmpCode[i];
    code += crrntChar;
    while (i < tmpCode.length() && tmpCode[i] == crrntChar)
      ++i;
  }
  code += "0000";
  for (int j = 0; j < 4; ++j)
    cout << code[j];
  cout << "\n";
  return 0;
}

