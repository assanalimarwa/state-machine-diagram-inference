#include <gtest/gtest.h>
struct Event{};
enum class State
{
  GUI,
  LVM,
  IPX,
  RSA,
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

TEST(App, IPX)
{
  // CHeck path ['RSA', 'IPX', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

TEST(App, LVM)
{
  // CHeck path ['RSA', 'IPX', 'LVM', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

TEST(App, GUI)
{
  // CHeck path ['RSA', 'IPX', 'GUI', 'RSA']
  Event event;
  auto state = State::RSA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::GUI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RSA);
}

