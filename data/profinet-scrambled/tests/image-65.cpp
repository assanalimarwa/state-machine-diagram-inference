#include <gtest/gtest.h>
struct Event{};
enum class State
{
  NFS,
  EXE,
  USB,
};
State handle_event(State const state, Event const & evnet);

TEST(App, NFS)
{
  // CHeck path ['NFS']
  Event event;
  auto state = State::NFS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NFS);
}

TEST(App, EXE)
{
  // CHeck path ['NFS', 'EXE', 'USB', 'NFS']
  Event event;
  auto state = State::NFS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NFS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::USB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NFS);
}

TEST(App, USB)
{
  // CHeck path ['NFS', 'USB', 'NFS']
  Event event;
  auto state = State::NFS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NFS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::USB);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::NFS);
}

