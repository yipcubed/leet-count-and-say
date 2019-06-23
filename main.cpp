#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    void getCountAndIndex(const string& s, int start, int& count) {
      char c = s[start];
      while (c == s[start] && start < s.length()) {
        ++count;
        ++start;
      }
    }

    string readNumber(const string& str) {
      stringstream ss;
      for (int index = 0; index < str.length(); ) {
        int count = 0;
        getCountAndIndex(str, index, count);
        ss << count << str[index];
        index += count;
      }

      return ss.str();
    }

    string countAndSay(int n) {
        if (n == 1)
          return "1";
        else if (n == 2)
          return "11";
        else {
          return readNumber(countAndSay(n - 1));
        }
    }
};

void test1() {
  Solution S;
  for (int i = 1; i < 10; ++i) {
    cout << i << ". " << S.countAndSay(i) << endl;
  }
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}

