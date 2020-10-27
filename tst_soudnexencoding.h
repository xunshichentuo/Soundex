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
        QString encoded = word.left(1);
        if(word.length() > 1)
            encoded += "1";
        return zeroPad(encoded);
    }

private:
    QString zeroPad(const QString &word) const {
        auto zeroNeeded =  4 - word.length();
        return word + QString(zeroNeeded, '0');
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
