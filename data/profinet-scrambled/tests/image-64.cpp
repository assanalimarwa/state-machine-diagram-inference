#include <gtest/gtest.h>
struct Event{};
enum class State
{
  ICQ,
};
State handle_event(State const state, Event const & evnet);

TEST(App, ICQ)
{
  // CHeck path ['ICQ']
  Event event;
  auto state = State::ICQ;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ICQ);
}

