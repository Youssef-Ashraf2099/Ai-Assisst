#include <iostream>
#include <string>
#include <algorithm> // For transform function

using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}
// Function to simulate a simple memory (e.g., user's name)
void rememberUser(std::string input, std::string &userName) {
    size_t pos = input.find("my name is");
    if (pos != std::string::npos) {
        userName = input.substr(pos + 11); // Extracts the name part
        std::cout << "Assistant: Nice to meet you, " << userName << "!" << std::endl;
    }
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
        
   cout << "NOTE: Interactive Assistant: Type 'bye' to exit." << endl;
    while (true) {
        cout << "You: ";
        getline(cin, userInput);
        
        // Convert input to lowercase for easier matching
        toLowerCase(userInput);

        if (userInput == "bye") {
            respondToUser(userInput);
            break;
        }

        respondToUser(userInput);
    }

    return 0;
}
