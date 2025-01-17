#include <gtest/gtest.h>
struct Event{};
enum class State
{
  CPU,
  LTE,
  CRT,
};
State handle_event(State const state, Event const & evnet);

TEST(App, LTE)
{
  // CHeck path ['LTE']
  Event event;
  auto state = State::LTE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LTE);
}

TEST(App, CRT)
{
  // CHeck path ['LTE', 'CRT', 'LTE']
  Event event;
  auto state = State::LTE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LTE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CRT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LTE);
}

TEST(App, CPU)
{
  // CHeck path ['LTE', 'CRT', 'CPU', 'LTE']
  Event event;
  auto state = State::LTE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LTE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CRT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LTE);
}

