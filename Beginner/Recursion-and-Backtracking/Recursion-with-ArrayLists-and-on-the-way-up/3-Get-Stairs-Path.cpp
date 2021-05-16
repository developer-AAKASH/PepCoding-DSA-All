#include <bits/stdc++.h>

using namespace std;

void getStairsPath( int n, string &currentPath, vector< string > &result ){
    if( n == 0 ){
        result.push_back( currentPath );
    }

    for( int i = 1; i <= 3; i++ ){
        if( ( n - i ) >= 0 ){
            string temp = currentPath + to_string(i);
            getStairsPath( n-i, temp, result );
        }
    }
}

void printAllStairsPath( int n, string &outputPath ){
    if( n == 0 ){
        cout << endl << outputPath;
        return;
    }

    for( int i = 1; i <= 3; i++ ){
        if( ( n - i ) >= 0 ){
            string temp = outputPath + to_string(i);
            printAllStairsPath( n-i, temp );
        }
    }
}

int main(){

    int n;
    cin >> n;

    string currentPath = "";
    // vector< string > result;
    // getStairsPath( n, currentPath, result );

    // cout << "[";
    // int i = 0;
    // for( i = 0; i < result.size()-1; i++ ){
    //     cout << result[i] << ", ";
    // }
    
    // cout << result[i] << "]";

    printAllStairsPath( n, currentPath );
    
    return 0;
}