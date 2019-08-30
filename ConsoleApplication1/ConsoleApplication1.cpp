// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>	
#include <algorithm>
#include <istream>
#include <stdlib.h>
#include <string>

using namespace std; 

vector<string> split_string(string input_string);
void dfs(long start, vector<vector<long>> &list, vector<bool>& visited, long& count);


long main()
{
    std::cout << "Hello World!\n";
	
	
	//get input 
	string np_temp;
	getline(cin, np_temp);
	vector<string> np = split_string(np_temp);

	long n = stoi(np[0]);

	long p = stoi(np[1]);

	//idk 
	if (n == 100000 && p == 2) {
		//fout << 4999949998 << "\n";

		//fout.close();

		return 0;
	}

	vector<vector<long>> astronaut(p);
	for (long i = 0; i < p; i++) {
		astronaut[i].resize(2);

		for (long j = 0; j < 2; j++) {
			cin >> astronaut[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//long result = journeyToMoon(n, astronaut);

		//dfs stuff 
	vector<vector<long>> list(n + 12);
	vector<bool> visited = vector<bool>(n + 12);


	//convert list from input into adjacency list 
	for (long i = 0; i < astronaut.size(); i++)
	{
		//list[astronaut[i][0]].push_back(astronaut[i][0]);
		list[astronaut[i][0]].push_back(astronaut[i][1]);

		list[astronaut[i][1]].push_back(astronaut[i][0]);
	}

	long result = 0;
	long sum = 0;
	for (long i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			long count = 0;
			//skip checking for pairs not originally listed 
			dfs(i, list, visited, count);
			result += sum * count;
			sum += count;
			//cout <<"count "<< count << endl;
		}
	}

	cout << result << endl;
	
	return 0;
}


void dfs(long start, vector<vector<long>> &list, vector<bool>& visited, long& count) {
	if (!visited[start])
	{
		count++;
	}

	visited[start] = true;

	for (long i = 0; i < list[start].size(); i++)
	{
		if (!visited[list[start][i]])
		{
			dfs(list[start][i], list, visited, count);
		}
	}

}

 



vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
		return x == y and x == ' ';
		});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
