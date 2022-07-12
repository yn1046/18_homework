#pragma once

#include <string>
#include <utility>

class Message {
    std::string _text;
    std::string _sender;
    std::string _receiver;

public:
    Message(std::string text, std::string sender, std::string receiver) :
            _text{std::move(text)},
            _sender{std::move(sender)},
            _receiver{std::move(receiver)} {

    }

    [[nodiscard]]
    auto get_text() const -> std::string {
        return _text;
    }

    [[nodiscard]]
    auto get_sender() const -> std::string {
        return _sender;
    }

    [[nodiscard]]
    auto get_receiver() const -> std::string {
        return _receiver;
    }

};