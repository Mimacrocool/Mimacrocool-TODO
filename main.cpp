#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int t, x;
vector <string> Folder_name;
vector <string> todo_name[N];
vector <int> todo_done[N];
void init() {
	system("echo 0 >> .todo");
	freopen(".todo", "r", stdin);
	cin >> t;
	if (t == 0) {
		Folder_name.push_back("main");
		fclose(stdin);
		return;
	}
	Folder_name.resize(t);
	for (int i = 0; i < t; i++) {
		cin >> Folder_name[i] >> x;
		todo_name[i].resize(x);
		todo_done[i].resize(x);
		for (int j = 0; j < x; j++) 
			cin >> todo_name[i][j];
		for (int j = 0; j < x; j++)
			cin >> todo_done[i][j];
			
	}
	fclose(stdin);
}
void output() {
	freopen(".todo", "w", stdout);
	cout << Folder_name.size() << '\n';
	for (int i = 0; i < Folder_name.size(); i++) {
		cout << Folder_name[i] << '\n' << todo_name[i].size() << '\n';
		for (string j : todo_name[i]) 
			cout << j << '\n';
		for (bool j : todo_done[i])	
			cout << j<< '\n';
	}
	fclose(stdout);
} 
int main(int argc, char *argv[]) {
	init();
	if (argc == 1) {
		cout << "Please enter the command\n";
	} else if (!strcmp(argv[1], "add")) {
		if (argc == 2) {
			cout << "Please enter the name of the todo\n";
		}else if (argc == 3) {
			todo_name[0].push_back(argv[2]);
			todo_done[0].push_back(false);
		} else if (argc == 4) {
			int found = -1;
			for (int i = 0; i < Folder_name.size(); i++) 
			    if (!strcmp(argv[2], Folder_name[i].c_str())) {
					found = i;
					break;
				}
			if (found != -1) {
			    todo_name[found].push_back(argv[3]);
			    todo_done[found].push_back(false);
			} else {
				cout << "Folder not found\nDo you want to create a new folder?(Y/N)";
				char c;
				c = getchar();
				cout << c << '1';
				if (c == 'Y' || c == 'y') {
					Folder_name.push_back(argv[2]);
					todo_name[Folder_name.size() - 1].push_back(argv[3]);
					todo_done[Folder_name.size() - 1].push_back(false);
				} 
			}
		}
	}
	output();
}

