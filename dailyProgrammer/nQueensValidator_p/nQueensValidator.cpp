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

using namespace std;

// no queens can be in same row or diagonal,
// 8 must be placed on 8x8 board to be valid.

int main(){
	// add & subtract index diff for diagonals,
	// rows check number, columns inherently solved
	// each entry need be only checked with subsequent entries?
	 

	return 0;
}

void qcheck(int[8] queens){
	bool checkStatus = true;
	// row check
	int[8] sortQueens = queens;
	sort(sortQueens.begin(), sortQueens.end());
	for(int i=0; i<sortQueens.size()-1; i++){
		if(sortQueens[i] == sortQueens[i+1]){
			checkStatus = false;
			break;
		}
	}
	
//	if(queens[0] == (queens[1] + 1))
//	if(queens[0] == (queens[1] - 1))
//	if(queens[0] == (queens[2] + 2))
//	if(queens[0] == (queens[2] - 2))
//		...
//	if(queens[0] == (queens[8] + 8))
//	if(queens[0] == (queens[8] - 8))


//	if(queens[1] == (queens[0] - 1)) // has already been checked in queens[0] cases
//	if(queens[1] == (queens[2] + 1))
//	if(queens[1] == (queens[2] - 1))
//	if(queens[1] == (queens[8] + 7))
//	if(queens[1] == (queens[8] - 7))

//	formula:
//	if(queens[index] == ( queens[checkIndex](+/-)(checkIndex - index) ) )
//	
//	for(int i=0; i<queens.size(); i++){
//		index = i;
//		checkIndex = queens.size();
//		while(checkIndex > index){
//			if(queens[index] == ( queens[checkIndex]+(checkIndex - index) ) ){
//				// set check status to false & return
//			}
//			checkIndex--;
//		}
//	}
//	if(checkStatus){
//		// do diagonal check
//		for(int i=0; i<queens.size(); i++){
//			// refine logic here
//			if((queens[i]+i) = queens[i+1]){
//				checkStatus = false;
//			}
//			if((queens[i]-i) == queens[i+1]){

//			}
//		}
	}
	
	return;
}

