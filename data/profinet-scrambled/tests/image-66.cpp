#include <gtest/gtest.h>
struct Event{};
enum class State
{
  TLD,
  RDP,
  CPL,
  RAM,
  IVR,
};
State handle_event(State const state, Event const & evnet);

TEST(App, RAM)
{
  // CHeck path ['RAM']
  Event event;
  auto state = State::RAM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
}

TEST(App, IVR)
{
  // CHeck path ['RAM', 'IVR', 'RAM']
  Event event;
  auto state = State::RAM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
}

TEST(App, TLD)
{
  // CHeck path ['RAM', 'TLD', 'RAM']
  Event event;
  auto state = State::RAM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
}

TEST(App, CPL)
{
  // CHeck path ['RAM', 'TLD', 'CPL', 'RAM']
  Event event;
  auto state = State::RAM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
}

TEST(App, RDP)
{
  // CHeck path ['RAM', 'TLD', 'CPL', 'RDP', 'RAM']
  Event event;
  auto state = State::RAM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
}

