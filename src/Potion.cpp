#include "Potion.h"
#include "random_number.h"
#include <array>
#include <sstream>

Potion::Potion(Type type, Size size)
	: m_type{ type }, m_size{ size }
{
}

std::string_view Potion::getPotionTypeName(Type type) const
{
	static constexpr std::array types{ "Health", "Strength", "Poison" };

	return types.at(static_cast<std::size_t>(type));
}

std::string_view Potion::getPotionSizeName(Size size) const
{
	static constexpr std::array sizes{ "Small", "Medium", "Large" };

	return sizes.at(static_cast<std::size_t>(size));
}

std::string Potion::getName() const
{
	std::stringstream result{};

	result << getPotionSizeName(m_size) << " potion of " << getPotionTypeName(m_type);

	return result.str();
}

Potion Potion::getRandomPotion()
{
	Type type{ getRandomNumber(0, static_cast<int>(Type::MAX_TYPES) - 1) };
	Size size{ getRandomNumber(0, static_cast<int>(Size::MAX_SIZES) - 1) };

	return { static_cast<Type>(type), static_cast<Size>(size) };
}