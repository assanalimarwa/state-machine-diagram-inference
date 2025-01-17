#include <gtest/gtest.h>
struct Event{};
enum class State
{
  WWW,
  VNC,
  VPS,
  EHR,
};
State handle_event(State const state, Event const & evnet);

TEST(App, WWW)
{
  // CHeck path ['WWW']
  Event event;
  auto state = State::WWW;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WWW);
}

TEST(App, VNC)
{
  // CHeck path ['WWW', 'VNC', 'EHR', 'WWW']
  Event event;
  auto state = State::WWW;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WWW);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VNC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EHR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WWW);
}

TEST(App, VPS)
{
  // CHeck path ['WWW', 'VNC', 'VPS', 'EHR', 'WWW']
  Event event;
  auto state = State::WWW;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WWW);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VNC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EHR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WWW);
}

TEST(App, EHR)
{
  // CHeck path ['WWW', 'VNC', 'EHR', 'WWW']
  Event event;
  auto state = State::WWW;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WWW);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VNC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EHR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WWW);
}

