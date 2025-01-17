#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SDK,
  NAT,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SDK)
{
  // CHeck path ['SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

TEST(App, NAT)
{
  // CHeck path ['SDK', 'NAT', 'SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NAT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

