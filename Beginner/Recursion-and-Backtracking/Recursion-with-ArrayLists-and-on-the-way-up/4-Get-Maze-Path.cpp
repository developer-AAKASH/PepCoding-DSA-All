#include <bits/stdc++.h>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

void recursion( int srcR, int srcC, const int destR, const int destC, string current, vector< string > &result ){

    // cout << endl << srcC << " " << srcR << " " << current << endl;

    // If, both sourceRow and source column is out of bound then we just simply return from here, as ther are out of the Maze...
    if( srcR > destR and srcC > destC )
        return;

    // If, sourceRow and sourceColumn both is equal to destinationRow and destination column, then we add the current notation/path to result set as thats the path which we followed to reach the destination from the source....
    if( srcR == destR and srcC == destC ){
        result.push_back( current );
        return;
    }

    // But if, only sourceRow is out of bound, then we can move only in horizontal direction, not in vertical so we are restricting the same....
    if( srcR > destR ){
        recursion( srcR, srcC + 1, destR, destC, current + "h", result );
    }

    // But if, only sourceCol is out of bound, then we can move only in vertical direction, not in horizontal so we are restricting the same....
    else if( srcC > destC ){
        recursion( srcR + 1, srcC, destR, destC, current + "v", result );    
    }
    // And if both are within the range, then we can traverse in both the direction, so in that case we traverse to both the direction....
    else{
        recursion( srcR, srcC + 1, destR, destC, current + "h", result );
        recursion( srcR + 1, srcC, destR, destC, current + "v", result );
    }
}

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    vector< string > result;
    string current = "";

    recursion( sr, sc, dr, dc, current, result );

    return result;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}

void printAllMazePath( int srcR, int srcC, const int destR, const int destC, string &mazePath ){
    if( srcR > destR && srcC > destC ){
        return;
    }

    if( srcR == destR && srcC == destC ){
        cout << endl << mazePath;
    }

    if( srcR > destR ){
        string tmp = mazePath + "h";
        printAllMazePath( srcR, srcC + 1, destR, destC, tmp );
    }

    else if( srcC > destC ){
        string tmp = mazePath + "v";
        printAllMazePath( srcR + 1, srcC, destR, destC, tmp );    
    }
    else{
        string tmp = mazePath + "h";
        printAllMazePath( srcR, srcC + 1, destR, destC, tmp );
        tmp = mazePath + "v";
        printAllMazePath( srcR + 1, srcC, destR, destC, tmp );
    }
}

int main() {
    int n,m; cin >> n >> m;
    // vector<string> ans = getMazePaths(0,0,n-1,m-1);
    // display(ans);

    string output = "";
    printAllMazePath( 0, 0, n-1, m-1, output );

    return 0;
}