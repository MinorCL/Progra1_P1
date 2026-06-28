#include "Answer.h"


using namespace std;

Answer::Answer(const string& text,const bool isc){
	this->text = text;
	this->isCorrect = isc;

}

Answer::~Answer() {}

string Answer::getText() const {
    return text;
}



void Answer::setText(const string& text) {
    this->text = text;
}


string Answer::toString() {
    stringstream ss;
    ss << " " << text << " ";
    return ss.str();
}


