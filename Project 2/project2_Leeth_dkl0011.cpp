/* FILE NAME: project2_Leeth_dkl0011.cpp
* AUTHOR: Davis Leeth (dkl0011@auburn.edu)
*
* Complile: g++ project2_Leeth_dkl0011.cpp -o p2.out 	
* Run: ./p2.out 
*
* Comments: Used Dr. Li's hints for help.
*/
 
#include <iostream> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctime> 
using namespace std; 

/* 
* Input: A_alive indicates Aaron is alive true for alive, false for dead 
*   B_alive indicates Bob is alive 
*   C_alive indicates Charlie is alive 
* Return: true if at least two are alive otherwise return false 
*/ 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
 
/* 
* Call by reference 
* Strategy 1: Everyone shoots to kill the highest accuracy player alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Aaron_shoots1(bool& B_alive, bool& C_alive); 
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  C_alive indicates Charlie is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Bob_shoots(bool& A_alive, bool& C_alive); 
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  B_alive indicates Bob is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change B_alive into false if Bob is killed 
*/ 
void Charlie_shoots(bool& A_alive, bool& B_alive); 
 
/* 
* Call by reference 
* Strategy 2: Aaron intentionally misses if both are alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Aaron_shoots2(bool& B_alive, bool& C_alive); 
 
//Simple method to implement pause function in linux 
void PressAnyKey(void);
 
//TEST PROTOTYPES 
void test_at_least_two_alive(void); 
void test_Aaron_shoots1(void); 
void test_Bob_shoots(void); 
void test_Charlie_shoots(void); 
void test_Aaron_shoots2(void); 
 
//VARIABLES 
const int TOTAL_RUNS = 10000;
const int aaronHits = 33;
const int bobHits = 50;
bool charlie_a = true;
bool bob_a = true;
bool aaron_a = true;
int aaronWins1 = 0;
int aaronWins2 = 0;
int bobWins = 0;
int charlieWins = 0;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;
 
int main() { 
 //Initializes Random number generator's seed and calls test functions 
 cout << "*** Welcome to Davis' Duel Simulator ***\n"; 
 srand(time(0)); 
 test_at_least_two_alive(); 
 PressAnyKey(); 
 test_Aaron_shoots1(); 
 PressAnyKey(); 
 test_Bob_shoots(); 
 PressAnyKey(); 
 test_Charlie_shoots(); 
 PressAnyKey(); 
 test_Aaron_shoots2(); 
 PressAnyKey(); 
  
 //Starts strategy 1 and runs 10,000 times 
 cout << "Ready to test strategy 1 (run 10000 times):\n"; 
 PressAnyKey(); 

 for (int i = 0; i < TOTAL_RUNS; i++){  

     aaronAlive = true;
     bobAlive = true;
     charlieAlive = true;

  while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) { 
       if (aaronAlive) {
          Aaron_shoots1(bobAlive, charlieAlive);
      }
      if (bobAlive) {
          Bob_shoots(aaronAlive, charlieAlive);
      }
      if (charlieAlive) {
          Charlie_shoots(aaronAlive, bobAlive);
      } 
   }  
      if (aaronAlive){  
        aaronWins1++; 
      }
      if (bobAlive) {
        bobWins++; 
      }
      if (charlieAlive)  {
        charlieWins++;  
      } 
 }
 cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / 
TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
* 100 << "%\n" 
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
TOTAL_RUNS * 100 << "%\n" 
      << endl; 
  
 //Reinitializes variables and starts strategy 2 to run 10,000 times 
 bobWins = 0;
 charlieWins = 0;
 cout << "Ready to test strategy 2 (run 10000 times):\n"; 
 PressAnyKey(); 
 for (int i = 0; i < TOTAL_RUNS; i++){  

     aaronAlive = true;
     bobAlive = true;
     charlieAlive = true;

  while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) { 
      if (aaronAlive) {
          Aaron_shoots2(bobAlive, charlieAlive);
      }
      if (bobAlive) {
          Bob_shoots(aaronAlive, charlieAlive);
      }
      if (charlieAlive) {
          Charlie_shoots(aaronAlive, bobAlive);
      } 
   }  
      if (aaronAlive){  
        aaronWins2++; 
      }
      if (bobAlive) {
        bobWins++; 
      }
      if (charlieAlive)  {
        charlieWins++;  
      } 
 }

    cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / 
    TOTAL_RUNS * 100 << "%\n" 
        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
    * 100 << "%\n" 
        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
    TOTAL_RUNS * 100 << "%\n" 
        << endl; 
  
 if (aaronWins1 > aaronWins2) { 
  cout << "Strategy 1 is better than strategy 2.\n"; 
 } 
 else { 
  cout << "Strategy 2 is better than strategy 1.\n"; 
 } 
  
 return 0; 
} 
 
//Implementation of functions. Look above for documentation of them. 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) { 
    int numAlive = 0;
    if (A_alive) {
        numAlive++;
    }
    if (B_alive) {
        numAlive++;
    }
    if (C_alive) {
        numAlive++;
    }
    if (numAlive >= 2) {
        return true;
    }
    else {
        return false;
    }
} 
 
void test_at_least_two_alive(void) { 
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "Case passed ...\n";

    cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "Case passed ...\n";

    cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "Case passed ...\n";

    cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "Case passed ...\n";

    cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "Case passed ...\n";

    cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "Case passed ...\n";

    cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "Case passed ...\n";

    cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "Case passed ...\n";    
} 
 
void Aaron_shoots1(bool& B_alive, bool& C_alive) {  
    assert(true == aaronAlive);
 int shootResult = rand() % 100; 
 if (C_alive) { 
     if (shootResult < aaronHits) {
         C_alive = false;
     }
 } 
 else { 
     if (shootResult < aaronHits) {
         B_alive = false;
     }
 } 
} 
 
void test_Aaron_shoots1(void) { 
 cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n"; 
  bob_a = true;
  charlie_a = true;
 cout << "\tCase 1: Bob alive, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 Aaron_shoots1(bob_a, charlie_a); 
 assert(true == bob_a);
  
 bob_a = false; 
 charlie_a = true; 
 cout << "\tCase 2: Bob dead, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 Aaron_shoots1(bob_a, charlie_a); 
 assert(false == bob_a);
 
 bob_a = true; 
 charlie_a = false; 
 cout << "\tCase 3: Bob alive, Charlie dead\n" 
      << "\t\tAaron is shooting at Bob\n"; 
 Aaron_shoots1(bob_a, charlie_a); 
 assert(false == charlie_a);
} 
 
void Bob_shoots(bool& A_alive, bool& C_alive) { 
    assert(true == bobAlive);
 int shootResult = rand() % 100; 
 if (C_alive) { 
     if (shootResult < bobHits) {
         C_alive = false;
     }
 } 
 else { 
     if (shootResult < bobHits) {
         A_alive = false;
     }
 } 
} 
 
void test_Bob_shoots(void) { 
 cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n"; 
  aaron_a = true;
  charlie_a = true;
 cout << "\tCase 1: Aaron alive, Charlie alive\n" 
      << "\t\tBob is shooting at Charlie\n"; 
 Bob_shoots(aaron_a, charlie_a); 
 assert(true == aaron_a);
  
 aaron_a = false; 
 charlie_a = true; 
 cout << "\tCase 2: Aaron dead, Charlie alive\n" 
      << "\t\tBob is shooting at Charlie\n"; 
 Bob_shoots(aaron_a, charlie_a); 
 assert(false == aaron_a);
 
 aaron_a = true; 
 charlie_a = false; 
 cout << "\tCase 3: Aaron alive, Charlie dead\n" 
      << "\t\tBob is shooting at Aaron\n"; 
 Bob_shoots(aaron_a, charlie_a); 
 assert(false == charlie_a); 
  
} 
  
void Charlie_shoots(bool& A_alive, bool& B_alive) { 
    assert(true == charlieAlive);
 if (B_alive) { 
         B_alive = false;
    } 
 else { 
         A_alive = false;
    }  
} 
 
void test_Charlie_shoots(void) { 
 cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n"; 
  aaron_a = true;
  bob_a = true;
  charlie_a = true;
 cout << "\tCase 1: Aaron alive, Bob alive\n" 
      << "\t\tCharlie is shooting at Bob\n"; 
 Charlie_shoots(aaron_a, bob_a); 
 assert(true == aaron_a);
  
 aaron_a = false; 
 bob_a = true; 
 cout << "\tCase 2: Aaron dead, Bob alive\n" 
      << "\t\tCharlie is shooting at Bob\n"; 
 Charlie_shoots(aaron_a, bob_a); 
 assert(false == aaron_a);
 
 aaron_a = true; 
 bob_a = false; 
 cout << "\tCase 3: Aaron alive, Bob dead\n" 
      << "\t\tCharlie is shooting at Aaron\n"; 
 Charlie_shoots(aaron_a, bob_a); 
 assert(false == bob_a); 
 } 
 
void Aaron_shoots2(bool& B_alive, bool& C_alive) { 
    assert(true == aaronAlive);
 int shootResult = rand() % 100; 
 if (C_alive && B_alive) { 
     return; 
 } 
 else { 
    if (C_alive) { 
        if (shootResult < aaronHits) {
            C_alive = false;
        }
    } 
    else { 
        if (shootResult < aaronHits) {
            B_alive = false;
        }
    } 
 } 
} 
 
void test_Aaron_shoots2(void) { 
 cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n"; 
  bob_a = true;
  charlie_a = true;
  aaron_a = true;
 cout << "\tCase 1: Bob alive, Charlie alive\n" 
      << "\t\tAaron intentionally misses his first shot\n"
      << "\t\tBoth Bob and Charlie are alive.\n"; 
 Aaron_shoots2(bob_a, charlie_a); 
 assert(true == bob_a);
  
 bob_a = false; 
 charlie_a = true; 
 cout << "\tCase 2: Bob dead, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 Aaron_shoots2(bob_a, charlie_a); 
 assert(false == bob_a);
 
 bob_a = true; 
 charlie_a = false; 
 cout << "\tCase 3: Bob alive, Charlie dead\n" 
      << "\t\tAaron is shooting at Bob\n"; 
 Aaron_shoots2(bob_a, charlie_a); 
 assert(false == charlie_a); 
} 
 
void PressAnyKey(void) { 
 cout << "Press any key to continue..."; 
 cin.ignore().get();  
} 
