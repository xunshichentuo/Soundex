#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>

using namespace testing;

class Soundex {
public:
    QString encoding(const QString &word) const {
        return word;
    }
};

TEST(SoundexEncoding, RetainsSoleLetterOfOnLetter)
{
    Soundex soundex;
    auto encoded = soundex.encoding("A");
    ASSERT_EQ(encoded, QString("A"));
}
