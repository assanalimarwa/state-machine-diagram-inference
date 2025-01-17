#include <gtest/gtest.h>
struct Event{};
enum class State
{
  IIS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, IIS)
{
  // CHeck path ['IIS']
  Event event;
  auto state = State::IIS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IIS);
}

