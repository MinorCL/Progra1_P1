#include "Question.h"


Question::Question(const string& quest, int score, bool is) {
    this->quest = quest;
    this->score = score;
    this->uses = 0; // Inicializa los usos en 0
    isDefault = is;
    answers = new AnswerContainer(4); // Inicializa con capacidad inicial para 4 respuestas
}

Question::~Question() {
    delete answers; 
}

void Question::addAnswer(Answer* answer) {
    answers->addAnswer(answer);
}

int Question::getScore() const {
    return score;
}

void Question::setScore(int score) {
    this->score = score;
}

void Question::dncrementUses(int n) {
    uses += n;
    if (uses < 0) {
        uses = 0;
    }
}

bool Question::getDef()
{
    return isDefault;
}


string Question::toString() const {
    stringstream ss;
    ss << "Question: " << quest << "\n";
    ss << "Score: " << score << "\n";
    ss << "Uses: " << uses << "\n";
    ss << "Answers:\n" << answers->toString();
    return ss.str();
}


int Question::getUses() const {
    return uses;
}

void Question::incrementUses() {
    ++uses;
}






