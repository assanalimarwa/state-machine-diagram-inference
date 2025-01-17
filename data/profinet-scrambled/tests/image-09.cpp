#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SSH,
  DVR,
  IOS,
  ACL,
  IPV,
  API,
};
State handle_event(State const state, Event const & evnet);

TEST(App, IPV)
{
  // CHeck path ['IPV']
  Event event;
  auto state = State::IPV;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPV);
}

