//
// Created by Quinn.Tucker18 on 3/18/2017.
//

#pragma once

namespace util {

    template<class Stack>
    auto pop(Stack& c) -> std::remove_reference_t<decltype(c.pop(), c.top())> {
        auto value = std::move(c.top());
        c.pop();
        return std::move(value);
    }
    template<class Queue>
    auto pop(Queue& c) -> std::remove_reference_t<decltype(c.pop(), c.front())> {
        auto value = std::move(c.front());
        c.pop();
        return std::move(value);
    }
    template<class Vector>
    auto pop(Vector& c) -> std::remove_reference_t<decltype(c.pop_back(), c.back())> {
        auto value = std::move(c.back());
        c.pop_back();
        return std::move(value);
    }

}