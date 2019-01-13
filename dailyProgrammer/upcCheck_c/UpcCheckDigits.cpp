/*
Author:			Cody Larison 
Date Created:	12/21/18

this problem is from the subreddit dailyprogramming
the task is to create a function that will compute 
and verify the checksum on a upc code. 
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void 	upcChecksum(string upc);
string	upcValidate(string upc);

int main(int argc, char ** argv){
	string 	usr_resp;
	string 	upc;
	int 	upc_int = -1;

	if(argc > 1){
		upc = argv[1];
		cout 	<< "You specified the following UPC: " 
				<< argv[1] << ", do you wish to change"
				<< "this? (y/n)" << endl;
		cin >> usr_resp;
		transform(usr_resp.begin(), usr_resp.end(), usr_resp.begin(), ::tolower);
		if(usr_resp == "y" ){
			cout << "Enter a new UPC" << endl;
			cin >> upc;
		}
	}
	upc = upcValidate(upc);
	
	
	upcChecksum(upc);
	return 0;
}

string upcValidate(string upc){
	if(upc.empty())
	{
		cout << "Please enter a upc. " << endl;
		cin >> upc;
	}
	while(upc.length() != 12)
	{
		cout << "You specified an invalid UPC, please enter another." << endl;
		cin >> upc;
	}
	return (upc);
}

void upcChecksum(string upc){
	/* computes the checksum of the UPC	*/

	int odd_array[16];				
	int even_array[16];
	int odd_sum			= 0;
	int even_sum		= 0;

	/* generate even and odd position upc arrays */
	int 	oi =0, 
			ei = 0; 			// odd and even indexes
	for(int i=0; i<11; i++){ // only want first 11 digits for calculations
		if (i % 2){
			even_array[ei] = (int)upc[i]-'0';
			ei++;
		}
		else{
			odd_array[oi] = (int)upc[i]-'0';
			oi++;
		}
	}

	/* STEP 1: Sum the digits at odd numbered positions */
	for(int i=0; i<6; i++){
		odd_sum += odd_array[i];
	}

	/* STEP 2: Multiply result from step 1 by 3 */
	int stp2 = odd_sum * 3;

	/* STEP 3: Take the sum of digits at even-numbered 
	   positions (2nd, 4th, 6th, ..., 10th) in the 
	   original number, and add this sum to the result 
	   from step 2.
	*/
	for(int i=0; i<6; i++){
		even_sum += even_array[i];
	}
	int stp3 = even_sum + stp2;

	/* STEP 4: Calculate step 3 mod 10 */
	int stp4 = stp3 % 10;
	
	/* STEP 5: If stp4 is not 0, subtract stp4 from
	   10 to get the check digit
	*/
	int check_digit = 0;
	if(stp4 != 0){
		check_digit = 10 - stp4;
	}
	
	cout << "Calculated check digit: " << check_digit << endl;
	cout << "Actual check digit: " << upc[11] << endl;

	if(check_digit == (int)(upc[11]-'0')){
		cout << "\nValid UPC" << endl;
	}
	else 
		cout << "\nInvalid UPC" << endl;
	return ;
}
