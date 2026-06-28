
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Answer {
private:
    string text;
    bool isCorrect;

public:
 
    Answer(const string& text, const bool isc);
    ~Answer();

  
    string getText() const;


  
    void setText(const string& text);
   

 
    string toString();
};



