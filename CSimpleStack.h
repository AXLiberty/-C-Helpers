#pragma once

#include <stdint.h>
#include <deque>

template <typename T>
class CSimpleStack : public std::deque<T>
{
private:
	uint64_t m_u64MaxCount;

public:
	CSimpleStack(uint64_t maxCount = 1) { m_u64MaxCount = maxCount; }
	void setMaxCount(uint64_t maxCount) { m_u64MaxCount = maxCount; }
	auto getMaxCount() const { return m_u64MaxCount; }

	auto count() const { return __super::size(); }
	auto size() const { return count() * sizeof(T); }

	void push(T value)
	{
		if (count() >= m_u64MaxCount)
			pop_front();
		push_back(value);
	}

	T pop()
	{
		if (!empty())
		{
			auto value = back();
			pop_back();
			return value;
		}
		return NULL;
	}
};
