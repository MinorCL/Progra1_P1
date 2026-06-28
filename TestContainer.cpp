#include "TestContainer.h"
TestContainer::TestContainer(int initialCapacity)
    : size(0), capacity(initialCapacity) {
    tests = new Test * [capacity];
}

TestContainer::~TestContainer() {
    for (int i = 0; i < size; ++i) {
        delete tests[i]; 
    }
    delete[] tests;
    cout << "TestContainer destroyed." << endl;
}

void TestContainer::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Test** newTests = new Test * [capacity];
    for (int i = 0; i < size; ++i) {
        newTests[i] = tests[i];
    }
    delete[] tests;
    tests = newTests;
}

void TestContainer::addTest(Test* test) {
    if (size == capacity) {
        resize();
    }
    tests[size++] = test;
}

Test* TestContainer::getTest(int index) const {
    if (index >= 0 && index < size) {
        return tests[index];
    }
    return nullptr;
}

int TestContainer::getSize() const {
    return size;
}


bool TestContainer::removeTestByName(const string& testName) {
    for (int i = 0; i < size; ++i) {
        if (tests[i]->getName() == testName) { 
            
            IDContainer* ids = tests[i]->getIDContainer();
            for (int j = 0; j < ids->getSize(); ++j) {
                Question* question = ids->getID(j)->getQuestion();
                if (question) {
                    question->dncrementUses(-1);
                }
            }

           
            delete tests[i]; 
            for (int k = i; k < size - 1; ++k) {
                tests[k] = tests[k + 1];
            }
            --size;
            return true; 
        }
    }
    return false; 
}
string TestContainer::showTestNamesAndScores() const {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        Test* test = tests[i];
        if (test) {
            ss << "Test Name: " << test->getName() << "\n";
            ss << "Score: " << test->getIDContainer()->getSize() << " questions.\n";
        }
    }
    return ss.str();
}

Test* TestContainer::getTestByName(const string& testName) {
    for (int i = 0; i < size; ++i) {
        if (tests[i]->getName() == testName) {
            return tests[i];
        }
    }
    return nullptr; // Retorna nullptr si no se encuentra el test
}




string TestContainer::toString() const {
    stringstream ss;
    ss << "Tests in the container:\n";
    for (int i = 0; i < size; ++i) {
        ss << "  Test " << i + 1 << tests[i]->toString() << "\n";
    }
    return ss.str();
}


