#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "User.h"

using namespace std;

void printTime(int time, char delimiter) {
    if (time < 10)
        cout << 0;
    cout << time << delimiter;
}

int main() {
    string nameOfFile;
    cin >> nameOfFile;


    int numOfUsers = 0;
    cin >> numOfUsers;

    vector <User> users;

    std::ofstream chatFile;
    chatFile.open(nameOfFile, std::ios_base::out);
    std::cout.rdbuf(chatFile.rdbuf());

    for (int i = 0; i < numOfUsers; ++i) {
        int delay;
        string message;
        cin >> delay;
        getline(cin, message);

        User currentUser(delay, message);

        users.push_back(currentUser);

    }


    long long secCounter = 0;
    time_t now1 = time(nullptr);
    while (secCounter != LONG_LONG_MAX) {
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);

        if (now - now1 >= 1) {
            for (int i = 0; i < users.capacity(); ++i) {
                if (secCounter % users[i].getDelay() == 0 && secCounter != 0){
                    cout << "Time: ";
                    printTime(ltm->tm_hour, ':');
                    printTime(ltm->tm_min, ':');
                    printTime(ltm->tm_sec, ',');
                    cout << " User id: " << users[i].getId() << "\t";
                    cout << users[i].getMessage() << endl;
                    flush(cout);
                }
            }
            secCounter++;
            now1 = now;
        }
    }
}
