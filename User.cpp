#include "User.h"

User::User() {
    this->id = std::to_string(countOfUsers++);
    this->delay = 1;
    this->message = "Without message";
}

User::User(std::string id, long long int delay, std::string message) {
    this->id = id;
    this->delay = delay;
    this->message = message;
}

User::User(long long int delay, std::string message) {
    this->id = std::to_string(countOfUsers++);
    this->delay = delay;
    this->message = message;
}

std::string User::getId() {
    return id;
}

ll User::getDelay() const {
    return delay;
}

std::string User::getMessage() {
    return message;
}


