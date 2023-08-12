/*
Implement a messaging application where users can send and receive messages. Use message passing to simulate the messaging process.

Input:
    User user1("Alice");
    User user2("Bob");

    Message msg1("Alice", "Bob", "Hi Bob! How's it going?");
    Message msg2("Bob", "Alice", "Hey Alice! I'm good. How about you?");

    user1.receiveMessage(msg2);
    user2.receiveMessage(msg1);

    user1.displayInbox();
    user2.displayInbox();


Output:

Inbox for user Alice:
From: Bob
To: Alice
Message: Hey Alice! I'm good. How about you?
--------------
Inbox for user Bob:
From: Alice
To: Bob
Message: Hi Bob! How's it going?
--------------

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a Message class to represent a message between two users
class Message {
private:
    string sender;
    string receiver;
    string content;

public:
    // Constructor to initialize the message with sender, receiver, and content
    Message(string s, string r, string c) : sender(s), receiver(r), content(c) {}

    // Display the message details
    void display() {
        cout << "From: " << sender << "\nTo: " << receiver << "\nMessage: " << content << endl;
    }
};

// Define a User class to represent a user with a username and an inbox of messages
class User {
private:
    string username;
    vector<Message> inbox;

public:
    // Constructor to initialize a user with a given username
    User(string name) : username(name) {}

    // Method to receive a message and add it to the user's inbox
    void receiveMessage(Message msg) {
        inbox.push_back(msg);
    }

    // Display the messages in the user's inbox
    void displayInbox() {
        cout << "Inbox for user " << username << ":\n";
        for (auto& msg : inbox) {
            msg.display();
            cout << "--------------\n";
        }
    }
};

int main() {
    // Create two users: Alice and Bob
    User user1("Alice");
    User user2("Bob");

    // Create two messages: one from Alice to Bob, and another from Bob to Alice
    Message msg1("Alice", "Bob", "Hi Bob! How's it going?");
    Message msg2("Bob", "Alice", "Hey Alice! I'm good. How about you?");

    // User1 (Alice) receives the message from user2 (Bob) and vice versa
    user1.receiveMessage(msg2);
    user2.receiveMessage(msg1);

    // Display the inbox for both users
    user1.displayInbox();
    user2.displayInbox();

    return 0;
}

/*
This program simulates a messaging application using message passing. The Message class represents a message with a sender, receiver, and content. The User class represents a user with an inbox to receive messages.

In the main() function, two User objects, user1 and user2, are created. Messages msg1 and msg2 are created and sent between the users using the receiveMessage() method, which utilizes message passing to add messages to the user's inbox.

The displayInbox() method is used to display the inbox of each user, showing the messages received.

*/

