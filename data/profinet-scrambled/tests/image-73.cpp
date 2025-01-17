#include <gtest/gtest.h>
struct Event{};
enum class State
{
  EDI,
  CPU,
  VPS,
  MFA,
};
State handle_event(State const state, Event const & evnet);

TEST(App, EDI)
{
  // CHeck path ['EDI']
  Event event;
  auto state = State::EDI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EDI);
}

