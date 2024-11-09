#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include<regex>

using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void speak(const string &text) {
    string command = "espeak \"" + text + "\"";
    system(command.c_str());
}
// Function to simulate a simple memory (e.g., user's name)
void rememberUser(string input, string &userName) {
    size_t pos = input.find("my name is");
    if (pos != string::npos) {
        userName = input.substr(pos + 11); // Extracts the name part
        cout << "Assistant: Nice to meet you, " << userName << "!" << endl;
    }
}

// Random response generator for more natural conversation
std::string getRandomResponse(const std::vector<std::string> &responses) {
    if (responses.empty()) return "I'm not sure how to respond to that.";
    int index = rand() % responses.size();
    return responses[index];
}

// Enhanced method for responding to user input with pattern matching and context tracking
void respondToUser(const std::string &input, const std::map<std::string, std::vector<std::string>> &responseMap, const std::string &userName) {
    for (const auto &pair : responseMap) {
        std::regex pattern(pair.first, std::regex_constants::icase);
        if (std::regex_search(input, pattern)) {
            std::string response = getRandomResponse(pair.second);
            std::cout << "Assistant: " << response << std::endl;
            return;
        }
    }

    // Default response if no match is found
    std::cout << "Assistant: I'm not sure how to respond to that. Could you try rephrasing?" << std::endl;
}
int main()
{
std::string userInput, userName;
    std::map<std::string, std::vector<std::string>> responseMap = {
        {"hello", {"Hello! How can I help you today?", "Hi there! What can I do for you?", "Hey! How's it going?"}},
        {"how are you", {"I'm just a program, but I'm doing great! How can I assist you?", "I'm fine, thanks for asking! What do you need help with?"}},
        {"bye", {"Goodbye! Have a great day!", "See you later!", "Bye! Take care!"}},
        {"your name", {"I'm an interactive assistant created in C++!", "You can call me your virtual assistant."}},
        {"time", {"I'm not equipped to tell the time right now, but you can check your system clock."}}
    };

   
   
bool talkMode = false;

    cout << "NOTE: Interactive Assistant: Type 'bye' to exit." << endl;
    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        if (userInput == "bye") {
            respondToUser(userInput, responseMap, userName);
            break;
        }
        // Toggle talk mode on or off
        if (userInput == "talk") {
            talkMode = !talkMode; // Toggle the mode
            cout << "Assistant: Talk mode is now " << (talkMode ? "ON" : "OFF") << "." << endl;
            continue;
        }

        // Check if user is introducing themselves
        size_t pos = userInput.find("my name is");
        if (pos != string::npos) {
            userName = userInput.substr(pos + 11);
           cout << "Assistant: Nice to meet you, " << userName << "!" << endl;
            continue;
        }

        // Respond with context
        if (!userName.empty() && userInput.find("my name is") == string::npos) {
            cout << "Assistant: " << userName << ", ";
        }
 // Speak the response if talk mode is enabled
        if (talkMode) {
            speak(userInput);
        }
        // Generate a response
        respondToUser(userInput, responseMap, userName);
    }

    return 0;
}