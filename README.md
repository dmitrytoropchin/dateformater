DateFormater Library
====================

Предоставляет классы для форматирования дат в удобном для чтения формате.

Например, следующий код

```
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
```

выводит

```
"неопределенная дата" 
"сегодня" 
"вчера" 
"завтра" 
"сегодня в 14:58:55" 
"20 апреля 2015" 
 
"неопределенный период" 
"с 20 по 21 марта 2015" 
"с 20 марта по 20 апреля 2015" 
"с 20 марта 2015 по 20 марта 2016" 
"с 14:58:55 до 15:58:55 20 марта 2015" 
"с 14:58:55 20 марта до 15:58:55 21 марта 2015" 
"с 14:58:55 20 марта 2015 до 15:58:55 20 марта 2016" 
```
