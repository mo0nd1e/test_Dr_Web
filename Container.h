#pragma once

#include "Dictionary.h"
#include "NotKeyException.h"

#include <map>

template<class TKey, class TValue>
class Container : public Dictionary<TKey, TValue> {
public:
	Container();
	const TValue& Get(const TKey& key) const override;
	void Set(const TKey& key, const TValue& value) override;
	void Remove(const TKey& key) override;
	bool IsSet(const TKey& key) const override;

	void print();

private:
	std::map<TKey, TValue> dict;
};

template<class TKey, class TValue>
Container<TKey, TValue>::Container() {}

template<class TKey, class TValue>
void Container<TKey, TValue>::print() {
	std::cout << std::endl;
	for (auto& it : dict) {
		std::cout << it.first << ' ' << it.second << '\n';
	}
}

template<class TKey, class TValue>
const TValue& Container<TKey, TValue>::Get(const TKey& key) const {
	if (!IsSet(key)) {
		throw NotKeyException<TKey>(key);
	}
	return dict.at(key);
}

template<class TKey, class TValue>
void Container<TKey, TValue>::Set(const TKey& key, const TValue& value) {
	dict[key] = value;
}

template<class TKey, class TValue>
void Container<TKey, TValue>::Remove(const TKey& key) {
	if (!IsSet(key)) {
		throw NotKeyException<TKey>(key);
	}
	dict.erase(key);
}

template<class TKey, class TValue>
bool Container<TKey, TValue>::IsSet(const TKey& key) const {
	return (dict.find(key) != dict.end());
}