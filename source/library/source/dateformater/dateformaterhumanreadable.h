#ifndef DATEPICKERHUMANREADABLEFORMATER_H
#define DATEPICKERHUMANREADABLEFORMATER_H

#include <dateformater/dateformater_common.h>
#include <dateformater/dateformaterbase.h>

class DateFormaterHumanReadablePrivate;

class DATEFORMATER_EXPORT DateFormaterHumanReadable : public DateFormaterBase {
    Q_DECLARE_PRIVATE(DateFormaterHumanReadable)

    DateFormaterHumanReadablePrivate * const d_ptr;
public:
    DateFormaterHumanReadable();
    ~DateFormaterHumanReadable();

    QString format(const QDate &date) const;
    QString format(const QDateTime &datetime) const;
    QString format(const QDate &begin, const QDate &end) const;
    QString format(const QDateTime &begin, const QDateTime &end) const;

    QString dateFromWord() const;
    void setDateFromWord(const QString &word);

    QString dateToWord() const;
    void setDateToWord(const QString &word);

    QString invalidDateWord() const;
    void setInvalidDateWord(const QString &word);

    QString invalidPeriodWord() const;
    void setInvalidPeriodWord(const QString &word);

    bool isSpecialDayWordShown() const;
    void setSpecialDayWordShown(bool on);
};

#endif // DATEPICKERHUMANREADABLEFORMATER_H
