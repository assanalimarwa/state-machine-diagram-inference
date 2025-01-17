#include <gtest/gtest.h>
struct Event{};
enum class State
{
  ERP,
  KVM,
  SQL,
};
State handle_event(State const state, Event const & evnet);

TEST(App, KVM)
{
  // CHeck path ['KVM']
  Event event;
  auto state = State::KVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::KVM);
}

TEST(App, SQL)
{
  // CHeck path ['KVM', 'SQL', 'KVM']
  Event event;
  auto state = State::KVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::KVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::KVM);
}

TEST(App, ERP)
{
  // CHeck path ['KVM', 'SQL', 'ERP', 'KVM']
  Event event;
  auto state = State::KVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::KVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::KVM);
}

