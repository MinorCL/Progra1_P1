#include "ID.h"


int ID::nextID = 1;

ID::ID(Question* question) : idValue(nextID++), question(question) {}

ID::~ID() {

}

int ID::getIDValue() const {
    return idValue;
}

Question* ID::getQuestion() const {
    return question;
}

void ID::setQuestion(Question* question) {
    this->question = question;
}

string ID::toString() const {
    stringstream ss;
    ss << "ID: " << idValue << ", Question: " << (question ? question->toString() : "null");
    return ss.str();
}

int ID::getNextId()
{

    return nextID;
}

