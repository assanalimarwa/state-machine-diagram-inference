#include <gtest/gtest.h>
struct Event{};
enum class State
{
  MIM,
  VNC,
  XSS,
  IDE,
};
State handle_event(State const state, Event const & evnet);

TEST(App, IDE)
{
  // CHeck path ['IDE']
  Event event;
  auto state = State::IDE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IDE);
}

TEST(App, VNC)
{
  // CHeck path ['IDE', 'VNC', 'IDE']
  Event event;
  auto state = State::IDE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IDE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VNC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IDE);
}

TEST(App, MIM)
{
  // CHeck path ['IDE', 'VNC', 'MIM', 'IDE']
  Event event;
  auto state = State::IDE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IDE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VNC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MIM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IDE);
}

TEST(App, XSS)
{
  // CHeck path ['IDE', 'VNC', 'MIM', 'XSS', 'IDE']
  Event event;
  auto state = State::IDE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IDE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VNC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MIM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IDE);
}

