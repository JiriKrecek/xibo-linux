#include "Md5Hash.hpp"

#include "common/fs/FileSystem.hpp"

#include <boost/format.hpp>
#include <openssl/evp.h>
#include <sstream>

#define MD5_DIGEST_LENGTH 16

Md5Hash Md5Hash::fromString(std::string_view data)
{
    unsigned char result[MD5_DIGEST_LENGTH];
    unsigned int result_len = MD5_DIGEST_LENGTH;
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_md5(), NULL);
    EVP_DigestUpdate(mdctx, data.data(), data.size());
    EVP_DigestFinal_ex(mdctx, result, &result_len);
    EVP_MD_CTX_free(mdctx);

    std::stringstream stream;
    for (unsigned char byte : result)
    {
        stream << boost::format("%02x") % static_cast<short>(byte);
    }
    return Md5Hash{stream.str()};
}

Md5Hash Md5Hash::fromFile(const FilePath& path)
{
    auto fileContent = FileSystem::readFromFile(path);

    return Md5Hash::fromString(fileContent);
}

bool operator==(const Md5Hash& first, const Md5Hash& second)
{
    return static_cast<std::string>(first) == static_cast<std::string>(second);
}

bool operator!=(const Md5Hash& first, const Md5Hash& second)
{
    return !(first == second);
}

std::ostream& operator<<(std::ostream& out, const Md5Hash& hash)
{
    return out << static_cast<std::string>(hash);
}
