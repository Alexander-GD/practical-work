#pragma once

#include <string>

/**
 * @brief  Check if the string consists of certain characters.
 * @param str  The string to check.
 * @param characters  The characters that the string should consist of.
 * @return  True if the string consists of the provided characters, false otherwise.
 */
bool consistsOfCharacters(const std::string str, const std::string characters);

/**
 * @brief  Get the local-part of the email address.
 * @param address  The email address.
 */
std::string getLocalPartOfEmailAddress(const std::string address);

/**
 * @brief  Get the domain-part of the email address.
 * @param address  The email address.
 */
std::string getDomainPartOfEmailAddress(const std::string address);

/**
 * @brief  Check if the email address is valid.
 * @param address  The email address.
 */
bool isValidEmailAddress(const std::string address);
