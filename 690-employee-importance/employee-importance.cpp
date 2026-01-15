/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;

    int dfs(int id) {
        Employee* e = mp[id];
        int sum = e->importance;
        for (int sub : e->subordinates) {
            sum += dfs(sub);
        }
        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for (auto e : employees) {
            mp[e->id] = e;
        }
        return dfs(id);
    }
};
