// 8-queens Validator
// Cody Larison
// 1/9/18

// Given an array of 8 integers between 1 and 8, 
// determine whether it represents a valid 8 
// queens solution.

/* Example:
	qcheck({4, 2, 7, 3, 6, 8, 5, 1}) => true
	qcheck({2, 5, 7, 4, 1, 8, 6, 3}) => true
	qcheck({5, 3, 1, 4, 2, 8, 6, 3}) => false   (b3 and h3 are on the same row)
	qcheck({5, 8, 2, 4, 7, 1, 3, 6}) => false   (b8 and g3 are on the same diagonal)
	qcheck({4, 3, 1, 8, 1, 3, 5, 2}) => false   (multiple problems)
*/

#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

// no queens can be in same row or diagonal,
// 8 must be placed on 8x8 board to be valid.

bool qcheck(array<int,8> queens);
int main(){
	array<bool,5> results;
	
	array<int,8> test1 = {4,2,7,3,6,8,5,1};
	array<int,8> test2 = {2,5,7,4,1,8,6,3};
	array<int,8> test3 = {5,3,1,4,2,8,6,3};
	array<int,8> test4 = {5,8,2,4,7,1,3,6};
	array<int,8> test5 = {4,3,1,8,1,3,5,2};
	
	results[0] = qcheck(test1);
	results[1] = qcheck(test2);
	results[2] = qcheck(test3);
	results[3] = qcheck(test4);
	results[4] = qcheck(test5);

	// testing 
	int testnum = 5;
	array<string,5> solArray = {"true", "true", "false", "false", "false"};

	for(int i=0; i<testnum; i++){
		cout << "Test " << (i+1) << "\nexpected: " << solArray[i] << "\nresult: " << boolalpha << results[i] << "\n\n";
	}
	
	return 0;
}

bool qcheck(array<int,8> queens){
	bool checkStatus = true;
	// row check
	array<int,8> sortQueens = queens;
	sort(sortQueens.begin(), sortQueens.end());
	for(int i=0; i<sortQueens.size()-1; i++){
		if(sortQueens[i] == sortQueens[i+1]){
			return (false);
		}
	}
	
	// diagonal check

	//	if(queens[0]+1 == queens[1]
	//	if(queens[0]-1 == queens[1]
	//	if(queens[0]+2 == queens[2] 
	//	if(queens[0]-2 == queens[2] 
	//		...
	//	if(queens[0]+7 == queens[7] 
	//	if(queens[0]-7 == queens[7]


	//	if(queens[1]-1 == queens[2] // has already been checked in queens[0] cases
	//	if(queens[1]+1 == queens[2]
	//	if(queens[1]+6 == queens[7]
	//	if(queens[1]-6 == queens[7]

	//	formula:
	//	if(queens[index](+-)(checkIndex - index) ==  queens[checkIndex] 
	//	
	int checkIndex = 0;
	for(int i=0; i<queens.size(); i++){
		checkIndex = queens.size()-1;
		while(checkIndex > i){
			if( (queens[i]+(checkIndex - i)) ==  queens[checkIndex] ){
				return(false);
			}
			else if( (queens[i]-(checkIndex - i)) ==  queens[checkIndex] ){
				return(false);
			}
			checkIndex--;
		}
	}

	
	return(true);
}

