#include <string>
#define ll long long
#pragma once

static int countOfUsers = 1;

class User {
    private:
        std::string id;
        ll delay;
        std::string message;


    public:
        User();
        User(std::string id, ll delay, std::string message);
        User(ll delay, std::string message);

        std::string getId();
        ll getDelay() const;
        std::string getMessage();

};

