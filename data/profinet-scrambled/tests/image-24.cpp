#include <gtest/gtest.h>
struct Event{};
enum class State
{
  CSS,
  HDD,
};
State handle_event(State const state, Event const & evnet);

TEST(App, CSS)
{
  // CHeck path ['CSS']
  Event event;
  auto state = State::CSS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSS);
}

