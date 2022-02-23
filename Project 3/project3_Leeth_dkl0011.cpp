/* FILE NAME: project3_Leeth_dkl0011.cpp
 * AUTHOR: Davis Leeth (dkl0011@auburn.edu)
 *
 * Complile: g++ project3_Leeth_dkl0011.cpp -o p3.out
 * Run: ./p3.out
 *
 * Comments: Used Dr. Li's hints for help along with
 * help from stackoverflow.com to learn about vectors.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;

/*
 * Input: string name of the file being read
 * Return: vector of the ints from the file
 */
vector<int> readFile(string);

/*
 * Input: string name of the file being checked
 * Return: boolean of the validity of the file
 */
bool checkFile(string);

/*
 * Input: string name of file that is being written
 *   and vector of ints that is being transcribed onto the file
 */
void writeFile(string, vector<int>);

/*
 * Input: two vectors that are being merged
 * Return: sorted merged vector
 */
vector<int> merge(vector<int>, vector<int>);

/*
 * Merge the numbers in two specified files and write all the numbers
 * to a specified third file sorted in ascending order.
 *
 * Return: 1 Program completed successfully. (int)
 */
int main() {
    // variables
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    string fileName1;
    string fileName2;
    string outFile;

    cout << "*** Welcome to Davis' sorting program ***\nEnter the first"
         << " input file name: ";

    // Gets name of file one.
    do {
        cin >> fileName1;
    } while (cin.fail() || !checkFile(fileName1));

    // Gets and displays numbers from file one.
    v1 = readFile(fileName1);
    cout << "The list of " << v1.size() << " numbers in file " << fileName1
         << " is:\n";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << endl;
    }

    cout << "\nEnter the second input file name: ";

    // Gets name of file two.
    do {
        cin >> fileName2;
    } while (cin.fail() || !checkFile(fileName2));

    // Gets and displays numbers from file two.
    v2 = readFile(fileName2);
    cout << "The list of " << v2.size() << " numbers in file " << fileName2
         << " is:\n";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << endl;
    }

    // Merges and displays numbers from both files.
    v3 = merge(v1, v2);
    cout << "\nThe sorted list of " << v3.size() << " numbers is: ";
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << "\nEnter the output file name: ";

    // Gets name of output file.
    do {
        cin >> outFile;
    } while (cin.fail());

    // Writes combined vector to output file.
    writeFile(outFile, v3);

    cout << "*** Please check the new file - " << outFile << " ***"
         << "\n*** Goodbye. ***" << endl;

    return 1;
}

// Implementation of functions. Look above for documentation of them.
vector<int> readFile(string fileName) {
    ifstream stream;
    vector<int> v;
    int i;
    string line;
    stream.open((char*)fileName.c_str());
    while (getline(stream, line)) {
        stringstream(line) >> i;
        v.push_back(i);
    }
    stream.close();
    return v;
}

bool checkFile(string fileName) {
    ifstream stream;
    stream.open((char*)fileName.c_str());
    if (stream.fail()) {
        cout << "Input file opening failed." << endl;
        return false;
    }
    stream.close();

    return true;
}

void writeFile(string fileName, vector<int> v) {
    ofstream stream;
    stream.open((char*)fileName.c_str(), ios::out);

    for (int i = 0; i < v.size(); i++) {
        stream << v[i] << endl;
    }
    stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> v3;
    int v1i = 0;
    int v2i = 0;

    while (v1.size() != 0 && v2.size() != 0) {
        if (v1[v1i] < v2[v2i]) {
            v3.push_back(v1[v1i]);
            v1.erase(v1.begin());
        }
        else if (v1[v1i] > v2[v2i]) {
            v3.push_back(v2[v2i]);
            v2.erase(v2.begin());
        }
        else if (v1[v1i] == v2[v2i]) {
            v3.push_back(v1[v1i]);
            v1.erase(v1.begin());
            v3.push_back(v2[v2i]);
            v2.erase(v2.begin());
        }
    }

    if (v1.size() != 0) {
        for (int i = 0; i < v1.size(); i++) {
            v3.push_back(v1[i]);
        }
    }
    if (v2.size() != 0) {
        for (int i = 0; i < v2.size(); i++) {
            v3.push_back(v2[i]);
        }
    }

    return v3;
}
