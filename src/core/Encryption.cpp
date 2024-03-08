/*
| Filename: Encryption.cpp
| Author: Jjlrjjlr
| Date: 2024-03-06
*/

#include <ludivum/core/Encryption.h>

ludivum_core::EncryptionHandler::EncryptionHandler() {
    if (!gcry_check_version(NULL)) {
        std::cerr << "Version of gcrypt too old, cannot proceed." << std::endl;
    }

    gcry_control(GCRYCTL_SUSPEND_SECMEM_WARN);

    gcry_control(GCRYCTL_INIT_SECMEM, 16384, 0);

    gcry_control(GCRYCTL_RESUME_SECMEM_WARN);

    gcry_control(GCRYCTL_INITIALIZATION_FINISHED, 0);
}


std::string ludivum_core::EncryptionHandler::encryptData(const char* argData, const size_t argDataLength, const char* argKey, size_t argCipher) {
    gcry_cipher_hd_t handle;
    gcry_error_t error {0};
    size_t keyLength {gcry_cipher_get_algo_keylen(argCipher)};
    size_t blockLength {gcry_cipher_get_algo_blklen(argCipher)};
    size_t cryptLength {argDataLength};
    std::vector<char> encryptedText (cryptLength, 0);

    error = gcry_cipher_open(&handle, argCipher, GCRY_CIPHER_MODE_ECB, 0);

    if (error) {
        std::cerr << "Error opening cipher: " << gcry_strerror(error) << std::endl;
    }

    error = gcry_cipher_setkey(handle, argKey, keyLength);

    if (error) {
        std::cerr << "Error setting key: " << gcry_strerror(error) << std::endl;
    }

    error = gcry_cipher_encrypt(handle, encryptedText.data(), cryptLength, argData, argDataLength);

    if (error) {
        std::cerr << "Error encrypting data: " << gcry_strerror(error) << std::endl;
    }

    gcry_cipher_close(handle);

    return std::string{encryptedText.data()};
}

std::string ludivum_core::EncryptionHandler::decryptData(const char* argData, const size_t argDataLength, const char* argKey, size_t argCipher) {
    gcry_cipher_hd_t handle;
    gcry_error_t error {0};
    size_t keyLength {gcry_cipher_get_algo_keylen(argCipher)};
    size_t blockLength {gcry_cipher_get_algo_blklen(argCipher)};
    size_t cryptLength {argDataLength};
    std::string decryptedText (cryptLength, 0);

    error = gcry_cipher_open(&handle, argCipher, GCRY_CIPHER_MODE_ECB, 0);

    if (error) {
        std::cerr << "Error opening cipher: " << gcry_strerror(error) << std::endl;
    }

    error = gcry_cipher_setkey(handle, argKey, keyLength);

    if (error) {
        std::cerr << "Error setting key: " << gcry_strerror(error) << std::endl;
    }

    error = gcry_cipher_decrypt(handle, decryptedText.data(), cryptLength, argData, argDataLength);

    if (error) {
        std::cerr << "Error decrypting data: " << gcry_strerror(error) << std::endl;
    }

    gcry_cipher_close(handle);

    return decryptedText;
}


std::string ludivum_core::EncryptionHandler::encryptSerpent(const char* argData, const size_t argDataLength, const char* argKey) {
    return encryptData(argData, argDataLength, argKey, GCRY_CIPHER_SERPENT256);
}

std::string ludivum_core::EncryptionHandler::decryptSerpent(const char* argData, const size_t argDataLength, const char* argKey) {
    return decryptData(argData, argDataLength, argKey, GCRY_CIPHER_SERPENT256);
}


std::string ludivum_core::EncryptionHandler::encryptTwoFish(const char* argData, const size_t argDataLength, const char* argKey) {
    return encryptData(argData, argDataLength, argKey, GCRY_CIPHER_TWOFISH);
}

std::string ludivum_core::EncryptionHandler::decryptTwoFish(const char* argData, const size_t argDataLength, const char* argKey) {
    return decryptData(argData, argDataLength, argKey, GCRY_CIPHER_TWOFISH);
}