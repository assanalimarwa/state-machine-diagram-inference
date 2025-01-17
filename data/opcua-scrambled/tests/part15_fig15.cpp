#include <gtest/gtest.h>
struct Event{};
enum class State
{
  MIM,
  TCP,
  TLD,
};
State handle_event(State const state, Event const & evnet);

TEST(App, MIM)
{
  // CHeck path ['MIM']
  Event event;
  auto state = State::MIM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MIM);
}

