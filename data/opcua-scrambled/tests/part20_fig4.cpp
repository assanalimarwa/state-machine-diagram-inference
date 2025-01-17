#include <gtest/gtest.h>
struct Event{};
enum class State
{
  X,
  GUI,
  CSS,
  RAM,
  CP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, X)
{
  // CHeck path ['X']
  Event event;
  auto state = State::X;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
}

TEST(App, RAM)
{
  // CHeck path ['X', 'RAM', 'GUI', 'X']
  Event event;
  auto state = State::X;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::GUI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
}

TEST(App, CSS)
{
  // CHeck path ['X', 'CSS', 'X']
  Event event;
  auto state = State::X;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
}

TEST(App, CP)
{
  // CHeck path ['X', 'RAM', 'CP', 'X']
  Event event;
  auto state = State::X;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
}

TEST(App, GUI)
{
  // CHeck path ['X', 'RAM', 'GUI', 'X']
  Event event;
  auto state = State::X;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::GUI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::X);
}

