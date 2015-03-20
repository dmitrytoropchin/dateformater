#ifndef DATEPICKERSTANDARDFORMATER_H
#define DATEPICKERSTANDARDFORMATER_H

#include <dateformater/dateformater_common.h>
#include <dateformater/dateformaterbase.h>

class DateFormaterStandardPrivate;

class DATEFORMATER_EXPORT DateFormaterStandard : public DateFormaterBase {
    Q_DECLARE_PRIVATE(DateFormaterStandard)

    DateFormaterStandardPrivate * const d_ptr;
public:
    DateFormaterStandard();
    ~DateFormaterStandard();

    QString format(const QDate &date) const;
    QString format(const QDateTime &datetime) const;
    QString format(const QDate &begin, const QDate &end) const;
    QString format(const QDateTime &begin, const QDateTime &end) const;

    QString dateFormatTemplate() const;
    void setDateFormatTemplate(const QString &format_template);

    QString dateTimeFormatTemplate() const;
    void setDateTimeFormatTemplate(const QString &format_template);
};

#endif // DATEPICKERSTANDARDFORMATER_H
