/*
 * author: Mimacrocool in Github
 * email: 1345098180@qq.com
 * All rights reserved.
 * Developed by the Mimacrocool Dev Team
 * 2024-2024 , © Mimacrocool
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int t, x;
vector<string> Folder_name;
vector<string> todo_name[N];
vector<int> todo_done[N];
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
    freopen("CON", "r", stdin);
}
void output() {
    freopen(".todo", "w", stdout);
    int cnt = Folder_name.size();
    for (int i = 0; i < Folder_name.size(); i++)
        if (!strcmp(Folder_name[i].c_str(), ""))
            cnt--;
    cout << cnt << '\n';
    for (int i = 0; i < Folder_name.size(); i++) {
        if (!strcmp(Folder_name[i].c_str(), ""))
            continue;
        cout << Folder_name[i] << '\n' << todo_name[i].size() << '\n';
        for (string j : todo_name[i])
            cout << j << '\n';
        for (bool j : todo_done[i])
            cout << j << '\n';
    }
    freopen("CON", "w", stdout);
}
int main(int argc, char* argv[]) {
    init();
    if (argc == 1) {
        cout << "Please enter the command\n";
    } else if (!strcmp(argv[1], "add")) {
        if (argc == 2) {
            cout << "Please enter the name of the todo\n";
        } else if (argc == 3) {
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
                cout << "Folder not found\nDo you want to create a new "
                        "folder?(Y/N)";
                char c;
                cin >> c;
                if (c == 'Y' || c == 'y') {
                    Folder_name.push_back(argv[2]);
                    todo_name[Folder_name.size() - 1].push_back(argv[3]);
                    todo_done[Folder_name.size() - 1].push_back(false);
                }
            }
        } else {
            cout << "Invalid command\n";
        }
    } else if (!strcmp(argv[1], "del")) {
        if (argc == 2) {
            cout << "Please enter the name of the todo\n";
        } else if (argc == 3) {
            int found = -1;
            for (int i = 0; i < todo_name[0].size(); i++)
                if (!strcmp(argv[2], todo_name[0][i].c_str())) {
                    found = i;
                    break;
                }
            if (found != -1) {
                todo_name[0].erase(todo_name[0].begin() + found);
                todo_done[0].erase(todo_done[0].begin() + found);
            } else {
                cout << "Todo not found\n";
            }
        } else if (argc == 4) {
            int found = -1;
            for (int i = 0; i < Folder_name.size(); i++)
                if (!strcmp(argv[2], Folder_name[i].c_str())) {
                    found = i;
                    break;
                }
            if (found != -1) {
                int Found = -1;
                for (int i = 0; i < todo_name[found].size(); i++)
                    if (!strcmp(argv[3], todo_name[found][i].c_str())) {
                        Found = i;
                        break;
                    }
                if (Found != -1) {
                    todo_name[found].erase(todo_name[found].begin() + Found);
                    todo_done[found].erase(todo_done[found].begin() + Found);
                } else {
                    cout << "Todo not found\n";
                }
            } else {
                cout << "Folder not found\n";
            }
        } else {
            cout << "Invalid command\n";
        }
    } else if (!strcmp(argv[1], "rm")) {
        if (argc == 2) {
            cout << "Please enter the name of the folder\n";
        } else if (argc == 3) {
            if (!strcmp(argv[2], "main")) {
                cout << "The folder named main cannot be deleted\n";
            } else {
                int found = -1;
                for (int i = 0; i < Folder_name.size(); i++) {
                    if (!strcmp(Folder_name[i].c_str(), argv[2])) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) {
                    Folder_name[found] = "";
                } else {
                    cout << "Folder not found\n";
                }
            }
        } else {
            cout << "Invalid command\n";
        }
    } else if (!strcmp(argv[1], "show")) {
        if (argc == 2) {
            cout << "Items in list main: \n";
            cout << left << setw(log10(todo_name[0].size() + 1) + 5) << "id"
                 << left << setw(5) << "name" << left << setw(9) << "status"
                 << '\n';
            for (int i = 0; i < todo_name[0].size(); i++)
                cout << left << setw(log10(todo_name[0].size() + 1) + 5)
                     << i + 1 << left << setw(5) << todo_name[0][i] << left
                     << setw(9) << (todo_done[0][i] ? "Y" : "N") << '\n';
        } else if (argc == 3) {
            int found = -1;
            for (int i = 0; i < Folder_name.size(); i++) {
                if (!strcmp(Folder_name[i].c_str(), argv[2])) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                cout << "Items in list " << Folder_name[found] << ": \n";
                cout << left << setw(log10(todo_name[found].size() + 1) + 5)
                     << "id" << left << setw(5) << "name" << left << setw(9)
                     << "status" << '\n';
                for (int i = 0; i < todo_name[found].size(); i++)
                    cout << left << setw(log10(todo_name[found].size() + 1) + 5)
                         << i + 1 << left << setw(5) << todo_name[found][i]
                         << left << setw(9) << (todo_done[found][i] ? "Y" : "N")
                         << '\n';
            } else {
                cout << "Folder not found\n";
            }
        } else {
            cout << "Invalid command\n";
        }
    } else if (!strcmp(argv[1], "done")) {
        if (argc == 2) {
            cout << "Please enter the name of the todo\n";
        } else if (argc == 3) {
            int found = -1;
            for (int i = 0; i < todo_name[0].size(); i++)
                if (!strcmp(argv[2], todo_name[0][i].c_str())) {
                    found = i;
                    break;
                }
            if (found != -1) {
                todo_done[0][found] = true;
            } else {
                cout << "Todo not found\n";
            }
        } else if (argc == 4) {
            int found = -1;
            for (int i = 0; i < Folder_name.size(); i++)
                if (!strcmp(argv[2], Folder_name[i].c_str())) {
                    found = i;
                    break;
                }
            if (found != -1) {
                int Found = -1;
                for (int i = 0; i < todo_name[found].size(); i++)
                    if (!strcmp(argv[3], todo_name[found][i].c_str())) {
                        Found = i;
                        break;
                    }
                if (Found != -1) {
                    todo_done[found][Found] = true;
                } else {
                    cout << "Todo not found\n";
                }
            } else {
                cout << "Folder not found\n";
            }
        } else {
            cout << "Invalid command\n";
        }
    } else if (!strcmp(argv[1], "undo")) {
        if (argc == 2) {
            cout << "Please enter the name of the todo\n";
        } else if (argc == 3) {
            int found = -1;
            for (int i = 0; i < todo_name[0].size(); i++)
                if (!strcmp(argv[2], todo_name[0][i].c_str())) {
                    found = i;
                    break;
                }
            if (found != -1) {
                todo_done[0][found] = false;
            } else {
                cout << "Todo not found\n";
            }
        } else if (argc == 4) {
            int found = -1;
            for (int i = 0; i < Folder_name.size(); i++)
                if (!strcmp(argv[2], Folder_name[i].c_str())) {
                    found = i;
                    break;
                }
            if (found != -1) {
                int Found = -1;
                for (int i = 0; i < todo_name[found].size(); i++)
                    if (!strcmp(argv[3], todo_name[found][i].c_str())) {
                        Found = i;
                        break;
                    }
                if (Found != -1) {
                    todo_done[found][Found] = false;
                } else {
                    cout << "Todo not found\n";
                }
            } else {
                cout << "Folder not found\n";
            }
        } else {
            cout << "Invalid command\n";
        }
    } else if (!strcmp(argv[1], "help")) {
        cout << "add: Add a to-do item. It can be added to the main list or a "
                "specified folder."
             << endl;
        cout << "del: Delete a to-do item. It can delete items in the main "
                "list or in a specified folder."
             << endl;
        cout << "rm: Remove a folder. It can delete a specified folder, but "
                "the main folder cannot be deleted."
             << endl;
        cout << "show: Display to-do items. It can show items in the main list "
                "or in a specified folder."
             << endl;
        cout << "done: Mark an item as completed. It can mark items in the "
                "main list or in a specified folder."
             << endl;
        cout << "undo: Undo completion status. It can undo the completion "
                "status of items in the main list or in a folder."
             << endl;
        cout << "help: Display help information, listing available commands."
             << endl;
    } else {
        cout << "Invalid command\n";
        cout << "You can type help to get help.\n";
    }
    output();
}
