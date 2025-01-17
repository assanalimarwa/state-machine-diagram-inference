#include <gtest/gtest.h>
struct Event{};
enum class State
{
  LAN,
  NOC,
};
State handle_event(State const state, Event const & evnet);

TEST(App, NOC)
{
  // CHeck path ['NOC']
  Event event;
  auto state = State::NOC;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NOC);
}

TEST(App, LAN)
{
  // CHeck path ['NOC', 'LAN', 'NOC']
  Event event;
  auto state = State::NOC;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NOC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NOC);
}

