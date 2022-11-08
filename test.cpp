#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include "FibLFSR.h"

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

BOOST_AUTO_TEST_CASE(correctLength)
{
  FibLFSR l3("1011011000110110");
  BOOST_CHECK_EQUAL(l3.getLength(), 16);
}

BOOST_AUTO_TEST_CASE(constructorWorks)
{
  FibLFSR l4("1011011000110110");
  int array[16] = {0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1};
  int *temp = l4.getArray();

  BOOST_CHECK_EQUAL_COLLECTIONS(temp, temp+15, array, array+15);
}