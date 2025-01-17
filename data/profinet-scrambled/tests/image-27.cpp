#include <gtest/gtest.h>
struct Event{};
enum class State
{
  RDP,
  JSON,
};
State handle_event(State const state, Event const & evnet);

TEST(App, RDP)
{
  // CHeck path ['RDP']
  Event event;
  auto state = State::RDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDP);
}

TEST(App, JSON)
{
  // CHeck path ['RDP', 'JSON', 'RDP']
  Event event;
  auto state = State::RDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JSON);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDP);
}

