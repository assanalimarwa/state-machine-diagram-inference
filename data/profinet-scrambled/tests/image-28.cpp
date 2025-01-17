#include <gtest/gtest.h>
struct Event{};
enum class State
{
  EEP,
  PPT,
  IDE,
};
State handle_event(State const state, Event const & evnet);

TEST(App, EEP)
{
  // CHeck path ['EEP']
  Event event;
  auto state = State::EEP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EEP);
}

