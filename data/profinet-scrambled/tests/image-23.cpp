#include <gtest/gtest.h>
struct Event{};
enum class State
{
  PDF,
  CRT,
};
State handle_event(State const state, Event const & evnet);

TEST(App, CRT)
{
  // CHeck path ['CRT']
  Event event;
  auto state = State::CRT;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CRT);
}

