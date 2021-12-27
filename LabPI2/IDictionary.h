#pragma once

template<typename T, typename R>
class IDictionary {
public:
	virtual size_t Count() = 0;

	virtual void Add(T, R) = 0;
	virtual void Remove(T) = 0;

	virtual R GetVal(T) = 0;
	virtual bool ContainsKey(T) = 0;
};