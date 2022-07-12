#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "Models/Message.h"
#include "Utils/MessagesCSV.h"
#include "Models/User.h"
#include "Utils/UsersCSV.h"

using namespace std;

#define MESSAGE_FILE "msgs.csv"
#define USER_FILE "msgs.csv"

// Закомментированный код отвечает за создание CSV-файлов
int main() {
//    auto msg = make_shared<Message>("text text", "you", "me");
//    auto msg2 = make_shared<Message>("response", "me", "you");
//    vector<shared_ptr<Message>> messages_w{msg, msg2};
//    write_messages(ofstream{MESSAGE_FILE}, messages_w);

    vector<shared_ptr<Message>> messages = read_messages(ifstream{MESSAGE_FILE});
    for (const auto &m: messages) {
        cout << "[from] " << m->get_sender() << endl;
        cout << "[to] " << m->get_receiver() << endl;
        cout << "[text] " << m->get_text() << endl << endl;
    }

//    auto usr = make_shared<User>("Ivan Petrov", "log1", "pswd");
//    auto usr2 = make_shared<User>("Petr Ivanoff", "log2", "qwerty");
//    vector<shared_ptr<User>> users_w{usr, usr2};
//    write_users(ofstream{USER_FILE}, users_w);

    vector<shared_ptr<User>> users = read_users(ifstream{USER_FILE});
    for (const auto &u: users) {
        cout << "[name] " << u->get_name() << endl;
        cout << "[login] " << u->get_login() << endl;
        cout << "[pass length] " << u->get_pass().length() << endl << endl;
    }


    return 0;
}
