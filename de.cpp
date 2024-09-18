#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void vigenereEncrypt(string &message, const string &key) {
    int msgLen = message.length();
    int keyLen = key.length();
    
    for (int i = 0, j = 0; i < msgLen; i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = tolower(key[j % keyLen]) - 'a';
            message[i] = (ch - base + keyChar) % 26 + base;
            j++;
        }
    }
}

void vigenereDecrypt(string &message, const string &key) {
    int msgLen = message.length();
    int keyLen = key.length();
    
    for (int i = 0, j = 0; i < msgLen; i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = tolower(key[j % keyLen]) - 'a';
            message[i] = (ch - base - keyChar + 26) % 26 + base;
            j++;
        }
    }
}

int main() {
    string message, key;

    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Enter key: ";
    getline(cin, key);

    cout << "Original Message: " << message << endl;

    vigenereEncrypt(message, key);
    cout << "Encrypted Message: " << message << endl;

    vigenereDecrypt(message, key);
    cout << "Decrypted Message: " << message << endl;

    return 0;
}
