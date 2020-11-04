#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <QObject>
#include <QMap>

class Soundex {
public:
    QString encode(const QString &word) const {
        return zeroPad(head(word) + encodedDigits(tail(word)));
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

    QString tail(const QString &word) const {
        return word.mid(1);
    }

    QString encodedDigits(const QString &word) const {
        if(word.isEmpty())  return "";

        QString encoding;
        for(auto letter : word) {
            if(isComplete(encoding)) break;
            encoding += encodedDigit(letter);
        }
        return encoding;
    }

    bool isComplete(const QString& encoding) const {
         return encoding.length() == MaxCodeLength - 1;
    }

    QString encodedDigit(QChar letter) const {
        const QMap<QChar, QString> encodings {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                        {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"},
        };
        auto it = encodings.find(letter);
        return it == encodings.end() ? "" : it.value();
    }
};

#endif // SOUNDEX_H
