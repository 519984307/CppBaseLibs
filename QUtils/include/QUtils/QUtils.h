#ifndef _BASE_QUTILS_H_
#define _BASE_QUTILS_H_

#include <QtCore/QtGlobal>

#if !defined(DLL_DECL_SPEC)
#if defined(IS_BUILT_AS_LIBRARY)
#define DLL_DECL_SPEC Q_DECL_EXPORT
#else
# define DLL_DECL_SPEC Q_DECL_IMPORT
#endif
#endif

#include <QString>
#include <QCryptographicHash>
#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QUrl>

namespace base { namespace Utils
{

DLL_DECL_SPEC QString Utils_Uint8ToHexQStr(uint8_t in);
DLL_DECL_SPEC QString Utils_Uint8ArrToHexQStr(uint8_t *arr, ssize_t len);
DLL_DECL_SPEC QString Utils_QByteArrayToHexQStr(const QByteArray& bytes_arr);
DLL_DECL_SPEC QByteArray Utils_RawHexStrToQByteArr(QString in_hexstr);
DLL_DECL_SPEC bool Utils_RawHexStrToArr(QString in_hexstr, uint8_t *out_arr, ssize_t *out_len, ssize_t max_len);
DLL_DECL_SPEC bool Utils_Sha512(uint8_t *in_data, ssize_t in_len, uint8_t outData[64]);

DLL_DECL_SPEC QString Utils_BytesToPrintableAsciiString(const QByteArray *in_arr);
DLL_DECL_SPEC QString Utils_BytesToAlphanumericString(const QByteArray *in_arr);
DLL_DECL_SPEC QString Utils_BytesToBinaryString(const QByteArray *in_arr);
DLL_DECL_SPEC QString Utils_BytesToDECString(const QByteArray *in_arr);

DLL_DECL_SPEC QString ParseCertOrCsrFromFileToHexStr(const QString& fileName);

DLL_DECL_SPEC QStringList Utils_ExtractAllUrls(const QString& inputText);
DLL_DECL_SPEC QStringList Utils_ExtractAllHosts(const QString &input);

DLL_DECL_SPEC bool Utils_IsValidIPv4(const QString &input);
DLL_DECL_SPEC bool Utils_IsValidIPv6(const QString &input);

DLL_DECL_SPEC void Utils_NumericListSort(QStringList *list);
DLL_DECL_SPEC bool Utils_FileExists(const QString& fileName);
DLL_DECL_SPEC QStringList Utils_ParseCsvLine(const QString &string);
DLL_DECL_SPEC QString Util_EncodeForCSV(const QString &string);
DLL_DECL_SPEC QString Utils_FloatWithDigitsPrecision(float number, int precision = 2);

// Data structures utils
DLL_DECL_SPEC void Utils_PrintNestedQMap(const QVariantMap &map, int level = 0);
DLL_DECL_SPEC void Utils_PrintNestedQMap_AsQStrings(const QVariantMap &map, int level = 0);

DLL_DECL_SPEC QByteArrayList SplitByteArray(const QByteArray &in, QByteArray delimiter);

DLL_DECL_SPEC void SleepMs(quint64 ms);

}} // Namespaces
#endif // _BASE_QUTILS_H_