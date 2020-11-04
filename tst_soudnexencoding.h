#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "soundex.h"

using namespace testing;

QT_BEGIN_NAMESPACE
inline void PrintTo(const QString &qStringSupport, ::std::ostream *resultShow)
{
    *resultShow << qUtf8Printable(qStringSupport);
}
QT_END_NAMESPACE

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
