#ifndef _BASE_QGLOBALS_H_
#define _BASE_QGLOBALS_H_

#include <QtCore/QtGlobal>

#if !defined(DLL_DECL_SPEC)
#if defined(IS_BUILT_AS_LIBRARY)
#define DLL_DECL_SPEC Q_DECL_EXPORT
#else
# define DLL_DECL_SPEC Q_DECL_IMPORT
#endif
#endif



#endif //_BASE_QGLOBALS_H_
