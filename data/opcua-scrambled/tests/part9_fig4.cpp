#include <gtest/gtest.h>
struct Event{};
enum class State
{
  AIK,
  TLD,
  SIP,
  WAN,
};
State handle_event(State const state, Event const & evnet);

TEST(App, TLD)
{
  // CHeck path ['TLD']
  Event event;
  auto state = State::TLD;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
}

TEST(App, SIP)
{
  // CHeck path ['TLD', 'SIP', 'TLD']
  Event event;
  auto state = State::TLD;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SIP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
}

