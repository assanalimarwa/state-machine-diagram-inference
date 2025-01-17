#include <gtest/gtest.h>
struct Event{};
enum class State
{
  RDP,
  USB,
  CMS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, RDP)
{
  // CHeck path ['RDP']
  Event event;
  auto state = State::RDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDP);
}

