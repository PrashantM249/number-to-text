#include <iostream> 
#include <sstream>
using namespace std; 

string one[] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " }; 

string ten[] = { "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " }; 

// Function to print a given number in words 
string numToWords(int n, string s)  { 
	string str = ""; 
	// divide if n is more than 19
	if (n > 19) {
		str += ten[n / 10] + one[n % 10]; 
	} else {
		str += one[n]; 
	}

	// if n is non-zero 
	if (n) {
		str += s; 
	}

	return str; 
} 

// Function to print a given number in words 
string convertToWords(long n) { 
	string out; 

	out += numToWords(((n / 100000) % 100), "lakh "); 

	out += numToWords(((n / 1000) % 100), "thousand "); 

	out += numToWords(((n / 100) % 10), "hundred "); 

	if (n > 100 && n % 100) {
		out += "and "; 
	}

	out += numToWords((n % 100), ""); 

	return out; 
} 

// Returns true if str is a number or not
bool isNumber(string str) {
	int i = 0, j = str.length() - 1; 

    // Check whitespaces 
	while (i < str.length() && str[i] == ' ') {
		i++; 
	}
	while (j >= 0 && str[j] == ' ') {
		j--; 
	}

	if (i > j) {
		return 0; 
	}

    // if string is of length 1 and the only 
    // check string is not a digit 
	if (i == j && !(str[i] >= '0' && str[i] <= '9')) {
		return 0; 
	}

    // If the 1st char is not '+', '-', '.' or digit 
	if (str[i] != '.' && str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')) {
		return 0; 
	}

    // To check if a '.' or 'e' is found in given 
    // string. We use this flag to make sure that 
    // either of them appear only once. 
	bool flagDotOrE = false; 

	for (i; i <= j; i++) { 
        // If any of the char does not belong to 
        // {digit, +, -, ., e} 
		if (str[i] != 'e' && str[i] != '.' && str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')) {
			return 0; 
		}

		if (str[i] == '.') { 
            // checks if the char 'e' has already 
            // occurred before '.' If yes, return 0. 
			if (flagDotOrE == true) {
				return 0; 
			}

            // If '.' is the last character. 
			if (i + 1 > str.length()) {
				return 0; 
			} 

            // if '.' is not followed by a digit. 
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9')) {
				return 0; 
			}
		} else if (str[i] == 'e') { 
            // set flagDotOrE = 1 when e is encountered. 
			flagDotOrE = true; 

            // if there is no digit before 'e'. 
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9')) {
				return 0; 
			}

            // If 'e' is the last Character 
			if (i + 1 > str.length()) {
				return 0; 
			}

            // if e is not followed either by 
            // '+', '-' or a digit 
			if (str[i + 1] != '+' && str[i + 1] != '-'&& (str[i + 1] >= '0' && str[i] <= '9')) {				
				return 0; 
			}
		} 
	} 

        /* If the string skips all above cases, then  
        it is numeric*/
	return 1; 
}

// Main function
int main() { 
	string n; 
	char again = 'y';
	while(again == 'y' || again == 'Y') {

		cout << "Type a number: " << endl;
		cin >> n; 

		if(!isNumber(n)) {
			cout << "Please Enter Valid Number." << endl;
		} else {
			stringstream geek(n); 

			// The object has the value 12345 and stream 
			// it to the integer x 
			int x = 0; 
			geek >> x; 
			
			float getFloatVal = std::stof(n); 
			
			float getDecVal = getFloatVal - x;

	        int decVal = 0;
			if(getDecVal > 0) {
				//decimal next logic
				decVal = getDecVal * 100;
			}
			
			// convert given number in words 
			if(x == 0){
				cout << "Zero" << endl; 
			} else if(x >= 999999) {
				cout << "Please Enter number between 0 to 999999" << endl; 
			} else {
				cout << convertToWords(x); 			
				if(decVal > 0) {
				    cout << decVal << "/100 ONLY" << endl;
				} else {
					cout << endl;
				}
			}
		}

		cout << "Try Again (y/n): " << endl;
		cin >> again; 
		if(again != 'y' && again != 'Y') {
			cout << "Thank you!!! " << endl;
		}
	}
	
	return 0; 
} 
