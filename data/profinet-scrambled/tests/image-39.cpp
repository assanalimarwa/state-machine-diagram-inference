#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DAC,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DAC)
{
  // CHeck path ['DAC']
  Event event;
  auto state = State::DAC;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DAC);
}

