#include <gtest/gtest.h>
struct Event{};
enum class State
{
  XSS,
  DNS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DNS)
{
  // CHeck path ['DNS']
  Event event;
  auto state = State::DNS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
}

