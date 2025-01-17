#include <gtest/gtest.h>
struct Event{};
enum class State
{
  JVM,
  RAM,
  LVM,
  DVR,
};
State handle_event(State const state, Event const & evnet);

TEST(App, LVM)
{
  // CHeck path ['LVM']
  Event event;
  auto state = State::LVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
}

TEST(App, JVM)
{
  // CHeck path ['LVM', 'JVM', 'LVM']
  Event event;
  auto state = State::LVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
}

TEST(App, DVR)
{
  // CHeck path ['LVM', 'JVM', 'DVR', 'LVM']
  Event event;
  auto state = State::LVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
}

TEST(App, RAM)
{
  // CHeck path ['LVM', 'JVM', 'DVR', 'RAM', 'LVM']
  Event event;
  auto state = State::LVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
}

