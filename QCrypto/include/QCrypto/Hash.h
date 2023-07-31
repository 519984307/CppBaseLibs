#ifndef _BASE_CRYPTO_HASH_H_
#define _BASE_CRYPTO_HASH_H_

#include <QByteArray>

#include <QtCore/QtGlobal>

#if !defined(DLL_DECL_SPEC)
#if defined(IS_BUILT_AS_LIBRARY)
#define DLL_DECL_SPEC Q_DECL_EXPORT
#else
# define DLL_DECL_SPEC Q_DECL_IMPORT
#endif
#endif

namespace base { namespace Crypto { namespace Hash
{
    DLL_DECL_SPEC QByteArray MD5(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA1(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA2_224(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA2_256(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA2_384(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA2_512(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA2_512_224(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA2_512_256(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA3_224(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA3_256(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA3_384(const QByteArray &input);
    DLL_DECL_SPEC QByteArray SHA3_512(const QByteArray &input);
    DLL_DECL_SPEC QByteArray KECCAK_224(const QByteArray &input);
    DLL_DECL_SPEC QByteArray KECCAK_256(const QByteArray &input);
    DLL_DECL_SPEC QByteArray KECCAK_384(const QByteArray &input);
    DLL_DECL_SPEC QByteArray KECCAK_512(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2B_160(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2B_256(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2B_384(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2B_512(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2S_128(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2S_160(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2S_224(const QByteArray &input);
    DLL_DECL_SPEC QByteArray BLAKE2S_256(const QByteArray &input);

}}} // Namespaces


#endif // _BASE_CRYPTO_HASH_H_
