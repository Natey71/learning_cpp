

#include <stdio.h>
// Used for reading and writing files
#include <iostream>
#include <fstream>
#include <string>
// this is for a clock / time so we can watch how long the process takes in ms
#include <chrono>
using namespace std;

void function_readFile(char delim) {
    cout << "This is the funciton that handles tabl files \n\n";

    
    ifstream myFile("C:/Users/NM4127/Downloads/file_one_test_list.txt");
    std::string line;
    
    if (myFile.is_open()) {
        // Grab
        auto start_time = std::chrono::high_resolution_clock::now();
        // Adding '\t' to getline() makes the program seperate on the Tabs
        //      Removing the \t param will result in the program printing out line by line as they appear in the file
        //      Otherwise with splitting on tab each variable gets printed out on a new line
        while (getline(myFile, line, delim)) {

            cout << line << endl;

        }
        // Close the file stream showing we are done using the file
        myFile.close();
        // 
        auto end_time = std::chrono::high_resolution_clock::now();

        // Print out the time it took to process the file. 
        std::cout << "PRocessing Time: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
            << " milliseconds\n";
    }
    

    
}

int main()
{
    

    int x;
    cout << "Choose an option below\n";
    cout << "1.) Read .txt file with Tab delimeter\n";
    cout << "2.) Read .txt file with Comma delimeter\n";
    cin >> x;
    switch (x) {
    case 1:
        function_readFile('\t');
        break;
    case 2:
        function_readFile(',');
        break;
    default:
        cout << "Error, bad input \n The Program is closing \n";
        break;
    }
    cin.get();

}
