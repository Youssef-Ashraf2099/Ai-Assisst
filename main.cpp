#include <iostream>
#include <string>
#include <algorithm> // For transform function

using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}



int main() {    
    string userInput;

    cout << "Interactive Assistant: Type 'bye' to exit." << endl;
    while (true) {
        // get user input
    }

    return 0;
}
