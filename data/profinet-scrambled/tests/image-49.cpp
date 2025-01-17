#include <gtest/gtest.h>
struct Event{};
enum class State
{
  MLB,
  ATM,
  OOP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, MLB)
{
  // CHeck path ['MLB']
  Event event;
  auto state = State::MLB;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
}

