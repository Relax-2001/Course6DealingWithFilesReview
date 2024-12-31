#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Lesson1
void ReadMode()
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::out); // Write Mode

	if (MyFile.is_open())
	{

		MyFile << "Lyla\n";
		MyFile << "Dana\n";
		MyFile << "Lama\n";

		MyFile.close();

	}
}

//Lesson2
void AppendMode()
{

	fstream MyFile;
	MyFile.open("MyFile.txt", ios::out | ios::app); //Append Mode / Create if not exist
	{

		if (MyFile.is_open())
		{
			MyFile << "Sami\n";
			MyFile << "Ali\n";
			MyFile << "Mahmoud\n";

			MyFile.close();
		}

	}

}

//Lesson3
void PrintFileContent(string FileName)
{

	fstream MyFile;
	
	MyFile.open(FileName , ios::in); // Read Mode

	if (MyFile.is_open())
	{

		string Line = "";

		while (getline(MyFile , Line))
		{
			cout << Line << "\n";
		}

		MyFile.close();

	}


}

//Lesson4
void LoadDataFromFileToVector(string FileName , vector <string> & vLines)
{

	fstream MyFile;

	MyFile.open(FileName , ios::in); // Read mode

	if (MyFile.is_open())
	{

		string Line = "";

		while (getline(MyFile , Line))
		{

			vLines.push_back(Line);
			
		}

		MyFile.close();
	}


}

//Lesson5
void LoadDataFromVectorToFile(string FileName , vector <string> & vLines)
{

	fstream MyFile;

	MyFile.open(FileName , ios::out);
	{

		if (MyFile.is_open())
		{
			
			for (string & Element : vLines)
			{
				if (Element != "")
				{
					MyFile << Element << "\n";

				}

			}


		}
		MyFile.close();

	}


}

//Lesson6
void DeleteFromFile(string FileName , string ToDelete)
{
	vector <string> vLines;
	LoadDataFromFileToVector(FileName , vLines);

	for (string & Line : vLines)
	{

		if (Line == ToDelete)
		{
			Line = "";
		}

	}

	LoadDataFromVectorToFile(FileName , vLines);


}

//Lesson7
void UpdateRecordOnFile(string FileName, string Record , string ToUpdate)
{
	vector <string> vLines;
	LoadDataFromFileToVector(FileName, vLines);

	for (string& Line : vLines)
	{

		if (Line == Record)
		{
			Line = ToUpdate;
		}

	}

	LoadDataFromVectorToFile(FileName, vLines);


}


int main()
{

	PrintFileContent("MyFile.txt");

	UpdateRecordOnFile("MyFile.txt" , "Ali" , "Omar");

	cout << "\n\nafter delete\n";
	PrintFileContent("MyFile.txt");


	return 0;
}
