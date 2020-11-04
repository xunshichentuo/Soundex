#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <QObject>
#include <QMap>

class Soundex {
public:
    QString encode(const QString &word) const {
        return zeroPad(head(word) + encodeDigits(word));
    }

private:
    static const int MaxCodeLength{4};

    QString zeroPad(const QString &word) const {
        auto zeroNeeded =  MaxCodeLength - word.length();
        return word + QString(zeroNeeded, '0');
    }

    QString head(const QString &word) const {
        return word.left(1);
    }

    QString encodeDigits(const QString &word) const {
        if(word.length() > 1) return encodingDigit(word.at(1));

        return "";
    }

    QString encodingDigit(QChar letter) const {
        const QMap<QChar, QString> encodings {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                        {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"},
        };
        return encodings.find(letter).value();
    }
};

#endif // SOUNDEX_H
