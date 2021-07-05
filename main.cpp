#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>



using namespace std;




int main() {
    string nameOfFile;
    cin >> nameOfFile;


    int numOfUsers = 0;
    cin >> numOfUsers;

    vector <pair<int, string>> users;

    std::ofstream logFile;
    logFile.open(nameOfFile, std::ios_base::out);
    std::cout.rdbuf(logFile.rdbuf());

    for (int i = 0; i < numOfUsers; ++i) {
        int delay;
        string message;
        cin >> delay;
        getline(cin, message);

        users.emplace_back(make_pair(delay, message));

    }

    long long secCounter = 0;
    time_t now1 = time(0);
    while (true) {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        if (now - now1 >= 1) {
            for (int i = 0; i < users.capacity(); ++i) {
                if (secCounter % users[i].first == 0 && secCounter != 0){
                    cout << "Time: "<< 1 + ltm->tm_hour << ":";
                    cout << 1 + ltm->tm_min << ":";
                    if (1 + ltm->tm_sec < 10)
                        cout << 0;
                    cout << 1 + ltm->tm_sec << ", ";
                    cout << "User id: " << i << "\t";
                    cout << users[i].second << endl;
                }
            }
            secCounter++;
            now1 = now;
        }
    }
}

/*
 *
Q:\CProjects\miniChat\chat.txt
3
2 Dima
3 Nikita
5 Sasha
 */
