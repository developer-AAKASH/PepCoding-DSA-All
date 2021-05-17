#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > getKnightMoves( int row, int col ){
    vector< vector< int > > moves( 8, vector< int > ( 2, 0 ) );

    moves[0][0] = row-2; moves[0][1] = col+1;
    moves[1][0] = row-1; moves[1][1] = col+2;
    moves[2][0] = row+1; moves[2][1] = col+2;
    moves[3][0] = row+2; moves[3][1] = col+1;
    moves[4][0] = row+2; moves[4][1] = col-1;
    moves[5][0] = row+1; moves[5][1] = col-2;
    moves[6][0] = row-1; moves[6][1] = col-2;
    moves[7][0] = row-2; moves[7][1] = col-1;

    return moves;
}

void knightTour( int r, int c, const int row, const int col, vector< vector< int > > &board, int moveNum ){

    // cout << endl << r << " " << c << " " << moveNum << endl;

    // cout << endl << moveNum << " " << ( row * row ) << endl;


    if( r < 0 || r >= row || c < 0 || c >= col || board[ r ][ c ] > 0 ){
        return;
    }

    else if( moveNum == ( row * row ) ){
    // cout << endl << moveNum << " " << ( row * row ) << endl;
        board[ r ][ c ] = moveNum;

        for( int i = 0; i < row; i++ ){
            for( int j = 0; j < col; j++ ){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        board[ r ][ c ] = 0;

        return;
    }
        
    // cout << endl << moveNum << endl;
    
    board[ r ][ c ] = moveNum;

    vector< vector< int > > moves = getKnightMoves( r, c );
    // cout << endl << moves.size() << endl;

    for( int i = 0; i < 8; i++ ){
        // cout << endl << moves[i][0] << " " << moves[i][1] << endl;
        knightTour( moves[i][0], moves[i][1], row, col, board, moveNum + 1 );
    }

    board[ r ][ c ] = 0;
}

int main(){
    int size, row, col;
    cin >> size >> row >> col;

    vector< vector< int > > board( size, vector< int > ( size , 0 ) );

    // cout << endl << size << " " << row << " " << col << endl;

    knightTour( row, col, size, size, board, 1 );

    return 0;
}