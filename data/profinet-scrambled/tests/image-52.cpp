#include <gtest/gtest.h>
struct Event{};
enum class State
{
  JDK,
  HDD,
  RSA,
  CMS,
  LAN,
  CSV,
};
State handle_event(State const state, Event const & evnet);

TEST(App, RSA)
{
  // CHeck path ['RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

TEST(App, CSV)
{
  // CHeck path ['RSA', 'CSV', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

TEST(App, JDK)
{
  // CHeck path ['RSA', 'CSV', 'JDK', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

TEST(App, CMS)
{
  // CHeck path ['RSA', 'CSV', 'JDK', 'CMS', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CMS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

TEST(App, HDD)
{
  // CHeck path ['RSA', 'CSV', 'JDK', 'CMS', 'HDD', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CMS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HDD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

TEST(App, LAN)
{
  // CHeck path ['RSA', 'CSV', 'JDK', 'CMS', 'LAN', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CSV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CMS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

