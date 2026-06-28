

#include "IDContainer.h"

class Test {
private:
    ID** ids;        
    IDContainer* Idco;
    int size;       
    int capacity;    
    string name;

    void resize();   

public:
    Test(const string& name, int initialCapacity = 4); 
    ~Test();                                           
    void addQuestion(Question* question); 
    string getName();
    string toString() const;                          
    IDContainer* getIDContainer() const;
};





