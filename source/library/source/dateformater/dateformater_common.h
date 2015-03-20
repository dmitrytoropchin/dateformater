#ifndef DATEPICKER_COMMON_H
#define DATEPICKER_COMMON_H

#include <QtGlobal>
#include <QLocale>

class QCoreApplication;

#if defined(DATEFORMATER_LIBRARY)
#  define DATEFORMATER_EXPORT Q_DECL_EXPORT
#else
#  define DATEFORMATER_EXPORT Q_DECL_IMPORT
#endif

void DATEFORMATER_EXPORT init_dateformater(QCoreApplication *app, const QLocale &locale = QLocale::system());

#endif // DATEPICKER_COMMON_H
