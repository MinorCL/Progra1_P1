#include "QuestionContainer.h"


using namespace std;

QuestionContainer::QuestionContainer(int t) : size(0), capacity(t) {
    
    Questions = new Question * [capacity];
}

QuestionContainer::~QuestionContainer() {
    for (int i = 0; i < capacity; i++)
    {
		delete Questions[i];

    }
	delete[] Questions;
}




void QuestionContainer::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Question** newQuestions = new Question * [capacity];
    for (Question** it = Questions, **newIt = newQuestions; it != Questions + size; ++it, ++newIt) {
        *newIt = *it;
    }
    delete[] Questions;
    Questions = newQuestions;
}

void QuestionContainer::addQuestion(Question* question) {
    if (size == capacity) {
        resize();
    }
    *(Questions + size++) = question;
}

int QuestionContainer::getSize() const
{
	return size;
}

string QuestionContainer::getQuestion(int index) const
{
	return Questions[index]->toString();
}

string QuestionContainer::toString() {
    stringstream ss;
    for (int i = 0; i < capacity; i++)
    {
		ss << "Question " << i + 1 << ": " << Questions[i]->toString() << "\n";

    }
    return ss.str();
}



