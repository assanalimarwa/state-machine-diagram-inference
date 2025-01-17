#include <gtest/gtest.h>
struct Event{};
enum class State
{
  JSON,
  DOS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, JSON)
{
  // CHeck path ['JSON']
  Event event;
  auto state = State::JSON;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JSON);
}

TEST(App, DOS)
{
  // CHeck path ['JSON', 'DOS', 'JSON']
  Event event;
  auto state = State::JSON;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JSON);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JSON);
}

