


#include "TestContainer.h"
class Controller {
private:
    TestContainer* testContainer; 
    IDContainer* idContainer;    

    void initializeDefaultQuestions();

    void clearScreen(); 

public:
    Controller();
    ~Controller();

    void run(); 
};








