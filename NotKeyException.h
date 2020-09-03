#pragma once

#include "NotFoundException.h"

#include <iostream>
#include <exception>

template<class TKey>
class NotKeyException : NotFoundException<TKey> {
public:
    NotKeyException(TKey key);
    const TKey& GetKey() const noexcept override;
    void what_happend();

private:
    TKey info;
};

template<class TKey>
NotKeyException<TKey>::NotKeyException(TKey key) : info(key) {}

template<class TKey>
const TKey& NotKeyException<TKey>::GetKey() const noexcept {
    return info;
}

template<class TKey>
void NotKeyException<TKey>::what_happend() {
    std::cout << std::endl << "Key \"" << info << "\" not in Dictionary!\n";
}