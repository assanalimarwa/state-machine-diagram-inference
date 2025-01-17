#include <gtest/gtest.h>
struct Event{};
enum class State
{
  API,
};
State handle_event(State const state, Event const & evnet);

TEST(App, API)
{
  // CHeck path ['API']
  Event event;
  auto state = State::API;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::API);
}

