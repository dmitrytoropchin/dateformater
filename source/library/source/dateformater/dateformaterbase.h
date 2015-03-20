#ifndef DATEPICKERABSTRACTFORMATER_H
#define DATEPICKERABSTRACTFORMATER_H

#include <dateformater/dateformater_common.h>

class QDate;
class QDateTime;

class DATEFORMATER_EXPORT DateFormaterBase {
protected:
    DateFormaterBase() {}
public:
    virtual ~DateFormaterBase() {}

    virtual QString format(const QDate &date) const = 0;
    virtual QString format(const QDateTime &datetime) const = 0;
    virtual QString format(const QDate &begin, const QDate &end) const = 0;
    virtual QString format(const QDateTime &begin, const QDateTime &end) const = 0;
};

#endif // DATEPICKERABSTRACTFORMATER_H
