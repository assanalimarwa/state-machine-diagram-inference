#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SDK,
  HDD,
  SLA,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SLA)
{
  // CHeck path ['SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

TEST(App, HDD)
{
  // CHeck path ['SLA', 'HDD', 'SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HDD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

TEST(App, SDK)
{
  // CHeck path ['SLA', 'HDD', 'SDK', 'SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HDD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

