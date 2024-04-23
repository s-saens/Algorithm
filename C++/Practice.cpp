#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef unordered_map<string, vector<string>> M;
typedef vector<vector<string>> T;

void init(M &ticketMap, T &tickets, int &cnt)
{
  for (auto t : tickets)
  {
    string key = t[0], value = t[1];
    if (ticketMap.find(key) == ticketMap.end())
    {
      ticketMap[key] = vector<string>();
    }
    ticketMap[key].push_back(value);
    cnt++;
  }

  for (auto &t : ticketMap)
  {
    sort(t.second.begin(), t.second.end());
  }
}

vector<string> answer;

bool dfs(string now, M ticketMap, int cnt)
{
  answer.push_back(now);
  if (cnt <= 0)
  {
    return true;
  }
  if (ticketMap[now].size() <= 0)
  {
    answer.pop_back();
    return false;
  }

  bool ret = false;

  for (int i = 0; i < ticketMap[now].size(); ++i)
  {
    M newMap = ticketMap;
    string next = ticketMap[now][i];
    newMap[now].erase(newMap[now].begin() + i);
    ret = dfs(next, newMap, cnt - 1);
    if (ret)
      break;
  }

  if (!ret)
  {
    answer.pop_back();
  }
  return ret;
}

vector<string> solution(T tickets)
{
  M ticketMap;
  int cnt = 0;
  init(ticketMap, tickets, cnt);

  dfs("ICN", ticketMap, cnt);

  return answer;
}

int main()
{
  vector<vector<string>> v = {{"ICN", "AAA"}, {"ICN", "CCC"}, {"CCC", "DDD"}, {"AAA", "BBB"}, {"AAA", "BBB"}, {"DDD", "ICN"}, {"BBB", "AAA"}};
  for (auto a : solution(v))
  {
    cout << a << ',';
  }
  return 0;
}