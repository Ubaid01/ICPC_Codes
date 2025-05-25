#include<iostream>
#include<vector>
using namespace std;

int main(){
    int cases, threshold;
    cin >> cases;
    cin >> threshold;
    vector<vector<int>> res(cases);
    for (int i = 0;i < cases;i++){
        int n, x, diff_prv, y, diff_curr;
        cin >> n;
        if (n > 2){
            cin >> x;
            cin >> y;
            diff_prv = abs(y - x);
            for (int j = 2;j < n;j++){
                cin >> x;
                diff_curr = abs(y - x);
                if (abs(diff_curr - diff_prv) >= threshold)
                    res[i].push_back(1);
                else res[i].push_back(0);
                diff_prv = diff_curr;
                y = x;
            }
        }
    }
    for (int i = 0;i < res.size();i++){
        for (int j = 0;j < res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}