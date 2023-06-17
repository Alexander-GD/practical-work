#pragma once

#include <string>

/**
 * @brief  Get a part of an IP address.
 * @param address  The IP address.
 * @param octetNo  The octet number.
 * @return The part of the IP address by octet number.
 */
std::string getOctetOfIpAddress(const std::string address, const int octetNo);

/**
 * @brief  Check if the IP address octet is valid.
 * @param octet  The IP address octet.
 */
bool isOctetOfIpAddressValid(const std::string octet);

/**
 * @brief  Check if the IP address is valid.
 * @param address  The IP address.
 */
bool isIpAddressValid(const std::string address);
