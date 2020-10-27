#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>
#include <QMap>

using namespace testing;

QT_BEGIN_NAMESPACE
inline void PrintTo(const QString &qStringSupport, ::std::ostream *resultShow)
{
    *resultShow << qUtf8Printable(qStringSupport);
}
QT_END_NAMESPACE

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

class SoundexEncoding : public Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOnLetter)
{
    auto encoded = soundex.encode("A");
    ASSERT_EQ(encoded, QString("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits)
{
    auto encoded = soundex.encode("I");
    ASSERT_EQ(encoded, QString("I000"));
}

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    ASSERT_THAT(soundex.encode("Ab"), Eq(QString("A100")));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}
