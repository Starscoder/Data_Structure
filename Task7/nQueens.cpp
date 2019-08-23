class Solution {
public:
      vector<vector<string>> solveNQueens(int n) {
            N= n;
            c.resize(n);
            queenFun(0);
            return t;
      }
      void queenFun(int n) {
          if (n == N) {
              vector<string> temp;
              for (int i = 0; i < N; ++i) {
                  string str = "";
                  for (int j = 0; j < c[i]; ++j) {
                    str += ".";
                  }
                  str += "Q";
                  for (int k = 0; k < N - c[i] -1; ++k) {
                    str += ".";
                  }
                temp.push_back(str);
            }
            t.push_back(temp);
          } else {
            for (int i = 0; i < N; ++i) {
              c[n] = i;
              bool falg = true;
              for (int j = 0; j < n; ++j) {
                if (c[j] == c[n] || c[n] - n == c[j] - j || c[n] + n == c[j] + j) {
                  falg = false;
                  break;
                }
              }
              if (falg)
                queenFun(n + 1);
            }
      }
}
private:
    vector<int> c;
    int num = 0,N;
    vector<vector<string>> t;
};
