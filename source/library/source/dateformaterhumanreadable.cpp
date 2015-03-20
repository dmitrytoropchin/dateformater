#include <QObject>
#include <QMap>
#include <QDate>
#include <QDateTime>

#include "dateformater/dateformaterhumanreadable.h"


class DateFormaterHumanReadablePrivate {
    Q_DECLARE_PUBLIC(DateFormaterHumanReadable)

    DateFormaterHumanReadable *q_ptr;

    QMap<int, QString> month_name; // с падежом

    QString date_from_word;
    QString date_to_word;

    QString time_from_word;
    QString time_to_word;

    QString invalid_date_word;
    QString invalid_period_word;

    QString date_time_delimeter;

    bool is_special_day_word_shown;

    DateFormaterHumanReadablePrivate(DateFormaterHumanReadable *q) :
        q_ptr(q)
    {
        month_name.insert(1, QObject::tr("january"));
        month_name.insert(2, QObject::tr("february"));
        month_name.insert(3, QObject::tr("march"));
        month_name.insert(4, QObject::tr("april"));
        month_name.insert(5, QObject::tr("may"));
        month_name.insert(6, QObject::tr("june"));
        month_name.insert(7, QObject::tr("july"));
        month_name.insert(8, QObject::tr("august"));
        month_name.insert(9, QObject::tr("september"));
        month_name.insert(10, QObject::tr("october"));
        month_name.insert(11, QObject::tr("november"));
        month_name.insert(12, QObject::tr("december"));

        date_from_word = QObject::tr("from", "date");
        date_to_word = QObject::tr("to", "date");

        time_from_word = QObject::tr("from", "time");
        time_to_word = QObject::tr("to", "time");

        invalid_date_word = QObject::tr("undefined date");
        invalid_period_word = QObject::tr("undefined period");

        date_time_delimeter = QObject::tr("in");

        is_special_day_word_shown = true;
    }

    ~DateFormaterHumanReadablePrivate() {}
};

DateFormaterHumanReadable::DateFormaterHumanReadable() :
    DateFormaterBase(),
    d_ptr(new DateFormaterHumanReadablePrivate(this))
{
}

DateFormaterHumanReadable::~DateFormaterHumanReadable()
{
    delete d_ptr;
}

QString DateFormaterHumanReadable::format(const QDate &date) const
{
    Q_D(const DateFormaterHumanReadable);

    if (!date.isValid())
        return d->invalid_date_word;

    QString human_readable_str;

    QDate current_date = QDate::currentDate();
    int day_difference = current_date.daysTo(date);

    if ((day_difference == 0) && d->is_special_day_word_shown) {
        human_readable_str = QObject::tr("today");
    }
    else if ((day_difference == -1) && d->is_special_day_word_shown) {
        human_readable_str = QObject::tr("yesterday");
    }
    else if ((day_difference == 1) && d->is_special_day_word_shown) {
        human_readable_str = QObject::tr("tomorrow");
    }
    else {
        human_readable_str = QObject::tr("%1 %2 %3")
                             .arg(date.day())
                             .arg(d->month_name.value(date.month()))
                             .arg(date.year());
    }

    return human_readable_str;
}

QString DateFormaterHumanReadable::format(const QDateTime &datetime) const
{
    Q_D(const DateFormaterHumanReadable);

    if (!datetime.isValid())
        return d->invalid_date_word;

    QString human_readable_time_str = (datetime.time().second() == 0) ? datetime.time().toString("hh:mm")
                                                                      : datetime.time().toString("hh:mm:ss");

    QString human_readable_date_str;

    QDate current_date = QDate::currentDate();
    int day_difference = current_date.daysTo(datetime.date());

    if ((day_difference == 0) && d->is_special_day_word_shown) {
        human_readable_date_str = QObject::tr("today");
    }
    else if ((day_difference == -1) && d->is_special_day_word_shown) {
        human_readable_date_str = QObject::tr("yesterday");
    }
    else if ((day_difference == 1) && d->is_special_day_word_shown) {
        human_readable_date_str = QObject::tr("tomorrow");
    }
    else {
        human_readable_date_str = QObject::tr("%1 %2 %3")
                                  .arg(datetime.date().day())
                                  .arg(d->month_name.value(datetime.date().month()))
                                  .arg(datetime.date().year());
    }

    return QString("%1 %2 %3").arg(human_readable_date_str, d->date_time_delimeter, human_readable_time_str);
}

QString DateFormaterHumanReadable::format(const QDate &begin, const QDate &end) const
{
    Q_D(const DateFormaterHumanReadable);

    if (!begin.isValid() || !end.isValid())
        return d->invalid_period_word;

    if (begin == end)
        return format(begin);

    QString human_readable_begin_str;
    QString human_readable_end_str;

    if (begin.year() == end.year()) {
        if (begin.month() == end.month()) {
            human_readable_begin_str = begin.toString("d");
        }
        else {
            human_readable_begin_str = QString("%1 %2")
                                       .arg(begin.day())
                                       .arg(d->month_name.value(begin.month()));
        }
    }
    else {
        human_readable_begin_str = QObject::tr("%1 %2 %3")
                                   .arg(begin.day())
                                   .arg(d->month_name.value(begin.month()))
                                   .arg(begin.year());
    }

    human_readable_end_str = QObject::tr("%1 %2 %3")
                             .arg(end.day())
                             .arg(d->month_name.value(end.month()))
                             .arg(end.year());

    return QObject::tr("%1 %2 %3 %4")
            .arg(d->date_from_word)
            .arg(human_readable_begin_str)
            .arg(d->date_to_word)
            .arg(human_readable_end_str).simplified();
}

QString DateFormaterHumanReadable::format(const QDateTime &begin, const QDateTime &end) const
{
    Q_D(const DateFormaterHumanReadable);

    if (!begin.isValid() || !end.isValid())
        return d->invalid_period_word;

    QString human_readable_period_str;

    QString human_readable_begin_time_str = (begin.time().second() == 0) ? begin.time().toString("hh:mm")
                                                                         : begin.time().toString("hh:mm:ss");
    QString human_readable_end_time_str = (end.time().second() == 0) ? end.time().toString("hh:mm")
                                                                     : end.time().toString("hh:mm:ss");

    if (begin.date() == end.date()) {
        if ((begin.time() == QTime(0, 0, 0)) && (end.time() == QTime(23, 59, 59))) {
            human_readable_period_str = format(begin.date());
        }
        else {
            QString human_readable_date_str = QObject::tr("%1 %2 %3")
                                              .arg(begin.date().day())
                                              .arg(d->month_name.value(begin.date().month()))
                                              .arg(begin.date().year());

            human_readable_period_str = QObject::tr("%1 %2 %3 %4 %5")
                                        .arg(d->time_from_word)
                                        .arg(human_readable_begin_time_str)
                                        .arg(d->time_to_word)
                                        .arg(human_readable_end_time_str)
                                        .arg(human_readable_date_str);
        }
    }
    else {
        if ((begin.time() == QTime(0, 0, 0)) && (end.time() == QTime(23, 59, 59))) {
            human_readable_period_str = format(begin.date(), end.date());
        }
        else {
            QString human_readable_begin_date_str;
            QString human_readable_end_date_str;

            if (begin.date().year() == end.date().year()) {
                human_readable_begin_date_str = QObject::tr("%1 %2")
                                                .arg(begin.date().day())
                                                .arg(d->month_name.value(begin.date().month()));
            }
            else {
                human_readable_begin_date_str = QObject::tr("%1 %2 %3")
                                                .arg(begin.date().day())
                                                .arg(d->month_name.value(begin.date().month()))
                                                .arg(begin.date().year());
            }
            human_readable_end_date_str = QObject::tr("%1 %2 %3")
                                          .arg(end.date().day())
                                          .arg(d->month_name.value(end.date().month()))
                                          .arg(end.date().year());

            human_readable_period_str = QObject::tr("%1 %2 %3 %4 %5 %6")
                                        .arg(d->time_from_word)
                                        .arg(human_readable_begin_time_str)
                                        .arg(human_readable_begin_date_str)
                                        .arg(d->time_to_word)
                                        .arg(human_readable_end_time_str)
                                        .arg(human_readable_end_date_str);
        }
    }

    return human_readable_period_str;
}

QString DateFormaterHumanReadable::dateFromWord() const
{
    Q_D(const DateFormaterHumanReadable);
    return d->date_from_word;
}

void DateFormaterHumanReadable::setDateFromWord(const QString &word)
{
    Q_D(DateFormaterHumanReadable);
    d->date_from_word = word;
}

QString DateFormaterHumanReadable::dateToWord() const
{
    Q_D(const DateFormaterHumanReadable);
    return d->date_to_word;
}

void DateFormaterHumanReadable::setDateToWord(const QString &word)
{
    Q_D(DateFormaterHumanReadable);
    d->date_to_word = word;
}

QString DateFormaterHumanReadable::invalidDateWord() const
{
    Q_D(const DateFormaterHumanReadable);
    return d->invalid_date_word;
}

void DateFormaterHumanReadable::setInvalidDateWord(const QString &word)
{
    Q_D(DateFormaterHumanReadable);
    d->invalid_date_word = word;
}

QString DateFormaterHumanReadable::invalidPeriodWord() const
{
    Q_D(const DateFormaterHumanReadable);
    return d->invalid_period_word;
}

void DateFormaterHumanReadable::setInvalidPeriodWord(const QString &word)
{
    Q_D(DateFormaterHumanReadable);
    d->invalid_period_word = word;
}

bool DateFormaterHumanReadable::isSpecialDayWordShown() const
{
    Q_D(const DateFormaterHumanReadable);
    return d->is_special_day_word_shown;
}

void DateFormaterHumanReadable::setSpecialDayWordShown(bool on)
{
    Q_D(DateFormaterHumanReadable);
    d->is_special_day_word_shown = on;
}
