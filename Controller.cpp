#include "Controller.h"
#include <cctype> 


void Controller::initializeDefaultQuestions() {
    Question* question1 = new Question("What is the capital of France?", 5, true);
    question1->addAnswer(new Answer("Paris", true));
    question1->addAnswer(new Answer("London", false));
    question1->addAnswer(new Answer("Berlin", false));
    question1->addAnswer(new Answer("Madrid", false));

    Question* question2 = new Question("Which planet is known as the Red Planet?", 5, true);
    question2->addAnswer(new Answer("Mars", true));
    question2->addAnswer(new Answer("Earth", false));
    question2->addAnswer(new Answer("Jupiter", false));

    Question* question3 = new Question("What is the largest ocean on Earth?", 5, true);
    question3->addAnswer(new Answer("Pacific Ocean", true));
    question3->addAnswer(new Answer("Atlantic Ocean", false));
    question3->addAnswer(new Answer("Indian Ocean", false));
    question3->addAnswer(new Answer("Arctic Ocean", false));

    idContainer->addID(new ID(question1));
    idContainer->addID(new ID(question2));
    idContainer->addID(new ID(question3));
}

Controller::Controller() {
    testContainer = new TestContainer(5);
    idContainer = new IDContainer(10); // Capacidad inicial para el banco de preguntas
    initializeDefaultQuestions();     
}

Controller::~Controller() {
    delete testContainer;
    delete idContainer;
}

void Controller::clearScreen() {
    system("cls");
}

void Controller::run() {
    cout << "Welcome to the Test Management System!\n";

    while (true) {
        clearScreen();
        cout << "Options:\n";
        cout << "1. Create a new test\n";
        cout << "2. View all tests\n";
        cout << "3. Delete a test by name\n";
        cout << "4. View available questions\n";
        cout << "5. Query a question by ID\n";
        cout << "6. Query a test by name\n";
        cout << "7. Exit\n";
        cout << "8. Add a new question\n"; 
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            clearScreen();
            cout << "Enter the name of the test: ";
            string testName;
            cin.ignore();
            getline(cin, testName);

            Test* newTest = new Test(testName); // Crear un nuevo examen

            while (true) {
                cout << "Enter the ID of the question to add (or 0 to stop): ";
                int questionID;
                cin >> questionID;

                if (questionID == 0) break;

                Question* question = idContainer->getQuestionByID(questionID);
                if (question) {
                    if (question->getUses() < 3) { // Verificar que la pregunta no haya sido usada 3 veces
                        newTest->addQuestion(question); // Asignar pregunta al examen
                    }
                    else {
                        cout << "Question with ID " << questionID << " has already been used in 3 tests and cannot be added.\n";
                    }
                }
                else {
                    cout << "Invalid ID. Try again.\n";
                }
            }

            testContainer->addTest(newTest);
            cout << "Test \"" << testName << "\" created successfully!\n";
            system("pause");
        }


        else if (choice == 2) {
            clearScreen();
            cout << testContainer->toString() << endl;
            system("pause");
        }
        else if (choice == 3) {
            clearScreen();
            cout << "Enter the name of the test to delete: ";
            string testName;
            cin.ignore();
            getline(cin, testName);

            if (testContainer->removeTestByName(testName)) {
                cout << "Test \"" << testName << "\" deleted successfully!\n";

            }
            else {
                cout << "Test \"" << testName << "\" not found.\n";
            }
            system("pause");
        }
        else if (choice == 4) {
            clearScreen();
            cout << "Available questions:\n";
            cout << idContainer->toString() << endl;
            system("pause");
        }
        else if (choice == 5) {
            clearScreen();
            cout << "Enter the ID of the question to query: ";
            int id;
            cin >> id;
            Question* question = idContainer->getQuestionByID(id);
            if (question) {
                cout << question->toString() << endl;
            }
            else {
                cout << "Question with ID " << id << " not found.\n";
            }
            system("pause");
        }
        else if (choice == 6) {
            clearScreen();
            cout << "Enter the name of the test to query: ";
            string testName;
            cin.ignore();
            getline(cin, testName);

            Test* test = testContainer->getTestByName(testName);
            if (test) {
                cout << test->toString() << endl;
            }
            else {
                cout << "Test \"" << testName << "\" not found.\n";
            }
            system("pause");
        }
        else if (choice == 8) { 
            clearScreen();
            cout << "Enter the text for the new question: ";
            cin.ignore(); 
            string questionText;
            getline(cin, questionText);

            cout << "Enter the score for this question: ";
            int score;
            cin >> score;

            Question* newQuestion = new Question(questionText, score, false); // Crear pregunta personalizada

            cout << "How many answers does this question have? ";
            int numAnswers;
            cin >> numAnswers;

            for (int i = 0; i < numAnswers; ++i) {
                cin.ignore();
                cout << "Enter text for answer " << i + 1 << ": ";
                string answerText;
                getline(cin, answerText);

                cout << "Is this answer correct? (y/n): ";
                char isCorrectChar;
                cin >> isCorrectChar;
                bool isCorrect = (tolower(isCorrectChar) == 'y');

                newQuestion->addAnswer(new Answer(answerText, isCorrect)); // Agregar respuesta a la pregunta
            }

            idContainer->addID(new ID(newQuestion)); // Agregar la pregunta al banco 
            cout << "Question added successfully with ID " << ID::getNextId() - 1 << "!\n";
            system("pause");
        }
        else if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
            system("pause");
        }
    }
}
