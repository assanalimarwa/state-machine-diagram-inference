#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SSH,
  GPU,
  PPT,
  EHR,
  IOS,
  CLI,
  CPU,
  CSS,
  NAT,
  WAP,
  IVR,
};
State handle_event(State const state, Event const & evnet);

TEST(App, IOS)
{
  // CHeck path ['IOS']
  Event event;
  auto state = State::IOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOS);
}

