#include <gtest/gtest.h>
struct Event{};
enum class State
{
  PDF,
  DNS,
  DAC,
};
State handle_event(State const state, Event const & evnet);

TEST(App, PDF)
{
  // CHeck path ['PDF']
  Event event;
  auto state = State::PDF;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PDF);
}

