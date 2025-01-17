#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SDK,
  IPX,
  SSD,
};
State handle_event(State const state, Event const & evnet);

TEST(App, IPX)
{
  // CHeck path ['IPX']
  Event event;
  auto state = State::IPX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
}

TEST(App, SSD)
{
  // CHeck path ['IPX', 'SSD', 'IPX']
  Event event;
  auto state = State::IPX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
}

TEST(App, SDK)
{
  // CHeck path ['IPX', 'SSD', 'SDK', 'IPX']
  Event event;
  auto state = State::IPX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
}

