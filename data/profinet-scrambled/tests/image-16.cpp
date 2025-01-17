#include <gtest/gtest.h>
struct Event{};
enum class State
{
  PHP,
  RAM,
  IVR,
  AIK,
};
State handle_event(State const state, Event const & evnet);

TEST(App, PHP)
{
  // CHeck path ['PHP']
  Event event;
  auto state = State::PHP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
}

TEST(App, AIK)
{
  // CHeck path ['PHP', 'AIK', 'PHP']
  Event event;
  auto state = State::PHP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
}

TEST(App, RAM)
{
  // CHeck path ['PHP', 'AIK', 'RAM', 'PHP']
  Event event;
  auto state = State::PHP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
}

TEST(App, IVR)
{
  // CHeck path ['PHP', 'AIK', 'IVR', 'PHP']
  Event event;
  auto state = State::PHP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
}

