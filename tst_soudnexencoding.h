#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>

using namespace testing;

class Soundex {
public:
    QString encoding(const QString &word) const {
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
