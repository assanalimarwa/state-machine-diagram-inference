#include <gtest/gtest.h>
struct Event{};
enum class State
{
  AIX,
  MAC,
};
State handle_event(State const state, Event const & evnet);

TEST(App, MAC)
{
  // CHeck path ['MAC']
  Event event;
  auto state = State::MAC;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
}

TEST(App, AIX)
{
  // CHeck path ['MAC', 'AIX', 'MAC']
  Event event;
  auto state = State::MAC;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
}

