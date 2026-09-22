#include <iostream>
#include <string>

using namespace std;

char toUpperChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A'); 
    }
    return c;
}

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); 
    }
    return c;
}

int main() {
    //Bài 1
    cout << "--- BAI 1: STUDENT PROFILE ---\n";
    string fullName, studentId, email, hometown;
    
    getline(cin, fullName);
    getline(cin, studentId);
    getline(cin, email);
    getline(cin, hometown);

    cout << "===== STUDENT PROFILE =====\n";
    cout << "Full name  : " << fullName << "\n";
    cout << "Student ID : " << studentId << "\n";
    cout << "Email      : " << email << "\n";
    cout << "Hometown   : " << hometown << "\n";
    cout << "===========================\n\n";

    //Bài 2
    cout << "--- BAI 2: GREETING MESSAGE ---\n";
    string name;
    getline(cin, name);

    string greeting = "Hello, " + name + "!\nWelcome to C++ programming!";
    cout << greeting << "\n\n";
    //Bài 3
    cout << "--- BAI 3: INITIALS ---\n";
    string nameForInitials;
    getline(cin, nameForInitials);

    string initials = "";
    if (!nameForInitials.empty()) {
        initials += toUpperChar(nameForInitials[0]);
        initials += '.';

        for (int i = 0; i < (int)nameForInitials.length() - 1; i++) {
            if (nameForInitials[i] == ' ' && nameForInitials[i + 1] != ' ') {
                initials += toUpperChar(nameForInitials[i + 1]);
                initials += '.';
            }
        }
    }
    cout << "Initials: " << initials << "\n\n";

    //Bài 4
    cout << "--- BAI 4: FIND A WORD ---\n";
    string sentence, word;
    getline(cin, sentence);
    getline(cin, word);

    size_t pos = sentence.find(word);
    if (pos != string::npos) {
        cout << "The word \"" << word << "\" is found at position " << pos << ".\n\n";
    } else {
        cout << "The word \"" << word << "\" was not found.\n\n";
    }
    
    //Bài 5
    cout << "--- BAI 5: CREATE A USERNAME ---\n";
    string nameForUser;
    int birthYear;

    getline(cin, nameForUser);
    cin >> birthYear;
    cin.ignore();

    string username = "";
    for (int i = 0; i < (int)nameForUser.length(); i++) {
        if (nameForUser[i] != ' ') {
            username += toLowerChar(nameForUser[i]);
        }
    }
    username += to_string(birthYear);

    cout << "Username: " << username << "\n";

    return 0;
}