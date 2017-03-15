//
// Created by Nihal.Talur19 on 3/14/2017.
//

#pragma once

#include <stdexcept>

class NotImplementedException : public std::logic_error {
public:
    NotImplementedException() : std::logic_error("The method or operation is not implemented.") {};
};