#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>

using namespace testing;

class Soundex {
public:
    QString encoding(QString word) {
        return "";
    }
};

TEST(SoudnexEncoding, RetainsSoleLetterOfOnLetter)
{
    Soundex soundex;
    ASSERT_EQ(soundex.encoding("A"), QString("A"));
}
