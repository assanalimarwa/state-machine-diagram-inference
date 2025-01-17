#include <gtest/gtest.h>
struct Event{};
enum class State
{
  TCP,
  MAC,
  SQL,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SQL)
{
  // CHeck path ['SQL']
  Event event;
  auto state = State::SQL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
}

TEST(App, MAC)
{
  // CHeck path ['SQL', 'MAC', 'TCP', 'SQL']
  Event event;
  auto state = State::SQL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
}

TEST(App, TCP)
{
  // CHeck path ['SQL', 'MAC', 'TCP', 'SQL']
  Event event;
  auto state = State::SQL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
}

