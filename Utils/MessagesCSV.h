#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "../Models/Message.h"

void write_messages(std::ostream &o, const std::vector<std::shared_ptr<Message>> &messages) {
    for (const auto &m: messages) {
        o << m->get_text() << ';' << m->get_sender() << ';' << m->get_receiver() << '\n';
    }
}

void write_messages(std::ostream &&o, const std::vector<std::shared_ptr<Message>> &messages) {
    write_messages(o, messages);
}

auto read_messages(std::istream &i) -> std::vector<std::shared_ptr<Message>> {
    auto messages = std::vector<std::shared_ptr<Message>>();
    auto line = std::string{};

    while (std::getline(i, line)) {
        auto pos = line.find_first_of(';');
        auto pos2 = line.find_last_of(';');
        messages.push_back(std::make_shared<Message>(
                std::string{line, 0, pos},
                std::string{line, pos + 1, pos2 - pos - 1},
                std::string{line, pos2 + 1}));
    }

    return messages;
}

auto read_messages(std::istream &&i) -> std::vector<std::shared_ptr<Message>> {
    return read_messages(i);
}