#include <gtest/gtest.h>
struct Event{};
enum class State
{
  GUI,
  DNS,
  NAT,
  DAC,
};
State handle_event(State const state, Event const & evnet);

TEST(App, NAT)
{
  // CHeck path ['NAT']
  Event event;
  auto state = State::NAT;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NAT);
}

