#include <gtest/gtest.h>
struct Event{};
enum class State
{
  OSX,
  TLD,
  RDS,
  DNS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, RDS)
{
  // CHeck path ['RDS']
  Event event;
  auto state = State::RDS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
}

TEST(App, TLD)
{
  // CHeck path ['RDS', 'TLD', 'RDS']
  Event event;
  auto state = State::RDS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
}

TEST(App, DNS)
{
  // CHeck path ['RDS', 'TLD', 'DNS', 'RDS']
  Event event;
  auto state = State::RDS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
}

TEST(App, OSX)
{
  // CHeck path ['RDS', 'TLD', 'DNS', 'OSX', 'RDS']
  Event event;
  auto state = State::RDS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::OSX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
}

