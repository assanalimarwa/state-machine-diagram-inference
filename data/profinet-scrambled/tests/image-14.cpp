#include <gtest/gtest.h>
struct Event{};
enum class State
{
  XML,
  WAF,
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

TEST(App, XML)
{
  // CHeck path ['CSV', 'XML', 'CSV']
  Event event;
  auto state = State::CSV;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
}

TEST(App, WAF)
{
  // CHeck path ['CSV', 'XML', 'WAF', 'CSV']
  Event event;
  auto state = State::CSV;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WAF);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
}

