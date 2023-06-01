//
// Created by JoachimWagner on 01.06.2023.
//

#pragma once

#include "gmock/gmock.h"
#include "../source/services/BlacklistService.h"

class MockBlacklistService: public BlacklistService{
public:
    MOCK_METHOD(bool, is_blacklisted, (const person& person), (const, override));
};
