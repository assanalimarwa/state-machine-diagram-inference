#include <gtest/gtest.h>
struct Event{};
enum class State
{
  GIF,
  SSH,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SSH)
{
  // CHeck path ['SSH']
  Event event;
  auto state = State::SSH;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
}

