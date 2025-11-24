#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class solution{
    int res = 0;
    void solve(vector<vector<int>>& people_dept, unordered_set<int>& used_dept, int idx){// backtracking func
        if (idx == people_dept.size()){
            res++;
            return;
        }
        for (int i = 0;i < people_dept[idx].size();i++){
            if (used_dept.find(people_dept[idx][i]) == used_dept.end()){
                used_dept.insert(people_dept[idx][i]);
                solve(people_dept, used_dept, idx + 1);
                used_dept.erase(people_dept[idx][i]);
            }
        }
    }
public:
    int find_combinations(vector<vector<int>>& people_dept){
        res = 0;
        unordered_set<int> used_dept;
        solve(people_dept, used_dept, 0);
        return res;
    }
};

int main(){
    solution s;
    int cases, people, no_of_dept;
    cin >> cases;
    vector<int> res(cases, 0);
    for (int i = 0;i < cases;i++){
        cin >> people;
        vector<vector<int>> people_dept(people);
        for (int j = 0;j < people;j++){
            cin >> no_of_dept;
            for (int k = 0;k < no_of_dept;k++){
                int x;
                cin >> x;
                people_dept[j].push_back(x);
            }
        }
        res[i] = s.find_combinations(people_dept);
    }
    for (int i = 0;i < cases;i++){
        cout << res[i] << endl;
    }
    return 0;
}