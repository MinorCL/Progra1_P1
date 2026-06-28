


#include "Question.h"

using namespace std;

class ID {
private:
    static int nextID; 
    int idValue;       
    Question* question; 

public:
    
    ID(Question* question);
    ~ID();

    
    int getIDValue() const;
    Question* getQuestion() const;

 
    void setQuestion(Question* question);

    string toString() const;
    static int getNextId() ;
};





