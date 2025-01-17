#include <gtest/gtest.h>
struct Event{};
enum class State
{
  XML,
  GIF,
};
State handle_event(State const state, Event const & evnet);

TEST(App, XML)
{
  // CHeck path ['XML']
  Event event;
  auto state = State::XML;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XML);
}

