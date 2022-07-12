#pragma once

#include <string>
#include <utility>

class User {
    std::string _name;
    std::string _login;
    std::string _pass;
public:
    User(std::string name, std::string login, std::string pass) :
            _name{std::move(name)},
            _login{std::move(login)},
            _pass{std::move(pass)} {

    }

    [[nodiscard]]
    auto get_name() const -> std::string {
        return _name;
    }

    [[nodiscard]]
    auto get_login() const -> std::string {
        return _login;
    }

    [[nodiscard]]
    auto get_pass() const -> std::string {
        return _pass;
    }

};