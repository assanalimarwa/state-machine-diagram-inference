#include <gtest/gtest.h>
struct Event{};
enum class State
{
  TLD,
  NAT,
  SSD,
  LTE,
  NTP,
  ICQ,
};
State handle_event(State const state, Event const & evnet);

TEST(App, NTP)
{
  // CHeck path ['NTP']
  Event event;
  auto state = State::NTP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NTP);
}

