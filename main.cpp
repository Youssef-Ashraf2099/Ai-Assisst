#include <iostream>
#include <string>
#include <algorithm> // For transform function

using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void respondToUser(const string &input) {
    if (input.find("hello") != string::npos) {
        cout << "Assistant: Hello! How can I help you today?" << endl;
    } else if (input.find("how are you") != string::npos) {
        cout << "Assistant: I'm just a program, but I'm doing great! How can I assist you?" << endl;
    } else if (input.find("bye") != string::npos) {
        cout << "Assistant: Goodbye! Have a great day!" << endl;
    } else {
        cout << "Assistant: I'm not sure how to respond to that. Could you try rephrasing?" << endl;
    }
}
int main() {    
    string userInput;

    cout << "Interactive Assistant: Type 'bye' to exit." << endl;
    while (true) {
        // get user input
    }

    return 0;
}
