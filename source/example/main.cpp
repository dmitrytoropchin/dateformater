#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>
#include <QDate>

#include <dateformater/dateformaterhumanreadable.h>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // initilize library translations
    init_dateformater(&app, QLocale(QLocale::Russian, QLocale::RussianFederation));

    DateFormaterHumanReadable *formater = new DateFormaterHumanReadable();

    qDebug() << formater->format(QDate());

    qDebug() << formater->format(QDate::currentDate());
    qDebug() << formater->format(QDate::currentDate().addDays(-1));
    qDebug() << formater->format(QDate::currentDate().addDays(1));

    qDebug() << formater->format(QDateTime::currentDateTime());
    qDebug() << formater->format(QDate::currentDate().addMonths(1));

    qDebug() << "";

    qDebug() << formater->format(QDate(), QDate());

    qDebug() << formater->format(QDate::currentDate(), QDate::currentDate().addDays(1));
    qDebug() << formater->format(QDate::currentDate(), QDate::currentDate().addMonths(1));
    qDebug() << formater->format(QDate::currentDate(), QDate::currentDate().addYears(1));

    qDebug() << formater->format(QDateTime::currentDateTime(),
                                 QDateTime::currentDateTime().addSecs(3600));
    qDebug() << formater->format(QDateTime::currentDateTime(),
                                 QDateTime::currentDateTime().addDays(1).addSecs(3600));
    qDebug() << formater->format(QDateTime::currentDateTime(),
                                 QDateTime::currentDateTime().addYears(1).addSecs(3600));

    return 0;
}
