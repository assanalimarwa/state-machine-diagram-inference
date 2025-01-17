#include <gtest/gtest.h>
struct Event{};
enum class State
{
  MLB,
  MAC,
  IIS,
  YML,
};
State handle_event(State const state, Event const & evnet);

TEST(App, MLB)
{
  // CHeck path ['MLB']
  Event event;
  auto state = State::MLB;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
}

TEST(App, YML)
{
  // CHeck path ['MLB', 'YML', 'MLB']
  Event event;
  auto state = State::MLB;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
}

TEST(App, IIS)
{
  // CHeck path ['MLB', 'YML', 'IIS', 'MLB']
  Event event;
  auto state = State::MLB;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IIS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
}

TEST(App, MAC)
{
  // CHeck path ['MLB', 'YML', 'IIS', 'MAC', 'MLB']
  Event event;
  auto state = State::MLB;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IIS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MLB);
}

