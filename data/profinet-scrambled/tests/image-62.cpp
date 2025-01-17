#include <gtest/gtest.h>
struct Event{};
enum class State
{
  CSV,
  DRM,
  YML,
};
State handle_event(State const state, Event const & evnet);

TEST(App, YML)
{
  // CHeck path ['YML']
  Event event;
  auto state = State::YML;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
}

TEST(App, CSV)
{
  // CHeck path ['YML', 'CSV', 'YML']
  Event event;
  auto state = State::YML;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
}

TEST(App, DRM)
{
  // CHeck path ['YML', 'CSV', 'DRM', 'YML']
  Event event;
  auto state = State::YML;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DRM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
}

