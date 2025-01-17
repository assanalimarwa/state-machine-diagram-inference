#include <gtest/gtest.h>
struct Event{};
enum class State
{
  PNG,
  TCP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, TCP)
{
  // CHeck path ['TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

TEST(App, PNG)
{
  // CHeck path ['TCP', 'PNG', 'TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PNG);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

