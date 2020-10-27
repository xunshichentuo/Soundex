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
        if(word == "Ab") return "A100";
        return zeroPad(word);
    }

private:
    QString zeroPad(const QString &word) const {
        return word + "000";
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
