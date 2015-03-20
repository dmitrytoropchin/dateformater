#include <QDate>
#include <QDateTime>

#include "dateformater/dateformaterstandard.h"


class DateFormaterStandardPrivate {
    Q_DECLARE_PUBLIC(DateFormaterStandard)

    DateFormaterStandard *q_ptr;
    QString date_format_template;
    QString date_time_format_template;

    DateFormaterStandardPrivate(DateFormaterStandard *q) :
        q_ptr(q), date_format_template("d MMMM yyyy"), date_time_format_template("d MMMM yyyy hh:mm:ss") {}
    ~DateFormaterStandardPrivate() {}
};

DateFormaterStandard::DateFormaterStandard() :
    DateFormaterBase(),
    d_ptr(new DateFormaterStandardPrivate(this))
{
}

DateFormaterStandard::~DateFormaterStandard()
{
    delete d_ptr;
}

QString DateFormaterStandard::format(const QDate &date) const
{
    Q_D(const DateFormaterStandard);
    return date.toString(d->date_format_template);
}

QString DateFormaterStandard::format(const QDateTime &datetime) const
{
    Q_D(const DateFormaterStandard);
    return datetime.toString(d->date_time_format_template);
}

QString DateFormaterStandard::format(const QDate &begin, const QDate &end) const
{
    Q_D(const DateFormaterStandard);
    return QString("%1 - %2")
            .arg(begin.toString(d->date_format_template))
            .arg(end.toString(d->date_format_template));
}

QString DateFormaterStandard::format(const QDateTime &begin, const QDateTime &end) const
{
    Q_D(const DateFormaterStandard);
    return QString("%1 - %2")
            .arg(begin.toString(d->date_time_format_template))
            .arg(end.toString(d->date_time_format_template));
}

QString DateFormaterStandard::dateFormatTemplate() const
{
    Q_D(const DateFormaterStandard);
    return d->date_format_template;
}

void DateFormaterStandard::setDateFormatTemplate(const QString &format_template)
{
    Q_D(DateFormaterStandard);
    d->date_format_template = format_template;
}

QString DateFormaterStandard::dateTimeFormatTemplate() const
{
    Q_D(const DateFormaterStandard);
    return d->date_time_format_template;
}

void DateFormaterStandard::setDateTimeFormatTemplate(const QString &format_template)
{
    Q_D(DateFormaterStandard);
    d->date_time_format_template = format_template;
}
