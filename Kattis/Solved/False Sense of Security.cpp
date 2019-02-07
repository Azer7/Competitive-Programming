#include <iostream>
#include <string>

using namespace std;

string morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
int lengthOfMorses[26];

string charToMorse(char c) {
    if (c >= 65 && c <= 90) {
        return morseCodes[c - 65];
    } else {
        switch (c) {
            case '_':
                return "..--";
            case ',':
                return ".-.-";
            case '.':
                return "---.";
            case '?':
                return "----";
        }
    }
}

int charToMorseLength(char c) {
    if (c >= 65 && c <= 90) {
        return lengthOfMorses[c - 65];
    } else {
        return 4;
    }
}

char morseToChar(string morse) {
    for (int i = 0; i < 26; i++) {
        if (morse == morseCodes[i])
            return (char) (65 + i);
    }

    if (morse == "..--")
        return '_';
    else if (morse == ".-.-")
        return ',';
    else if (morse == "---.")
        return '.';
    else if (morse == "----")
        return '?';
}

int main() {
    for (int i = 0; i < 26; i++) {
        lengthOfMorses[i] = morseCodes[i].size();
    }
    string secretMessage;
    getline(cin, secretMessage);
    while (secretMessage != "") {
        string lengthString, morseMessage;
        for (int i = secretMessage.size() - 1; i >= 0; i--) {
            lengthString += charToMorseLength(secretMessage[i]);
        }
        for (int i = 0; i < secretMessage.size(); i++) {
            morseMessage += charToMorse(secretMessage[i]);
        }
        int counter = 0;
        for (int i = 0; i < secretMessage.size(); i++) {
            cout << morseToChar(morseMessage.substr(counter, (int) lengthString[i]));
            counter += lengthString[i];
        }

        getline(cin, secretMessage);
        if (secretMessage != "")
            cout << endl;
    }
    return 0;
}
