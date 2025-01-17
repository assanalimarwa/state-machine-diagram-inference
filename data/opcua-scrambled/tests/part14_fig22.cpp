#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SSH,
  EDI,
  HDD,
  WAF,
  BIOS,
  KV,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SSH)
{
  // CHeck path ['SSH']
  Event event;
  auto state = State::SSH;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
}

TEST(App, KV)
{
  // CHeck path ['SSH', 'KV', 'HDD', 'SSH']
  Event event;
  auto state = State::SSH;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::KV);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HDD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
}

TEST(App, BIOS)
{
  // CHeck path ['SSH', 'BIOS', 'SSH']
  Event event;
  auto state = State::SSH;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
}

TEST(App, HDD)
{
  // CHeck path ['SSH', 'BIOS', 'HDD', 'SSH']
  Event event;
  auto state = State::SSH;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HDD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSH);
}

