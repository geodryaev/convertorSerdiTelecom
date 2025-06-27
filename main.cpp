#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QSet>
#include <QStringList>
#include <QThread>

#include "procfiles.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "convertorSerDiTelecom_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    qDebug() << "test";
    QSettings settings("conf.ini", QSettings::IniFormat);
    QSet<QString> inProcFiles, porcFiles;

    if (!QFile::exists("conf.ini"))
    {
        qDebug() << "File is not be";
        settings.beginGroup("Path");
        settings.setValue("Folder_input", "-1");
        settings.setValue("Folder_output", "-1");
        settings.endGroup();
        settings.sync();
    }
    else
    {
        QString pathToSave = settings.value("Path/Folder_output").toString();
        QString pathToSource = settings.value("Path/Folder_input").toString();
        QDir dirSource(pathToSource);
        QDir dirSave(pathToSave);
        QStringList listFile ;
        qDebug() << pathToSave << " " << pathToSource << " ";
        while(true)
        {
            QThread::sleep(2);
            if (pathToSave == "-1" or pathToSource == "-1")
            {
                continue;
            }

            if (!dirSource.exists() || !dirSave.exists())
            {
                qCritical() << "Error: Пути не рабочие";
                continue;
            }
            listFile = dirSource.entryList(QStringList() << "*.cdr", QDir::Files | QDir::NoSymLinks);
            for (int i = 0; i < listFile.size();i++)
            {
                if (!porcFiles.contains(pathToSource + "/" +listFile[i]))
                {
                    inProcFiles.insert(pathToSource + "/" + listFile[i]);
                }
            }

            QThread::sleep(5);

            for(const QString &str : inProcFiles)
            {
                qCritical() << "Обработка файла :" << str;
                procFile(str,pathToSave);
            }


        }
    }

    return a.exec();
}
