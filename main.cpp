//Shira Cohen 211485198
//Mivne Netunim 2
//Targil 5- Graphs

#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

int main()
{
	try {
		string v1, v2, name;
		Graph g;
		int choice;
		cout << "choose one of the following:\n";
		cout << "1 - add a writer\n";
		cout << "2 - delete a writer\n";
		cout << "3 - add a follow up (edge)\n";
		cout << "4 - delete a follow up (edge)\n";
		cout << "5 - print all neighbors (followed)\n";
		cout << "6 - print all followers\n";
		cout << "7 - print all vertices that can be reached from V\n";
		cout << "8 - print all the graph\n";
		cout << "10 - exit";
		cout << endl;

		do
		{
			cin >> choice;
			switch (choice)
			{
			case 1:cout << "enter the writer name\n";
				cin >> v1;
				g.addv(v1);
				break;
			case 2:cout << "enter the writer name\n";
				cin >> v1;
				if (g.delv(v1))
					cout << "success";
				else
					cout << "ERROR";
				break;
			case 3:cout << "enter the follower and the writer\n";
				cin >> v1 >> v2;
				if (g.adde(v1, v2))
					cout << "success";
				else
					cout << "ERROR";
				break;
			case 4:cout << "enter the follower and the writer\n";
				cin >> v1 >> v2;
				if (g.dele(v1, v2))
					cout << "success";
				else
					cout << "ERROR";
				break;
			case 5:cout << "enter the v you want to print its neighbours\n";
				cin >> v1;
				g.printNeighbors(v1);
				break;
			case 6:cout << "enter the v you want to its followers\n";
				cin >> v1;
				g.printFollowers(v1);
				break;
			case 7:
				cout << "enter writer\n";
				cin >> v1;
				g.printAllReached(v1);
				break;

			case 8:
				cout << "The graph:\n";
				g.printAll();
				break;

			case 10:cout << "byebye";  break;
			default:cout << "ERROR";

			}
			cout << endl;
		} while (choice != 10);
	}
	catch (string s)
	{
		cout << s << endl;
	}
	return 0;
}

//choose one of the following :
//1 - add a writer
//2 - delete a writer
//3 - add a follow up(edge)
//4 - delete a follow up(edge)
//5 - print all neighbors(followed)
//6 - print all followers
//7 - print all vertices that can be reached from V
//8 - print all the graph
//10 - exit
//1
//enter the writer name
//a
//
//1
//enter the writer name
//b
//
//1
//enter the writer name
//c
//
//1
//enter the writer name
//d
//
//3
//enter the follower and the writer
//a b
//success
//3
//enter the follower and the writer
//a e
//ERROR
//3
//enter the follower and the writer
//b c
//success
//8
//The graph :
//a: b
//	b : c
//	c :
//d:
//
//   4
//	   enter the follower and the writer
//	   a f
//	   ERROR
//	   8
//	   The graph :
//a: b
//	b : c
//	c :
//d:
//
//   5
//	   enter the v you want to print its neighbours
//	   a
//	   b
//
//	   5
//	   enter the v you want to print its neighbours
//	   g
//	   ERROR
//
//	   6
//	   enter the v you want to its followers
//	   a
//
//
//	   6
//	   enter the v you want to its followers
//	   b
//	   a
//
//	   6
//	   enter the v you want to its followers
//	   f
//	   ERROR
//
//	   7
//	   enter writer
//	   a
//	   a b c
//
//	   7
//	   enter writer
//	   f
//	   ERROR
//
//	   8
//	   The graph :
//a: b
//	b : c
//	c :
//d:
//
//   10
//	   byebye
//
//	   C : \Users\User\Desktop\מבנה נתונים ב\תרגיל 5\Debug\תרגיל 5.exe(process 2528) exited with code 0.
//	   To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	   Press any key to close this window . . .