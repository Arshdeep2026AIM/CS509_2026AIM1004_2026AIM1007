#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void handleAssignment(int assignmentNum, const string& folderName, const string& menuTitle, const string& options) {
    int algoChoice;
    do {
        clearScreen();
        cout << "-------------------------------------------------\n";
        cout << "              " << menuTitle << "                  \n";
        cout << "-------------------------------------------------\n";
        cout << options;
        cout << "0. Go Back\n";
        cout << "Enter choice: ";
        cin >> algoChoice;
        int maxChoice = 0;
        if (assignmentNum == 1) maxChoice = 3;
        else if (assignmentNum == 2) maxChoice = 4;
        else if (assignmentNum == 3) maxChoice = 2;
        else if (assignmentNum == 4) maxChoice = 2;

        if (algoChoice > 0 && algoChoice <= maxChoice) {
            int modeChoice;
            cout << "\nSelect Execution Mode:\n";
            cout << "0 - Run Once (Standard execution)\n";
            cout << "1 - Test Mode (Average of 5 runs)\n";
            cout << "Enter choice (0 or 1): ";
            cin >> modeChoice;

            string command = "cd ../" + folderName + " && .\\driver_app.exe " + to_string(algoChoice) + " ALL";
            if (modeChoice == 1) {
                command += " --test";
            }
            cout << "\n[System] Executing: " << command << "\n\n";
            system(command.c_str());
            pauseScreen();
        } else if (algoChoice != 0) {
            cout << "\n[!] Invalid choice.\n";
            pauseScreen();
        }
    } while (algoChoice != 0);
}

int main() {
    int mainChoice;
    do {
        clearScreen();
        cout << "=================================================\n";
        cout << "           CS509 Common Wrapper Menu             \n";
        cout << "=================================================\n";
        cout << "1. Assignment 01 (BFS, DFS, SSSP)\n";
        cout << "2. Assignment 02 (TC-Unopt, TC-Opt, BC, CC)\n";
        cout << "3. Assignment 03 (Gradient Descent, Maxflow-Mincut)\n";
        cout << "4. Assignment 04 (K-Means & FastMap)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                handleAssignment(1, "assignment_01", "Assignment 01 Menu", 
                                 "1. BFS\n2. DFS\n3. SSSP\n");
                break;
            case 2:
                handleAssignment(2, "assignment_02", "Assignment 02 Menu", 
                                 "1. Triangle Counting (Optimized)\n2. Betweenness Centrality (BC)\n3. Connected Components (CC)\n");
                break;
            case 3:
                handleAssignment(3, "assignment_03", "Assignment 03 Menu", 
                                 "1. Gradient Descent\n2. Maxflow-Mincut\n");
                break;
            case 4:
                handleAssignment(4, "assignment_04", "Assignment 04 Menu", 
                                 "1. K-Means Clustering\n2. FastMap\n");
                break;
            case 0:
                cout << "\nExiting wrapper. Goodbye!\n";
                break;
            default:
                cout << "\n[!] Invalid choice. Please try again.\n";
                pauseScreen();
                break;
        }
    } while (mainChoice != 0);
    return 0;
}