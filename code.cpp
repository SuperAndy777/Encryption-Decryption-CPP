#include <iostream>
#include <string>
using namespace std;

// A class to represent an encryption/decryption system
class Encryptor
{
private:
    int key; // The key to use for encryption/decryption
public:
    // Making Constructor to initialize the key
    Encryptor(){};
    Encryptor(int k)
    {
        key = k;
    }

    // A function to encrypt message by XOR operation
    string encrypt1(string message)
    {
        string encrypted = "";
        for (char c : message)
        {
            encrypted += c ^ key; // XOR each character with the key
        }
        return encrypted;
    }
    // A function to encrypt message by reversing the string
    string encrypt2(string message)
    {
        string encrypted = "";
        for (int i = message.length() - 1; i >= 0; i--)
        {
            encrypted += message[i];
        }
        return encrypted;
    }
    // A function to encrypt message by shifting the letters of the string
    string encrypt3(string message, int shift)
    {
        string encrypted = "";
        for (char c : message)
        {
            encrypted += (c + shift);
        }
        return encrypted;
    }

    // A function to decrypt messageby XOR operation
    string decrypt1(string encrypted)
    {
        string decrypted = "";
        for (char c : encrypted)
        {
            decrypted += c ^ key; // XOR each character with the key
        }
        return decrypted;
    }
    // A function to decrypt message by reversing the string
    string decrypt2(string encrypted)
    {
        string decrypted = "";
        for (int i = encrypted.length() - 1; i >= 0; i--)
        {
            decrypted += encrypted[i];
        }
        return decrypted;
    }
    // A function to decrypt message by shifting the letters of string
    string decrypt3(string encrypted, int shift)
    {
        string decrypted = "";
        for (char c : encrypted)
        {
            decrypted += (c - shift);
        }
        return decrypted;
    }
};

int main()
{
    string message;
    int typeE, key;
    int choice;

    cout << "_________________________The Cipherer _________________________" << endl;
    cout << "_________________________WELCOME USER!_________________________" << endl;

    cout << "Enter 1 for ENCRYTPION" << endl
         << "Enter 2 for DECRYPTION" << endl;
    cin >> choice;

    Encryptor t2;

    if (choice == 1)
    {
        cout << "____---You selected ENCRYPTION____---" << endl;
        cout << "Select the type of encryption:" << endl
             << "Enter 1 for Encryption Type1," << endl
             << "Enter 2 for Encryption Type2," << endl
             << "Enter 3 for Encryption Type3." << endl;
        cin >> typeE;

        if (typeE == 1)
        {
            cout << "Enter string to Encrypt:" << endl;
            cin >> message;
            cout << "Enter key for Encryption:" << endl;
            cin >> key;                                         // The key to use for encryption/decryption
            Encryptor e(key);                                   // Create an object of the Encryptor class
            string encrypted = e.encrypt1(message);             // Encrypt the message using the object
            cout << "Encrypted message: " << encrypted << endl; // Print the encrypted message
        }
        else if (typeE == 2)
        {
            cout << "Enter string to encrypt:" << endl;
            cin >> message;

            string encrypted = t2.encrypt2(message); // Encrypt the message using the object
            cout << "Encrypted message: " << encrypted << endl;
        }
        else if (typeE == 3)
        {
            cout << "Enter string to encrypt:" << endl;
            cin >> message;
            int shift;
            cout << "Enter key:" << endl;
            cin >> shift;
            string encrypted = t2.encrypt3(message, shift);
            cout << "Encrypted message: " << encrypted << endl;
        }
        else
        {
            cout << "Enter valid type!";
        }
    }

    else if (choice == 2)
    {
        cout << "____---You selected DECRYPTION____---" << endl;
        cout << "Select the type of decryption:" << endl
             << "Enter 1 for Decryption Type1," << endl
             << "Enter 2 for Decryption Type2," << endl
             << "Enter 3 for Decryption Type3." << endl;
        cin >> typeE;

        if (typeE == 1)
        {
            cout << "Enter string encrypted by Type1 encryption to decrypt: " << endl;
            cin >> message;
            cout << "Enter key for Decryption: " << endl;
            cin >> key;                             // The key to use for encryption/decryption
            Encryptor e(key);                       // Create an object of the Encryptor class
            string decrypted = e.decrypt1(message); // Encrypt the message using the object
            cout << "Decrypted message: " << decrypted << endl;
        }
        else if (typeE == 2)
        {
            cout << "Enter string encrypted by Type2 encryption to decrypt:" << endl;
            cin >> message;

            string decrypted = t2.decrypt2(message); // Encrypt the message using the object
            cout << "Decrypted message: " << decrypted << endl;
        }
        else if (typeE == 3)
        {
            cout << "Enter string encrypted by Type3 encryption to decrypt: " << endl;
            cin >> message;
            int shift;
            cout << "Enter key: " << endl;
            cin >> shift;
            string decrypted = t2.decrypt3(message, shift);
            cout << "Decrypted message: " << decrypted << endl;
        }
        else
        {
            cout << "Enter valid type!";
        }
    }

    else
    {
        cout << "Enter only 1 or 2 !!";
    }
    return 0;
}