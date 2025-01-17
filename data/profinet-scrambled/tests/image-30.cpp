#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DOS,
  RDS,
  ROM,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DOS)
{
  // CHeck path ['DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

