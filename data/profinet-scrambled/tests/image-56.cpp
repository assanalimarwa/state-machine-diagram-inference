#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SDK,
  AIX,
  IOT,
  ASP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, ASP)
{
  // CHeck path ['ASP']
  Event event;
  auto state = State::ASP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
}

TEST(App, AIX)
{
  // CHeck path ['ASP', 'AIX', 'ASP']
  Event event;
  auto state = State::ASP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
}

TEST(App, SDK)
{
  // CHeck path ['ASP', 'AIX', 'SDK', 'ASP']
  Event event;
  auto state = State::ASP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
}

TEST(App, IOT)
{
  // CHeck path ['ASP', 'AIX', 'SDK', 'IOT', 'ASP']
  Event event;
  auto state = State::ASP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
}

