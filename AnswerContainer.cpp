#include "AnswerContainer.h"


using namespace std;

AnswerContainer::AnswerContainer(int t) : size(0), capacity(t) {
    Answers = new Answer * [capacity];
}

AnswerContainer::~AnswerContainer() {

    for (int i = 0; i < capacity; i++)
    {
		delete Answers[i];

    }
	delete[] Answers;
}

void AnswerContainer::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Answer** newAnswers = new Answer * [capacity];
    for (Answer** it = Answers, **newIt = newAnswers; it != Answers + size; ++it, ++newIt) {
        *newIt = *it;
    }
    delete[] Answers;
    Answers = newAnswers;
}

void AnswerContainer::addAnswer(Answer* answer) {
    if (size == capacity) {
        resize();
    }
    *(Answers + size++) = answer;
}

Answer* AnswerContainer::getAnswer(int index) const {
    if (index >= 0 && index < size) {
        return *(Answers + index);
    }
    return nullptr;
}

string AnswerContainer::toString() {
    stringstream ss;
    int counter = 1;
    for (Answer** it = Answers; it != Answers + size; ++it) {
        ss << "  Answer " << counter++ << ": " << (*it)->toString() << "\n";
    }
    return ss.str();
}



