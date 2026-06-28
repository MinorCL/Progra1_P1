
#include "AnswerContainer.h"

using namespace std;

class Question {
private:
    string quest;            
    AnswerContainer* answers;
    int score;               
    int uses;           
    bool isDefault;

public:
   
    Question(const string& quest, int score, bool is);
    ~Question();

    
    void addAnswer(Answer* answer); 
    string toString() const;      
    int getScore() const;         
    void setScore(int score);     
    void dncrementUses(int i= 1);
    bool getDef();
    int getUses() const;           
    void incrementUses();          
};

