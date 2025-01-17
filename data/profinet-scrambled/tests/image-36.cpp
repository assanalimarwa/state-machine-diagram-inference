#include <gtest/gtest.h>
struct Event{};
enum class State
{
  CSV,
  DVR,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DVR)
{
  // CHeck path ['DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

TEST(App, CSV)
{
  // CHeck path ['DVR', 'CSV', 'DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

