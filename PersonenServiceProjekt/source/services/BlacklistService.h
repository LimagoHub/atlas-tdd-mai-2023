//
// Created by JoachimWagner on 01.06.2023.
//

#pragma once


#include "../persistence/person.h"

class BlacklistService {
public:
    virtual bool is_blacklisted(const person &possibleBlacklistedPerson) const =0;
};
