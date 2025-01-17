#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DPI,
  SSH,
  MLB,
  PIP,
  API,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DPI)
{
  // CHeck path ['DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, MLB)
{
  // CHeck path ['DPI', 'MLB', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, SSH)
{
  // CHeck path ['DPI', 'MLB', 'SSH', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, PIP)
{
  // CHeck path ['DPI', 'MLB', 'SSH', 'PIP', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PIP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, API)
{
  // CHeck path ['DPI', 'MLB', 'SSH', 'API', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::API);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

