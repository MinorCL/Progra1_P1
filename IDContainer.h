

#include "ID.h"

class IDContainer {
private:
    ID** ids;       
    int size;        
    int capacity;     

    void resize();    

public:
   
    IDContainer(int capacity = 4);
    ~IDContainer();

   
    void addID(ID* id);
    ID* getID(int index) const;
	int getSize() const;
	Question* getQuestionByID(int idValue) const;
	bool containsID(int idValue) const;
    string showQuestionsWithDetails() const;
    string toString() const;
};




