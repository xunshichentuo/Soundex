#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>

using namespace testing;

QT_BEGIN_NAMESPACE
inline void PrintTo(const QString &qStringSupport, ::std::ostream *resultShow)
{
    *resultShow << qUtf8Printable(qStringSupport);
}
QT_END_NAMESPACE

class Soundex {
public:
    QString encoding(const QString &word) const {
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
        if(word.length() > 1) return encodingDigit();

        return "";
    }

    QString encodingDigit() const {
        return "1";
    }
};

class SoundexEncoding : public Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOnLetter)
{
    auto encoded = soundex.encoding("A");
    ASSERT_EQ(encoded, QString("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits)
{
    auto encoded = soundex.encoding("I");
    ASSERT_EQ(encoded, QString("I000"));
}

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    ASSERT_THAT(soundex.encoding("Ab"), Eq(QString("A100")));
}
