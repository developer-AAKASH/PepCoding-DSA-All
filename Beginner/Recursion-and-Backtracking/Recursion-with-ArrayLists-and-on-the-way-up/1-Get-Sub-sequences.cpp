#include <bits/stdc++.h>

using namespace std;

// It is very optimized solution, but the problem with this is, we can't store the answer so it works in the scenerio where we just want to print the answer, and we dont want to store the answer, at that situation, this solution is the most suitable solution.....
void printAllSubSequences( int currentIndex, const string &input, string &output ){
    int size = input.size();

    // cout << endl << currentIndex << " " << size << " " << input << " " << output << endl;

    if( currentIndex > size )
        return;

    if( currentIndex == size ){
        cout << endl << output;
    }

    string temp;
    
    temp = output + input[ currentIndex ];
    printAllSubSequences( currentIndex + 1, input, temp );
    temp = output + "";
    printAllSubSequences( currentIndex + 1, input, output );
}

// This solution uses the same approch as "printAllSubSequence", but, it also use the external storage for storing the data at the same time, but here the catch is it uses the storage by references, that means, through out the all the recursive calls, it uses single copy of the storage so it is the most optimal solution in context of space...
void pGetAllSubSequences( int currentIndex, const string &input, string &current, vector< string > &result ){
    int size = input.size();

    // cout << endl << currentIndex << " " << size << " " << input << " " << output << endl;

    if( currentIndex > size )
        return;

    if( currentIndex == size ){
        // cout << endl << output;
        result.push_back( current );
    }

    string temp;
    
    temp = current + input[ currentIndex ];
    pGetAllSubSequences( currentIndex + 1, input, temp, result );
    pGetAllSubSequences( currentIndex + 1, input, current, result );
}

// This solution is user and reading friendly solution for beginners and we have used the things by reference, but originally it wasnt by reference so this is not so optimal solution but for learning the recursion and backtracking, this is a very good step/solution to start with....
vector< string > getAllSubSequences( int currentIndex, const string &input ){
    if( currentIndex == input.size() ){
        vector< string > result;
        result.push_back("");

        return result;
    }

    vector< string > include = getAllSubSequences( currentIndex + 1, input );
    
    vector< string > result;
    for( int i = 0; i < include.size(); i++ ){
        result.push_back( include[i] );
        result.push_back( input[ currentIndex ] + include[i] );
    }

    return result;
}

int main(){
    string input;
    cin >> input;

    // cout << endl << input << endl;
    string output = "";
    // printAllSubSequences( 0, input, output );

    // vector< string > result;
    // pGetAllSubSequences( 0, input, output, result );
    // cout << endl << result.size() << endl;
    // input-> abcdefghijklmnopqrstuvwxyz output Size->6,71,08,864

    vector< string > result = getAllSubSequences( 0, input );

    for( int i = 0; i < result.size(); i++ ){
        cout << endl << result[i];
    }
    
    cout << endl;

    return 0;
}