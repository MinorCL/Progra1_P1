
#include "Test.h"



Test::Test(const string& name, int initialCapacity)
    : name(name), size(0), capacity(initialCapacity) {
    ids = new ID * [capacity]; 
    Idco = new IDContainer[capacity];
}

Test::~Test() {
    for (int i = 0; i < size; ++i) {
        delete ids[i]; 
    }
    delete[] ids; 
}

void Test::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    ID** newIds = new ID * [capacity]; 
    for (int i = 0; i < size; ++i) {
        newIds[i] = ids[i];
    }
    delete[] ids;
    ids = newIds;
}

void Test::addQuestion(Question* question) {
    if (question->getUses() < 3) { // Verifica que la pregunta no haya alcanzado el límite de usos
        if (size == capacity) {
            resize(); 
        }
        ids[size++] = new ID(question); // Agregar un nuevo ID al contenedor del examen
        question->incrementUses();     // Incrementar el uso de la pregunta
    }
    else {
        cout << "This question has already been used in 3 tests and cannot be added.\n";
    }
}


string Test::getName()
{
    return name;
}
IDContainer* Test::getIDContainer() const {
    return Idco;
}

string Test::toString() const {
    stringstream ss;
    ss << "Test Name: " << name << "\n";
    int totalScore = 0;

    for (int i = 0; i < size; ++i) {
        Question* question = ids[i]->getQuestion();
        if (question) {
            ss << question->toString() << "\n";
            totalScore += question->getScore(); // Sumar puntajes de las preguntas
        }
    }

    ss << "Total Score: " << totalScore << "\n";
    return ss.str();
}
