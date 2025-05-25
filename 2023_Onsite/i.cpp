#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class AgriYieldCalculator {
private:
    vector<double> arr;               
    vector<double> blocks;             
    int block_size;                    
    int n;                            
    
    double processBlock(vector<double>& values) {
        double result = 1.0;
        for( double &val : values )
            result *= sqrt(val);
        
        return result;
    }

public:
    AgriYieldCalculator(vector<double>& input) {
        arr = input;
        n = arr.size();
        block_size = floor( sqrt(n) );  // Component size
        int num_blocks = ceil( (double) n / block_size ) ;
        blocks.resize(num_blocks);
        
        // Preprocess blocks
        vector<double> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back(arr[i]);
            if((i + 1) % block_size == 0 || i == n - 1) {
                blocks[i / block_size] = processBlock(temp);
                temp.clear();
            }
        }
    }
    
    pair<double, int> query(int left, int right) {
        double result = 1.0;
        int component_hits = 0;
        
        int curr_block = -1;
        vector<double> temp;
        
        for(int i = left; i <= right; i++) {
            int block_idx = i / block_size;
            
            // If we're in a complete block
            if(curr_block != block_idx) {
                if(!temp.empty()) {
                    result *= processBlock(temp);
                    component_hits++;
                    temp.clear();
                }
                curr_block = block_idx;
            }
            temp.push_back(arr[i]);
            
            // If we've completed a block and it's not the last element
            if( (i + 1) % block_size == 0 && i != right ) {
                result *= processBlock(temp);
                component_hits++;
                temp.clear();
            }
        }
        
        if( !temp.empty() ) {
            result *= processBlock(temp);
            component_hits++;
        }
        
        return {result, component_hits};
    }
};

int main() {
    vector<double> crops = {2, 4, 1, 5, 3, 6, 7, 8};
    AgriYieldCalculator calculator(crops);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int left, right;
        cin >> left >> right;
        
        pair<double,int> result = calculator.query(left, right);
        cout << fixed << setprecision(3) << result.first << " " 
             << result.second << endl;
    }
    
    return 0;
}