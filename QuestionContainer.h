#include"Question.h"
class QuestionContainer {
private:
    Question** Questions;
    int size;
    int capacity;

    
    void resize();

public:
    
    QuestionContainer(int t);
    ~QuestionContainer();
    void addQuestion(Question* question);
    int getSize() const;
	string getQuestion(int index) const;
    string toString();
};
