// lab_5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;


vector <int> vecH = { 1,2,5,3,4 };
vector <int> vecV = { 5,1,4,2,3 };



// Функція шифрування
string Uncoding(string Text)
{
	int t = 0;
	string shyfr;
	char Table[6][6];
	char NewTable[6][6];
	

	cout << "\nZapushemo nashu frazu v tablytcu:\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(t<Text.length())
			{
				Table[i][j] = Text[t];
				t++;
				cout << "|" << Table[i][j] << "| ";
			}
		}
		cout << "\n";
	}

	cout << "\n\nPeremistymo ryadky i stovpci zgidno klychiv:\n12534 - po horyzontali\n51423 - po vertykali\n";
		
	for (int i = 0; i < 5; i++)
	{
		t = 0;
		for (int j = 0; j < 5; j++)
		{
			if (t<Text.length())
			{
				NewTable[vecH[i] - 1][vecV[j] - 1] = Table[i][j];
				t++;
			}
		}
	}
	cout << "\n\nVyvodymo peremishanu tablycu:\n";
	
	
	for (int i = 0; i < 5; i++)
	{
		t = 0;
		for (int j = 0; j < 5; j++)
		{
			if (t<Text.length())
			{
				cout << "|" << NewTable[i][j] << "| ";
				shyfr += NewTable[i][j];
				t++;
			}
		}
		cout << "\n";
	}

return shyfr;
}

string Decoding(string Text)
{
	int t = 0;
	string shyfr;
	char Table[6][6];
	char NewTable[6][6];


	cout << "\nZapushemo codovanu frazu v tablytcu:\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (t<Text.length())
			{
				Table[i][j] = Text[t];
				t++;
				cout << "|" << Table[i][j] << "| ";
			}
		}
		cout << "\n";
	}

	cout << "\n\nDecoduyemo ryadky i stovpci zgidno klychiv:\n12534 - po horyzontali\n51423 - po vertykali\n";

	for (int i = 0; i < 5; i++)
	{
		t = 0;
		for (int j = 0; j < 5; j++)
		{
			if (t<Text.length())
			{
				NewTable[i][j] = Table[vecH[i] - 1][vecV[j] - 1];
				t++;
			}
		}
	}
	cout << "\n\nVyvodymo peremishanu tablycu:\n";

	for (int i = 0; i < 5; i++)
	{
		t = 0;
		for (int j = 0; j < 5; j++)
		{
			if (t<Text.length())
			{
				t++;
				cout << "|" << NewTable[i][j] << "| ";
				shyfr += NewTable[i][j];
			}
		}
		cout << "\n";
	}

	return shyfr;
}


int main()
{
	string text = "ivanofrankivsk_university";
	string Hor = "12534";
	string Vert = "51423";
	string result = Uncoding(text);
	cout << "\nShyfruemo frazu: 'ivanofrankivsk_university'\n";
	cout << "\nRezultat shyfruvannya:\n" << result << "\n\n";
	cout << "\nRezultat deshyfruvannya:\n" << Decoding(result) << "\n\n";
	
    return 0;
}

