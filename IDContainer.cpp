#include "IDContainer.h"

IDContainer::IDContainer(int capacity) : size(0), capacity(capacity) {
    ids = new ID * [capacity];
}

IDContainer::~IDContainer() {
    for (int i = 0; i < size; ++i) {
        delete ids[i];
    }
    delete[] ids;
}

void IDContainer::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    ID** newIDs = new ID * [capacity];
    for (int i = 0; i < size; ++i) {
        newIDs[i] = ids[i];
    }
    delete[] ids;
    ids = newIDs;
}

void IDContainer::addID(ID* id) {
    if (size == capacity) {
        resize();
    }
    ids[size++] = id;
}

ID* IDContainer::getID(int index) const {
    if (index >= 0 && index < size) {
        return ids[index];
    }
    return nullptr;
}

int IDContainer::getSize() const
{
	return size;
}
Question* IDContainer::getQuestionByID(int idValue) const {
    for (int i = 0; i < size; ++i) {
        if (ids[i]->getIDValue() == idValue) {
            return ids[i]->getQuestion();
        }
    }
    return nullptr; // No se encontró la pregunta
}
bool IDContainer::containsID(int idValue) const {
    for (int i = 0; i < size; ++i) {
        if (ids[i]->getIDValue() == idValue) {
            return true;
        }
    }
    return false;
}
string IDContainer::showQuestionsWithDetails() const {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        Question* question = ids[i]->getQuestion();
        if (question) {
            ss << "ID: " << ids[i]->getIDValue() << "\n";
            ss << question->toString() << "\n";
        }
    }
    return ss.str();
}



string IDContainer::toString() const {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        ss << "  " << ids[i]->toString() << "\n";
    }
    return ss.str();
}

