// #include <iostream>
// #include <vector>
// using namespace std;

// template<typename T=int>
// class SegmentTree2D {
// private:
//     int rows, cols;
//     vector<vector<T>> matrix;
//     vector<vector<T>> segTree;
    
//     int left(int node) { return 2 * node + 1; }
//     int right(int node) { return 2 * node + 2; }
//     int mid(int l, int r) { return l + (r - l) / 2; }

//     void buildTreeRow(int node, int start, int end, int row, int treeRow) {
//         if (start == end) {
//             segTree[treeRow][node] = matrix[row][start];
//             return;
//         }
        
//         int m = mid(start, end);
//         buildTreeRow(left(node), start, m, row, treeRow);
//         buildTreeRow(right(node), m + 1, end, row, treeRow);
//         segTree[treeRow][node] = segTree[treeRow][left(node)] ^ segTree[treeRow][right(node)];
//     }

//     void buildTreeCol(int node, int start, int end, int colStart, int colEnd) {
//         if (start == end) {
//             buildTreeRow(0, colStart, colEnd, start, node);
//             return;
//         }

//         int m = mid(start, end);
//         buildTreeCol(left(node), start, m, colStart, colEnd);
//         buildTreeCol(right(node), m + 1, end, colStart, colEnd);
        
//         for (int i = 0; i < segTree[0].size(); i++) {
//             segTree[node][i] = segTree[left(node)][i] ^ segTree[right(node)][i];
//         }
//     }

//     T queryRow(int node, int start, int end, int left, int right, int treeRow) {
//         if (right < start || left > end) return 0;
//         if (left <= start && end <= right) return segTree[treeRow][node];
        
//         int m = mid(start, end);
//         return queryRow(2*node + 1, start, m, left, right, treeRow) ^ 
//                queryRow(2*node + 2, m + 1, end, left, right, treeRow);
//     }

//     T queryCol(int node, int start, int end, int rowStart, int rowEnd, 
//                int colStart, int colEnd) {
//         if (rowEnd < start || rowStart > end) return 0;
//         if (rowStart <= start && end <= rowEnd) 
//             return queryRow(0, 0, cols-1, colStart, colEnd, node);
        
//         int m = mid(start, end);
//         return queryCol(2*node + 1, start, m, rowStart, rowEnd, colStart, colEnd) ^ 
//                queryCol(2*node + 2, m + 1, end, rowStart, rowEnd, colStart, colEnd);
//     }

//     void updateRow(int node, int start, int end, int col, T val, int row, int treeRow) {
//         if (start == end) {
//             segTree[treeRow][node] = val;
//             return;
//         }
        
//         int m = mid(start, end);
//         if (col <= m)
//             updateRow(left(node), start, m, col, val, row, treeRow);
//         else
//             updateRow(right(node), m + 1, end, col, val, row, treeRow);
        
//         segTree[treeRow][node] = segTree[treeRow][left(node)] ^ segTree[treeRow][right(node)];
//     }

//     void updateCol(int node, int start, int end, int row, int col, T val) {
//         if (start == end) {
//             updateRow(0, 0, cols-1, col, val, row, node);
//             return;
//         }
        
//         int m = mid(start, end);
//         if (row <= m)
//             updateCol(left(node), start, m, row, col, val);
//         else
//             updateCol(right(node), m + 1, end, row, col, val);
        
//         for (int i = 0; i < segTree[0].size(); i++) {
//             segTree[node][i] = segTree[left(node)][i] ^ segTree[right(node)][i];
//         }
//     }

// public:
//     SegmentTree2D(vector<vector<T>>& mat) : matrix(mat) {
//         rows = mat.size();
//         cols = mat[0].size();
//         segTree.resize(4 * rows, vector<T>(4 * cols, 0));
//         buildTreeCol(0, 0, rows-1, 0, cols-1);
//     }

//     void update(int row, int col, T val) {
//         matrix[row][col] = val;
//         updateCol(0, 0, rows-1, row, col, val);
//     }

//     T query(int r1, int c1, int r2, int c2) {
//         return queryCol(0, 0, rows-1, r1, r2, c1, c2);
//     }
    
//     void displayMatrix() {
//         cout << "Matrix:" << endl;
//         for (vector<int>& row : matrix) {
//             for (T& val : row) cout << val << " ";
//             cout << endl;
//         }
//     }
// };

// int main() {
//     // vector<vector<int>> matrix = {
//     //     {0, 0, 192, 0, 0, 16, 0},
//     //     {12, 0, 24, 0, 48, 255, 96},
//     //     {0, 24, 0, 0, 64, 128, 0},
//     //     {0, 0, 48, 0, 128, 0, 0},
//     //     {48, 0, 0, 24, 0, 0, 255},
//     //     {0, 0, 255, 0, 48, 0, 0},
//     //     {0, 0, 0, 192, 0, 12, 32}
//     // };
    
//     // SegmentTree2D<int> tree(matrix);
    
//     // vector<vector<int>> queries = { 
//     //     {4, 1, 6, 2},
//     //     {6, 6, 6, 6},
//     //     {2, 3, 3, 4},
//     //     {0, 1, 1, 2},
//     //     {0, 0, 6, 6}
//     // };

//     // for(int i = 0; i < queries.size(); i++) {
//     //     int x1 = queries[i][1], y1 = queries[i][0];
//     //     int x2 = queries[i][3], y2 = queries[i][2];
//     //     cout << "Query #" << i + 1 << ": " << tree.query(x1, y1, x2, y2) << '\n';
//     // }

//     int n , m ;
//     cin >> n >> m ;
//     vector<vector<int>> arr( n , vector<int>( m ) ) ;
//     for( int i = 0 ; i < n ; i++ ) {
//         for( int j = 0 ; j < m ; j++ )
//             cin >> arr[i][j] ;
//     }
//     SegmentTree2D tree( arr ) ;

//     int q ;  cin >> q ;
//     for( int i = 0 ; i < q ; i++ ) {
//         int r1 , c1 , r2 , c2 ;
//         cin >> c1 >> r1 >> c2 >> r2 ;
//         cout << "Query #" << i + 1 << ": " <<  tree.query( r1 , c1 , r2 , c2 ) << '\n' ;
//     }

//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> mat(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> mat[i][j];
        }
    }
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(i != 0 && j != 0)    mat[i][j] ^= mat[i-1][j-1];
            if(i != 0)  mat[i][j] ^= mat[i-1][j]; 
            if(j != 0)  mat[i][j] ^= mat[i][j-1]; 
        }
    }
    int Q, c1, r1, c2, r2;
    cin >> Q;
    for(int i=1; i<=Q; i++) {
        cin >> c1 >> r1 >> c2 >> r2;
        int ans = mat[r2][c2];
        if(c1 != 0 && r1 != 0)  ans ^= mat[r1-1][c1-1];
        if(c1 != 0)     ans ^= mat[r2][c1-1];
        if(r1 != 0) ans ^= mat[r1-1][c2] ;
        cout << "Query #" << i << ": " << ans << '\n' ;
    }
    return 0 ;
}