#include <bits/stdc++.h>

using namespace std;

void getPaths( int row, int col, const int dRow, const int dCol, string current, vector< string > &result ){
    // cout << endl << row << " " << col << endl;

    if( row > dRow && col > dCol )
        return;

    if( row == dRow && col == dCol ){
        result.push_back( current );
        return;
    }
    
    if( row > dRow ){
        // cout << "row out of bound..." << endl;
        for( int c = 1; c <= dCol-col; c++ ){
            string temp = current + "h" + to_string(c);
            getPaths( row, col + c, dRow, dCol, temp, result );
        }
    }
    
    else if( col > dCol ){
        // cout << "col out of bound..." << endl;
        for( int r = 1; r <= dRow-row; r++ ){
            string temp = current + "v" + to_string(r);
            getPaths( row + r, col, dRow, dCol, temp, result );
        }
    }

    else{
        // cout << "all in range..." << endl;
        for( int c = 1; c <= dCol-col; c++ ){
            string temp = current + "h" + to_string(c);
            getPaths( row, col + c, dRow, dCol, temp, result );
        }
        for( int r = 1; r <= dRow-row; r++ ){
            string temp = current + "v" + to_string(r);
            getPaths( row + r, col, dRow, dCol, temp, result );
        }
        for( int d = 1; d <= dRow-row && d <= dCol-col; d++ ){
            string temp = current + "d" + to_string(d);
            getPaths( row + d, col + d, dRow, dCol, temp, result );
        }
    }
}

void printAllMazePathWithJump( int row, int col, const int dRow, const int dCol, string &output ){
    
    if( row > dRow && col > dCol )
        return;

    if( row == dRow && col == dCol ){
        cout << endl << output;
        return;
    }
    
    if( row > dRow ){
        cout << "row out of bound..." << endl;
        for( int c = 1; c <= dCol-col; c++ ){
            string temp = output + "h" + to_string(c);
            printAllMazePathWithJump( row, col + c, dRow, dCol, temp );
        }
    }
    
    else if( col > dCol ){
        cout << "col out of bound..." << endl;
        for( int r = 1; r <= dRow-row; r++ ){
            string temp = output + "v" + to_string(r);
            printAllMazePathWithJump( row + r, col, dRow, dCol, temp );
        }
    }

    else{
        cout << "all in range..." << endl;
        for( int c = 1; c <= dCol-col; c++ ){
            string temp = output + "h" + to_string(c);
            printAllMazePathWithJump( row, col + c, dRow, dCol, temp );
        }
        for( int r = 1; r <= dRow-row; r++ ){
            string temp = output + "v" + to_string(r);
            printAllMazePathWithJump( row + r, col, dRow, dCol, temp );
        }
        for( int d = 1; d <= dRow-row && d <= dCol-col; d++ ){
            string temp = output + "d" + to_string(d);
            printAllMazePathWithJump( row + d, col + d, dRow, dCol, temp );
        }
    }
}

int main(){
    int row, col;
    cin >> row >> col;

    // vector< string > result;

    // // cout << endl << row << " " << col << endl;

    // getPaths( 0, 0, row-1, col-1, "", result );

    // cout << "[";
    // for(int i = 0;i < result.size();i++){
    //     cout << result[i];
    //     if(i < result.size() -1) cout << ", ";
    // }
    
    // cout << "]"<<endl;

    string output = "";
    printAllMazePathWithJump( 0, 0, row-1, col-1, output );
    return 0;
}