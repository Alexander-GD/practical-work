#pragma once

#include <string>

/**
 * @brief  Encrypt the text with the Caesar cipher.
 * @param text  Text to encrypt.
 * @param key   Encryption key.
 * @return  Encrypted text.
 */
std::string encryptCaesar(std::string text, int key);

/**
 * @brief  Decrypt the text using the Caesar cipher.
 * @param text  Encrypted text.
 * @param key   Encryption key.
 * @return  Decrypted text.
 */
std::string decryptCaesar(std::string text, int key);
