#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <filesystem>
#include <bitset>

#include "Models/Message.h"
#include "Utils/MessagesCSV.h"
#include "Models/User.h"
#include "Utils/UsersCSV.h"

using namespace std;
namespace fs = std::filesystem;

#define MESSAGE_FILE "msgs.csv"
#define USER_FILE "usrs.csv"

void demo_perms(fs::perms p) {
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
              << '\n';
}

int main() {
    // Создание файла с сообщениями
    auto msg = make_shared<Message>("text text", "you", "me");
    auto msg2 = make_shared<Message>("response", "me", "you");
    vector<shared_ptr<Message>> messages_w{msg, msg2};
    write_messages(ofstream{MESSAGE_FILE}, messages_w);

    // Работа с правами файла
    cout << MESSAGE_FILE << " before modification" << endl;
    demo_perms(fs::status(MESSAGE_FILE).permissions());

    fs::permissions(
            MESSAGE_FILE,
            fs::perms::owner_read | fs::perms::owner_write,
            fs::perm_options::replace);
    cout << MESSAGE_FILE << " after modification" << endl;
    demo_perms(fs::status(MESSAGE_FILE).permissions());

    // Чтение файла с сообщениями
    vector<shared_ptr<Message>> messages = read_messages(ifstream{MESSAGE_FILE});
    for (const auto &m: messages) {
        cout << "[from] " << m->get_sender() << endl;
        cout << "[to] " << m->get_receiver() << endl;
        cout << "[text] " << m->get_text() << endl << endl;
    }

    // Создание файла с пользователями
    auto usr = make_shared<User>("Ivan Petrov", "log1", "pswd");
    auto usr2 = make_shared<User>("Petr Ivanoff", "log2", "qwerty");
    vector<shared_ptr<User>> users_w{usr, usr2};
    write_users(ofstream{USER_FILE}, users_w);

    // Работа с правами файла
    cout << USER_FILE << " before modification" << endl;
    demo_perms(fs::status(USER_FILE).permissions());

    fs::permissions(
            USER_FILE,
            fs::perms::owner_read | fs::perms::owner_write,
            fs::perm_options::replace);
    cout << USER_FILE << " after modification" << endl;
    demo_perms(fs::status(USER_FILE).permissions());

    // Чтение файла с пользователями
    vector<shared_ptr<User>> users = read_users(ifstream{USER_FILE});
    for (const auto &u: users) {
        cout << "[name] " << u->get_name() << endl;
        cout << "[login] " << u->get_login() << endl;
        cout << "[pass length] " << u->get_pass().length() << endl << endl;
    }


    return 0;
}
