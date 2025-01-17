#include <gtest/gtest.h>
struct Event{};
enum class State
{
  JDK,
  SLA,
};
State handle_event(State const state, Event const & evnet);

TEST(App, JDK)
{
  // CHeck path ['JDK']
  Event event;
  auto state = State::JDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
}

TEST(App, SLA)
{
  // CHeck path ['JDK', 'SLA', 'JDK']
  Event event;
  auto state = State::JDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
}

