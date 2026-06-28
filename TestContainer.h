#pragma once

#include "Test.h"
class TestContainer {
private:
    Test** tests;      
    int size;         
    int capacity;      

    void resize();     

public:
    TestContainer(int initialCapacity = 2);
    ~TestContainer();

    void addTest(Test* test);
    Test* getTest(int index) const; 
    int getSize() const; 
	bool removeTestByName(const string& testName);
    string showTestNamesAndScores() const;
    Test* getTestByName(const string& testName);
    string toString() const;

};




