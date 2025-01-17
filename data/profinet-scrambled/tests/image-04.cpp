#include <gtest/gtest.h>
struct Event{};
enum class State
{
  CSS,
  IOT,
};
State handle_event(State const state, Event const & evnet);

TEST(App, CSS)
{
  // CHeck path ['CSS']
  Event event;
  auto state = State::CSS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSS);
}

TEST(App, IOT)
{
  // CHeck path ['CSS', 'IOT', 'CSS']
  Event event;
  auto state = State::CSS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSS);
}

