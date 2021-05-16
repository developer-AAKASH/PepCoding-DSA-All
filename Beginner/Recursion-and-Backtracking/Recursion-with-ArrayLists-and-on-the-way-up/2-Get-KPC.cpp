#include <bits/stdc++.h>

using namespace std;

string getNumStr( const char num ){
    
    // cout << endl << "From getNumStr " << num;
    if( num == '1' ){
        return "abc";
    }
    else if( num == '2' ){
        return "def";
    }
    else if ( num == '3' ){
        return "ghi";
    }
    else if( num == '4' ){
        return "jkl";
    }
    else if( num == '5' ){
        return "mno";
    }
    else if ( num == '6' ){
        return "pqrs";
    }
    else if ( num == '7' ){
        return "tu";
    }
    else if ( num == '8' ){
        return "vwx";
    }
    else if ( num == '9' ){
        return "yz";   
    }
    else if ( num == '0' ){
        return ".;";
    }
    return "";
}

void printAllKPC( string &num, int currentIndex, string &output ){
    int size = num.size()-1;

    if( currentIndex == size ){
        string word = getNumStr( num[currentIndex ] );

        for ( int i = 0; i < word.size(); i++){
            cout << endl << output + word[i];
        }
        
        return;
    }

    string word = getNumStr( num[currentIndex ] );
    for ( int i = 0; i < word.size(); i++){
        string temp = output + word[i];
        printAllKPC( num, currentIndex + 1, temp );
    }

    return;
}

vector< string > getKPC( string &num, int currentIndex ){
   
    if( currentIndex == num.size()-1 ){
        string word = getNumStr( num[currentIndex ] );
        
        vector< string > result;
        
        cout << endl << num << " " << currentIndex << " " << word << endl;
        
        for( int i = 0; i < word.size(); i++ ){
            result.push_back( word.substr( i, 1 ) );
        }
        return result;
    }
    
    
    string words = getNumStr( num[ currentIndex ] );
    vector< string > subResult = getKPC( num, currentIndex + 1 );
    
    cout << endl << num << " " << currentIndex << " " << words << endl;
    
    int wSize = words.size(), rSize = subResult.size();
    
    vector< string > result;
    
    for( int i = 0; i < wSize; i++ ){
        for( int j = 0; j < rSize; j++ ){
            result.push_back( words[i] + subResult[j] );
        }
    }
    
    return result;
}

int main(){
    
    string num;
    cin >> num;
    
    // vector< string > result = getKPC( num, 0 );
    
    // cout << num << endl;
    
    // cout << endl << "[";
    
    // for( int i = 0; i < result.size(); i++ ){
    //     cout << result[i] << ", ";
    // }

    string output = "";
    printAllKPC( num, 0, output );
    
    // cout << "]";
    return 0;
}