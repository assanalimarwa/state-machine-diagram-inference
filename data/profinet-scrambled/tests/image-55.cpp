#include <gtest/gtest.h>
struct Event{};
enum class State
{
  VMX,
  VPN,
  MIM,
  CPU,
  BIOS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, VPN)
{
  // CHeck path ['VPN']
  Event event;
  auto state = State::VPN;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
}

TEST(App, BIOS)
{
  // CHeck path ['VPN', 'BIOS', 'VPN']
  Event event;
  auto state = State::VPN;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
}

TEST(App, CPU)
{
  // CHeck path ['VPN', 'BIOS', 'CPU', 'VPN']
  Event event;
  auto state = State::VPN;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
}

TEST(App, VMX)
{
  // CHeck path ['VPN', 'BIOS', 'CPU', 'VMX', 'VPN']
  Event event;
  auto state = State::VPN;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VMX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
}

TEST(App, MIM)
{
  // CHeck path ['VPN', 'BIOS', 'CPU', 'MIM', 'VPN']
  Event event;
  auto state = State::VPN;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MIM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPN);
}

