#include "dateformater/dateformater_common.h"
#include <QCoreApplication>
#include <QTranslator>
#include <QDebug>


void init_dateformater(QCoreApplication *app, const QLocale &locale)
{
    Q_INIT_RESOURCE(dateformater_resources);

    QString lang = locale.name().mid(0, 2);

    QTranslator *dateformater_translator = new QTranslator(app);
    if (!dateformater_translator->load(QString(":/dateformater_translations/%1").arg(lang)))
        qDebug() << "failed to load dateformater lib translations for" << lang;

    app->installTranslator(dateformater_translator);
}
