//
// Created by JoachimWagner on 01.06.2023.
//

#pragma once

#include <string>
#include <ostream>

class person {

    std::string id;
    std::string vorname;
    std::string nachname;

public:
    person(const std::string &vorname, const std::string &nachname) : vorname(vorname), nachname(nachname) {}

    const std::string &getId() const {
        return id;
    }

    void setId(const std::string &idx) {
        id = idx;
    }

    const std::string &getVorname() const {
        return vorname;
    }

    void setVorname(const std::string &vorname_) {
        vorname = vorname_;
    }

    const std::string &getNachname() const {
        return nachname;
    }

    void setNachname(const std::string &nachname_) {
        nachname = nachname_;
    }

    bool operator==(const person &rhs) const {
        return id == rhs.id &&
               vorname == rhs.vorname &&
               nachname == rhs.nachname;
    }

    bool operator!=(const person &rhs) const {
        return !(rhs == *this);
    }
};

