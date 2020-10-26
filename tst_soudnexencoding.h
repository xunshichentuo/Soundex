#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>

using namespace testing;

class Soundex {
public:
    QString encoding(const QString &word) const {
        return word + "000";
    }
};

TEST(SoundexEncoding, RetainsSoleLetterOfOnLetter)
{
    Soundex soundex;
    auto encoded = soundex.encoding("A");
    ASSERT_EQ(encoded, QString("A000"));
}

TEST(SoundexEncoding, PadsWithZeroToEnsureThreeDigits)
{
    Soundex soundex;
    auto encoded = soundex.encoding("I");
    ASSERT_EQ(encoded, QString("I000"));
}
