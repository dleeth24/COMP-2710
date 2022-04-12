/* FILE NAME: project4_Leeth_dkl0011.cpp
 * AUTHOR: Davis Leeth (dkl0011@auburn.edu)
 *
 * Complile: g++ project4_Leeth_dkl0011.cpp -o p4.out
 * Run: ./p4.out
 *
 * Comments: Used Dr. Li's hints for help along with
 * help from stackoverflow.com to learn about linked lists.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
using namespace std;
 

//Structure for creating a linked list that holds a trivia question, answer, and point amount. 
struct trivia_node { 
  string question; 
  string answer; 
  int point; 
  trivia_node *next; 
}; 

//Creates a trivia_list class used for linking lists.
class trivia_list {
    public:
        int count;
        trivia_node *head, *root;
        trivia_list() {
            count = 0;
            head = NULL;
            root = NULL;
        }
};

//creates a pointer to trivia_list. 
typedef trivia_node* trivia_nodeptr; 
 
//PROTOTYPES 

//Initializes the list.
void init_question_list(trivia_list&);

//Adds a question to the list.
void add_question(trivia_list&);
 
//Asks the user a question and starts the game.
int ask_question(trivia_list, int, int&);

//Tests the program
void Unit_Test();
 
//creates two versions. 
//Uncomment or comment the line below to run chose to run the unit test version or not
#define UNIT_TESTING 
#define trivia_quiz 

 
int main() {  
    //Method for testing 
#ifdef UNIT_TESTING
    Unit_Test(); 
#endif 

#ifdef trivia_quiz
    trivia_list node_list; 
    int score = 0; 
    //Creates a new trivia game  
    //Sets up three original questions 
    //Sets up loop for user to input his or her own questions. 
    //Quiz questions are stored in linked list. 
     
    init_question_list(node_list); 
    
    cout << "\n*** Welcome to Davis' trivia quiz game ***\n"; 
    add_question(node_list);   
    
    //This is start of Trivia quiz game. 
    ask_question(node_list, node_list.count, score); 
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl; 
#endif 
    return 0;
}
 
 
//initializes the quiz to have these three questions inputted into the linked list. 
void init_question_list(trivia_list& q_list) {  
    trivia_node *question1 = new trivia_node; 
    trivia_node *question2 = new trivia_node;
    trivia_node *question3 = new trivia_node;

    question1 -> question = "How long was the shortest war on record? (Hint: how many minutes)"; 
    question1 -> answer = "38"; 
    question1 -> point = 100; 
    question1 -> next = question2;

    question2 -> question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    question2 -> answer = "Bank of Italy";
    question2 -> point = 50;
    question2 -> next = question3; 

    question3 -> question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    question3 -> answer = "Wii Sports";
    question3 -> point = 20;
    question3 -> next = NULL;
    
    q_list.head = question1;
    q_list.root = question3;
    q_list.count += 3;
} 

//gives user the option to add a question to the linked list. 
//question is added to the front of the linked list. 
void add_question(trivia_list& q_list) { 
 string yn = ""; 
 bool keepGoing = true;
 //gets data from user. 
    do {
      q_list.count++;
      trivia_node *new_ptr = new trivia_node;
      cout << "Enter a question: "; 
      getline(cin, new_ptr -> question);

      cout << "Enter an answer: "; 
      getline(cin, new_ptr -> answer);

      cout << "Enter award points: ";
      cin >> new_ptr -> point;

      cout << "Continue? (Yes/No): ";
      getline(cin.ignore(), yn);

      q_list.root -> next = new_ptr;
      q_list.root = new_ptr;

      if (yn == "No" || yn == "no") {
          keepGoing = false;
      }
      
  } while (keepGoing);
} 

//Checks for null value 
//Ask the user trivia questions and starts the game 
int ask_question(trivia_list q_list, int num_ask, int& score) {  
    int num_of_questions = q_list.count;
    if (q_list.head == NULL) {
        return 3;
    }

    trivia_node *cur_ptr = q_list.head;

    if (num_ask < 1) { 
        cout << "\nWarning - the number of trivia to be asked must equal to or be larger than 1.";
        return 1;
    } 
    if (num_of_questions < num_ask) { 
        cout << "\nWarning - There are only " << num_of_questions << " trivia in the list." << endl; 
        return 2;
    } 

    score = 0;
    string user_answer = "";
 
    for(int x = 0; x < num_ask; x++) { 
        cout << "\nQuestion: " << cur_ptr -> question << endl; 
        cout << "Answer: "; 
        getline(cin, user_answer); 
        if (user_answer.compare(cur_ptr -> answer) == 0) { 
            cout << "Your answer is correct. You receive " << cur_ptr -> point << " points.";
            score += cur_ptr -> point;
        } 
        else {  
            cout << "Your answer is wrong. The correct answer is " << cur_ptr -> answer << endl;
        } 
        cout << "\nYour Total Points: " << score << endl;
        cur_ptr = cur_ptr -> next;
    }
    return 0;  
}
 
 
 
//Test cases to check whether the methods work. 
void Unit_Test() { 
    trivia_list node_list; 
    int score;
    init_question_list(node_list); 
    cout << "***This is a debuggion version ***\n";
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message."; 
    assert(ask_question(node_list, 0, score) == 1); 
    cout << "\nCase 1 Passed\n\n"; 
    
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect\nanswer."; 
    assert(ask_question(node_list, 1, score) == 0);
    assert(0 == score);
    cout << "\nCase 2.1 passed\n";

    cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct\nanswer."; 
    assert(ask_question(node_list, 1, score) == 0);
    assert(100 == score);
    cout << "\nCase 2.2 passed\n";

    cout << "\nUnit Test Case 3: Ask all the questions of the last trivia in the linked list.";
    assert(ask_question(node_list, 3, score) == 0);
    cout << "\nCase 3 passed\n";

    cout << "\nUnit Test Case 4: Ask 5 questions in the linked list.";
    assert(ask_question(node_list, 5, score) == 2);
    cout << "\nCase 4 passed\n";
    
    cout << "\n*** End of the Debugging Version ***" << endl; 
} 
 
 
 
 
 
 
