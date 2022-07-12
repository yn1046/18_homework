#pragma once

#include <iostream>
#include <vector>
#include "../Models/User.h"

void write_users(std::ostream &o, const std::vector<std::shared_ptr<User>> &users) {
    for (const auto &u: users) {
        o << u->get_name() << ';' << u->get_login() << ';' << u->get_pass() << '\n';
    }
}

void write_users(std::ostream &&o, const std::vector<std::shared_ptr<User>> &users) {
    write_users(o, users);
}

auto read_users(std::istream &i) -> std::vector<std::shared_ptr<User>> {
    auto users = std::vector<std::shared_ptr<User>>();
    auto line = std::string{};

    while (std::getline(i, line)) {
        auto pos = line.find_first_of(';');
        auto pos2 = line.find_last_of(';');
        users.push_back(std::make_shared<User>(std::string{line, 0, pos},
                                 std::string{line, pos + 1, pos2-pos-1},
                                 std::string{line, pos2 + 1}));
    }

    return users;
}

auto read_users(std::istream &&i) -> std::vector<std::shared_ptr<User>> {
    return read_users(i);
}