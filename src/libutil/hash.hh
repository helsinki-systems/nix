#ifndef __HASH_H
#define __HASH_H

#include <string>

#include "util.hh"

using namespace std;


typedef enum { htUnknown, htMD5, htSHA1, htSHA256 } HashType;


const int md5HashSize = 16;
const int sha1HashSize = 20;
const int sha256HashSize = 32;


struct Hash
{
    static const unsigned int maxHashSize = 32;
    unsigned int hashSize;
    unsigned char hash[maxHashSize];

    HashType type;

    /* Create an unusable hash object. */
    Hash();

    /* Create a zero-filled hash object. */
    Hash(HashType type);

    /* Check whether two hash are equal. */
    bool operator == (const Hash & h2) const;

    /* Check whether two hash are not equal. */
    bool operator != (const Hash & h2) const;

    /* For sorting. */
    bool operator < (const Hash & h) const;

};


/* Convert a hash to a hexadecimal representation. */
string printHash(const Hash & hash);

/* Parse a hexadecimal representation of a hash code. */
Hash parseHash(HashType ht, const string & s);

/* Convert a hash to a base-32 representation. */
string printHash32(const Hash & hash);

/* Parse a base-32 representation of a hash code. */
Hash parseHash32(HashType ht, const string & s);

/* Verify that the given string is a valid hash code. */
bool isHash(const string & s);

/* Compute the hash of the given string. */
Hash hashString(const string & s, HashType ht);

/* Compute the hash of the given file. */
Hash hashFile(const Path & path, HashType ht);

/* Compute the hash of the given path.  The hash is defined as
   md5(dump(path)). */
Hash hashPath(const Path & path, HashType ht);

/* Compress a hash to the specified number of bytes by cyclically
   XORing bytes together. */
Hash compressHash(const Hash & hash, unsigned int newSize);


#endif /* !__HASH_H */
