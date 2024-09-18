#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void caesarEncrypt(string &message, int key) {
    for (char &ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + key) % 26 + base;
        }
    }
}

void caesarDecrypt(string &message, int key) {
    caesarEncrypt(message, 26 - key); // Decrypting is same as encrypting with (26 - key)
}

int main() {
    string message;
    int key,key1;

    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Enter key (1-25): ";
    cin >> key;

    cout << "Original Message: " << message << endl;

    caesarEncrypt(message, key);
    cout << "Encrypted Message: " << message << endl;
   
   cout<<"Enter the for Decryption:";
   cin>>key1;
    if(key==key1){
	
	   
    caesarDecrypt(message, key);
    cout << "Decrypted Message: " << message << endl;}
    else{
    	cout<<"Invalid key";
	}

    return 0;
}
