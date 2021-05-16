#include <bits/stdc++.h>

using namespace std;

void pGetAllPathToMaze( int r, int c, const int row, const int col, string current, vector< vector< int > > &maze, vector< vector< bool > > &visited ){

    // cout << endl << r << " " << c << " " << row << " " << col << endl;

    if( r > row || c > col || r < 0 || c < 0 || maze[ r ][ c ] == 1 || visited[ r ][ c ] == true ){
        return;
    }

    if( ( r == row ) && ( c == col ) ){
        // result.push_back( current );
        cout << current << endl;
        return;
    }

    visited[ r ][ c ] = true;

    pGetAllPathToMaze( r - 1, c, row, col, current + "t", maze, visited );
    pGetAllPathToMaze( r , c - 1, row, col, current + "l", maze, visited );
    pGetAllPathToMaze( r + 1, c, row, col, current + "d", maze, visited );
    pGetAllPathToMaze( r , c + 1, row, col, current + "r", maze, visited );

    visited[ r ][ c ] = false;

    return;
}

int main(){
    int row, col;
    cin >> row >> col;

    vector< vector< int > > maze( row, vector< int >( col ) );
    vector< vector< bool > > visited( row, vector< bool >( col, false ) );

    for( int i = 0; i < row; i++ ){
        for( int j = 0; j < col; j++ ){
            cin >> maze[i][j];
        }
    }

    string current = "";
    pGetAllPathToMaze( 0, 0, row-1, col-1, current, maze, visited );

    return 0;
}