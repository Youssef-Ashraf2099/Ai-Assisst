#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include<regex>
#include <ctime>
#include <curl/curl.h>
#include <sstream>

using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}
void displayTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Assistant: The current time is ";
    cout << 1 + ltm->tm_hour-1 << ":" //Egypt Zone in winter time is early by 1 hour if summer +1
         << 1 + ltm->tm_min << ":"
         << 1 + ltm->tm_sec << "." << endl;
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
string getRandomResponse(const vector<string> &responses) {
    if (responses.empty()) return "I'm not sure how to respond to that.";
    int index = rand() % responses.size();
    return responses[index];
}

// Enhanced method for responding to user input with pattern matching and context tracking
void respondToUser(const string &input, const map<string, vector<string>> &responseMap, const string &userName,bool talkMode) {
    for (const auto &pair : responseMap) {
        regex pattern(pair.first, regex_constants::icase);
        if (regex_search(input, pattern)) {
            string response = getRandomResponse(pair.second);
            cout << "Assistant: " << response << endl;



if (regex_search(input, pattern)) {
    if (pair.first == "time") {
        displayTime();
    } else {
        string response = getRandomResponse(pair.second);
        cout << "Assistant: " << response << endl;
        if (talkMode) {
            speak(response);
        }
    }
    return;
}


             // Speak the response if talk mode is enabled
            if (talkMode) {
                speak(response);
            }
            return;
        }
    }

    // Default response if no match is found
    string defaultResponse = "I'm not sure how to respond to that. Could you try rephrasing?";
    cout << "Assistant: " << defaultResponse << endl;
    if (talkMode) {
        speak(defaultResponse);
    }
 
    }

   
int main()
{
     string userInput, userName;
    map<string, vector<string>> responseMap = {
        {"hello", {"Hello! How can I help you today?", "Hi there! What can I do for you?", "Hey! How's it going?"}},
        {"how are you", {"I'm just a program, but I'm doing great! How can I assist you?", "I'm fine, thanks for asking! What do you need help with?"}},
        {"bye", {"Goodbye! Have a great day!", "See you later!", "Bye! Take care!"}},
        {"your name", {"I'm an interactive assistant created in C++!", "You can call me your virtual assistant."}},
        {"time", {"The system clock is ..."}}
    };

   
   
bool talkMode = false;

    cout << "NOTE: Interactive Assistant: Type 'bye' to exit." << endl;
    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        if (userInput == "bye") {
            respondToUser(userInput, responseMap, userName,talkMode);
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
 /*
  Speak the response if talk mode is enabled
        if (talkMode) {
            speak(userInput);  //read the user input not needed here
        }

        */

        // Generate a response
        respondToUser(userInput, responseMap, userName,talkMode);
    }

    return 0;
}