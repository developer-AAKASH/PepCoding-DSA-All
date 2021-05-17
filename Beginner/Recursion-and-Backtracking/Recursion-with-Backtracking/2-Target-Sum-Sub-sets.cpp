#include <bits/stdc++.h>

using namespace std;

void pGetAllTargetSumSequence( int currentIndex, int currentSum, const int targetSum, vector< int > resultSoFar, vector< vector< int > > &result, vector< int > &nums ){
    
    cout << endl << currentIndex << " " << currentSum << endl;

    int size = nums.size();

    // Negative base-cases...
    if( currentSum > targetSum ){
        cout << endl << "greater current sum...." << currentSum;
        return;
    }

    if( currentIndex == size ){
        if( currentSum == targetSum ){
            result.push_back( resultSoFar );
        }
        return;
    }


    // Positive base case
    if( currentSum == targetSum ){
        result.push_back( resultSoFar );
        return;
    }

    // include...
    cout << endl << "include...";
    resultSoFar.push_back( nums[ currentIndex ] );
    pGetAllTargetSumSequence( currentIndex + 1, currentSum + nums[ currentIndex ], targetSum, resultSoFar, result, nums );
    resultSoFar.pop_back();

    // exclude...
    cout << endl << "exclude...";
    pGetAllTargetSumSequence( currentIndex + 1, currentSum, targetSum, resultSoFar, result, nums );

}

int main(){
    int size;
    cout << "Enter size: " << endl;
    cin >> size;

    vector< int > nums( size );

    cout << "Enter " << size << " numbers: " << endl;
    for( int i = 0; i < size; i++ ){
        cin >> nums[i];
    }

    cout << flush;

    cout << "Enter target-sum: " << endl;
    int targetSum = 0;
    cin >> targetSum;

    cout << endl << "after taking target-sum.." << endl;

    vector< int > resultSoFar;
    vector< vector< int > > result;

    pGetAllTargetSumSequence( 0, 0, targetSum, resultSoFar, result, nums );
    
    for( int i = 0; i < result.size(); i++ ){
        for( int j = 0; j < result[i].size(); j++ ){
            cout << result[i][j] << ", ";
        }
        cout << "." << endl;
    }

    return 0;
}