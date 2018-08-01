//============================================================================
// Name        : test1.cpp
// Author      : KartaYu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * C++ Program to Implement Knuth¡VMorris¡VPratt Algorithm (KMP)
 */
#include <iostream>
#include <cstring>
using namespace std;

void prefix_KMP(string pattern , int failure[]){
	int p = pattern.length();
	int j = failure[0] = -1;

	for(int i = 1; i < p; i++){

		while( j >= 0 && pattern [j+1] != pattern[i]){
			j = failure[j];
		}

		if(pattern [j+1] == pattern[i]){
			j++;
		}
		failure[i] = j;


	}

}

bool KMP(string pattern, string text){
	int p = pattern.size();
	int t = text.size();
	int failure [p];

	prefix_KMP(pattern, failure);

	for(int i = 0, j = -1; i < text.size(); i++){

	    while(j >= 0 && pattern[j+1] != text[i])
			j = failure [j];


		if(pattern[j+1] == text[i])
			j++;

		if(j == (pattern.size() - 1)){
			return 1;
		}



	}

	return 0;

}


int main()
{
	string text, pattern;

	cout << "entry a text" << endl;
	cin >> text;
	cout << "entry a pattern" << endl ;
	cin >> pattern;

	if(text.size() < pattern.size())
		cout << "error: " <<pattern << " is longer then " << text;

	if(KMP(pattern, text)){
		cout << pattern << " is founded in "<< text << endl;
	}else{
		cout << pattern << " is not founded in " << text << endl;
	}
}
