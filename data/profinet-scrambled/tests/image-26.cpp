#include <gtest/gtest.h>
struct Event{};
enum class State
{
  IPV,
  CSV,
};
State handle_event(State const state, Event const & evnet);

TEST(App, CSV)
{
  // CHeck path ['CSV']
  Event event;
  auto state = State::CSV;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
}

TEST(App, IPV)
{
  // CHeck path ['CSV', 'IPV', 'CSV']
  Event event;
  auto state = State::CSV;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
}

