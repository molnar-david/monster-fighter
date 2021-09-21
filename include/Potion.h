#pragma once

#include <string_view>

class Potion
{
public:
	enum class Type
	{
		HEALTH,			// 0
		STRENGTH,		// 1
		POISON,			// 2
		MAX_TYPES		// 3
	};

	enum class Size
	{
		SMALL,			// 0
		MEDIUM,			// 1
		LARGE,			// 2
		MAX_SIZES		// 3
	};

private:
	Type m_type;
	Size m_size;

public:
	Potion(Type type, Size size);

	Type getType() const { return m_type; }
	Size getSize() const { return m_size; }

	std::string_view getPotionTypeName(Type type) const;
	std::string_view getPotionSizeName(Size size) const;
	std::string getName() const;
	static Potion getRandomPotion();
};