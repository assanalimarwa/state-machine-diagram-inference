#include <gtest/gtest.h>
struct Event{};
enum class State
{
  GUI,
  AIX,
  YML,
};
State handle_event(State const state, Event const & evnet);

TEST(App, YML)
{
  // CHeck path ['YML']
  Event event;
  auto state = State::YML;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
}

