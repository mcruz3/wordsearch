// Michelle Cruz
//Word Search Program


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int N=10,M=10;
void initialize(string userpuzzle[]);
void output(string puzzle[]);
bool search(string search[], string word, string &direction, int &row, int &column);

int main(void){
string word, direction;
string answer;
int row, column;
string puzzle[10] = {   "DWGDBHXBTS",
						"WEIRAHLRBR",
						"HDSFAAKEOE",
						"EAHUEIFAFY",
						"AMSRCUNKRA",
						"TQEELOOFXL",
						"UCPLJYFAIW",
						"WHOLESRSAI",
						"HEVITNETTA",
						"LLXDJUINIM"};

string userpuzzle[M];

cout << "Do you want to use the pre-defined puzzle? Y/N: ";
cin >> answer;

if (answer == "N" || answer == "n"){
initialize(userpuzzle);
output(userpuzzle);
while (word != "DONE"){
		cout << "Enter in a word to search for: ";
		cin >> word;
		if (word != "DONE"){
		search(userpuzzle, word, direction, row, column);
		if (search(userpuzzle, word, direction, row, column) == true){
			cout << "Found " << word << " at (" << row << " , " << column << ") " << direction << endl;
		}
		else
			cout << word << " not found." << endl;
	}

}
}

else if (answer == "Y" || answer == "y"){
	output(puzzle);
	while (word != "DONE"){
		cout << "Enter in a word to search for: ";
		cin >> word;
		if (word != "DONE"){
		search(puzzle, word, direction, row, column);
		if (search(puzzle, word, direction, row, column) == true){
			cout << "Found " << word << " at (" << row << " , " << column << ") " << direction << endl;
		}
		else
			cout << word << " not found." << endl;
	}
	}
}
return 0;

}

void initialize(string userpuzzle[]){

string row;

for (int i=0; i<M; i++){
	cin >> row;
	userpuzzle[i] = row;
}
}

void output(string puzzle[]){

for (int i=0; i<M; i++)

cout << puzzle[i] << endl;

}

bool search(string search[], string word, string &direction, int &row, int &column){

	//DO UNTIL THE PERSON ENTERS DONE
	char firstletter;
	string found;
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			firstletter = word[0];
			if (firstletter == search[i][j]){
				found = word[0];
				if (i - 1 >= 0 && word[1] == search[i-1][j]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (i - g >= 0 && word[g] == search[i-g][j])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "N";
					
						return true;
					}
					found = firstletter;
				
				}

				if (i + 1 < M && word[1] == search[i+1][j]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (i + g < M && word[g] == search[i+g][j])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "S";
						return true;
					}
					found = firstletter;
				}
				if (j + 1 < N && word[1] == search[i][j+1]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (j + g < N && word[g] == search[i][j+g])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "E";
						return true;
					}
					found = firstletter;
				}
				if (j - 1 >= 0 && word[1] == search[i][j-1]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (j - g >=0 && word[g] == search[i][j-g])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "W";
						return true;
					}
					found = firstletter;
				}
				if (i - 1 >=0  && j - 1 >=0  && word[1] == search[i-1][j-1]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (i - g >= 0&& j -g >=0 && word[g] == search[i-g][j-g])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "NW";
						return true;
					}
					found = firstletter;
				}
				if (i +1 < M && j +1 < N && word[1] == search[i+1][j+1]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (i+g < M && j + g < N && word[g] == search[i+g][j+g])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "SE";
						return true;
					}
					found = firstletter;
				}
				if (i - 1 >= 0 && j +1 < N && word[1] == search[i-1][j+1]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (i -g >= 0 && j + g < N && word[g] == search[i-g][j+g])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "NE";
						return true;
					}
					found = firstletter;
				}
				if (i +1 < M && j -1 >= 0 && word[1] == search[i+1][j-1]){
					found = found + word[1];
					for (int g=2; g<word.length(); g++)
						if (i + g < M && j - g >=0 && word[g] == search[i+g][j-g])
							found = found + word[g];
					if(found == word){
						row = i;
						column = j;
						direction = "SW";
						return true;
					}
					found = firstletter;
				}
			}
		}
	}
	return false;
}