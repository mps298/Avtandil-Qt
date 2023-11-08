#ifndef CRYPTER_H
#define CRYPTER_H

#include <QObject>

static const QString kEncryptorString = QString("Your_key_string_must_be_here"); //here is key to crypt/decrypt QString;
static const int kEncryptorInt = /*Your key int must be here */9999; //here is key to crypt/decrypt Int;

class Crypter : public QObject
{
    Q_OBJECT
public:
    static QString cryptString(const QString& toCrypt)
    {
        QString resultString = QString();
        for ( int i = 0; i < toCrypt.length(); i++)
        {
            resultString.append(QString(QChar(toCrypt[i]).unicode()^QChar(kEncryptorString[i%kEncryptorString.length()]).unicode()));
        }
        return resultString;
    }
    static QString decryptString(const QString& toDecrypt)
    {
        QString resultString = QString();
        for ( int i = 0; i < toDecrypt.length(); i++)
        {
            resultString.append(QString(QChar(toDecrypt[i]).unicode()^QChar(kEncryptorString[i%kEncryptorString.length()]).unicode()));
        }
        return resultString;
    }
    static int cryptInt(const int& toCrypt)
    {
        return toCrypt + kEncryptorInt;
    }
    static int decryptInt(const int& toDecrypt)
    {
        return toDecrypt - kEncryptorInt;
    }
};

#endif // CRYPTER_H
