#include <gtest/gtest.h>
struct Event{};
enum class State
{
  XM,
  RA,
  MFA,
};
State handle_event(State const state, Event const & evnet);

TEST(App, MFA)
{
  // CHeck path ['MFA']
  Event event;
  auto state = State::MFA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
}

TEST(App, RA)
{
  // CHeck path ['MFA', 'RA', 'MFA']
  Event event;
  auto state = State::MFA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
}

TEST(App, XM)
{
  // CHeck path ['MFA', 'XM', 'MFA']
  Event event;
  auto state = State::MFA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
}

