#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DPI,
  SSH,
  IDE,
  CLI,
  RAM,
  CRT,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DPI)
{
  // CHeck path ['DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

