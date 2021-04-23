***************************************************************
	LECTURE 2. SIZEOF, VECTORS

#include <iostream>

using namespace std;

int main() {
  int i = 42;
  char c ='@'; 
  double d = 3.14;
  bool b = false;
  string s;

  cout << sizeof(i) << "\n";
  cout << sizeof(c) << "\n";
  cout << sizeof(d) << "\n";
  cout << sizeof(b) << "\n";
  cout << sizeof(s) << "\n";

  cout << sizeof(int) << "\n";
  cout << sizeof(char) << "\n";
  cout << sizeof(double) << "\n";
  cout << sizeof(bool) << "\n";
  cout << sizeof(string) << "\n";


  return 0;
}

****************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
  /*int i = 32;
  auto i = 32;*/
  //vector<int> v = {3, 14, 15};
  vector<int> v;
  
  
  //int n;
  size_t n;
  cin >> n;
  v.resize(n)
  //int x;
  for (size_t i = 0; i != n; ++i) {
    //cin >> x;
    cin >> v[i];
    //v.push_back(x);
  }

  //for (int x : v)
    //cout << x << " ";
  //cout << "\n";
}

*****************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
  /*vector<int> v;
  size_t n;
  cin >> n;

  cout << "Empty vector;\n";
  cout << v.capacity() << endl;

  v.resize(n);
  cout << v.capacity() << endl;
  for (size_t i; i != n; ++i) {
    cin >> v[i];
  }
  cout << v.size() << "\n";
  //v.empty();
  v.front() = 14;
  v.back() = 1;

  v.push_back(1);
  cout << v.capacity() << endl;
  v.pop_back();*/

  vector<int> v = {1, 2, 3};
  for (int x : v)
    cout << x << " ";
  cout << endl;
  v.erase(v.begin());
  v.insert(v.begin() + 1, 42); //v.end()
  *v.begin() = 325;
  
  //разные способы вывода
  for (int x : v)
    cout << x << " ";
  cout << endl;
  
  for (size_t i = 0; i != v.size(); ++i)
    cout << v[i] << " ";
  cout << "\n";

  for (auto it = v.begin();
      it != v.end();
      ++it)
    cout << *it << " ";
  cout << "\n";
}

**************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  size_t n;
  cin >> n;

  for (size_t i = 0; i != n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  {
    vector<int> v;
    v.resize(n);
    for (size_t i = 0; i != n; ++i)
      cin >> v[i];
  }
  {
    vector<int> v;
    v.reserve(n);
    for (size_t i = 0; i != n; ++i) {
      int x;
      cin >> x;
      v.push_back(x);
    }
  }
}

***************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> v;
  string s;
//  while (getline(cin, s))
  //  v.push_back(s);

 // for (auto s : v)
   // cout << s << "\n";

  vector<vector<int>> matrix;
  size_t m, n;
  cin >> m >> n;
  matrix.resize(m);
  for (size_t i = 0; i != m; ++i) {
    matrix[i].resize(n);
    for (size_t j; j != n; ++j) {
      matrix[i][j] = i + j;             // matrix.at(i).at(j)
    }
  }

  for (auto row : matrix) {
    for (auto elem : row)
      cout << elem << "\t";
    cout << "\n";
  }
}

