

#include "Answer.h"

class AnswerContainer {
private:
    Answer** Answers; 
    int size;
    int capacity;

   
    void resize();

public:
   
    AnswerContainer(int t);
    ~AnswerContainer();

    void addAnswer(Answer* answer);

  
    Answer* getAnswer(int index) const;

   
    string toString();
};





