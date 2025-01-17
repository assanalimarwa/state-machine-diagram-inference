#include <gtest/gtest.h>
struct Event{};
enum class State
{
  AIX,
  IIS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, AIX)
{
  // CHeck path ['AIX']
  Event event;
  auto state = State::AIX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIX);
}

TEST(App, IIS)
{
  // CHeck path ['AIX', 'IIS', 'AIX']
  Event event;
  auto state = State::AIX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IIS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIX);
}

