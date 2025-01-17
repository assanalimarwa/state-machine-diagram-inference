#include <gtest/gtest.h>
struct Event{};
enum class State
{
  JVM,
  SAS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SAS)
{
  // CHeck path ['SAS']
  Event event;
  auto state = State::SAS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SAS);
}

TEST(App, JVM)
{
  // CHeck path ['SAS', 'JVM', 'SAS']
  Event event;
  auto state = State::SAS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SAS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SAS);
}

