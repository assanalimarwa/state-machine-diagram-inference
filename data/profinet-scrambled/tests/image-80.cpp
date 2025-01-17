#include <gtest/gtest.h>
struct Event{};
enum class State
{
  IOS,
  VMX,
  VPS,
  WAP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, VMX)
{
  // CHeck path ['VMX']
  Event event;
  auto state = State::VMX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VMX);
}

