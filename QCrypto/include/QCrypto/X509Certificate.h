#ifndef _BASE_CRYPTO_X509CERTIFICATE_H_
#define _BASE_CRYPTO_X509CERTIFICATE_H_

#include <QString>
#include <QByteArray>
#include <QByteArray>

#include <QtCore/QtGlobal>

#if !defined(DLL_DECL_SPEC)
#if defined(IS_BUILT_AS_LIBRARY)
#define DLL_DECL_SPEC Q_DECL_EXPORT
#else
# define DLL_DECL_SPEC Q_DECL_IMPORT
#endif
#endif


namespace base { namespace Crypto { namespace x509
{
    DLL_DECL_SPEC QString GetCertHumanReadableFormat(const QByteArray &certBytes);

}}} //  namespaces


#endif // _BASE_CRYPTO_X509CERTIFICATE_H_
